/*
Author: Leonardo Matone
Course: CSCI-135
Instructor: Katherine Howitt

Assignment: Project 3

bot.cpp 
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "bot.h"

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

// static Action lastAction;

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	log << "Start!" << endl;
}

//Needs to return the address of the nearest debris
Action scan(int row, int col, Area &area, int id)
{
	//establishing our current location
	// Loc currentBot = {row, col}; 
	// int halfRows = ROWS / 2;
	// int halfCols = COLS / 2;

	int radius = 1;
	if ((area.inspect(row+radius, col) == DEBRIS) && (row+radius <= ROWS)){
		return DOWN;
	}
	if ((area.inspect(row-radius, col) == DEBRIS) && (row-radius >= 0)){
		return UP;
	}
	if ((area.inspect(row, col+radius) == DEBRIS) && (col+radius <= COLS)){
		return RIGHT;
	}
	if ((area.inspect(row, col-radius) == DEBRIS) && (col-radius >= 0)){
		return LEFT;
	}
	else{
		while (radius < ROWS)
		{
			// rows from the range of -radius to +radius,
			for (int rowTest = (-radius); rowTest < radius; rowTest++){
				//cols from the range of -radius to +radius
				for (int colTest = (-radius); rowTest < radius; rowTest++){
					//if the region in question (robot Loc + the row and column within the range) is
					//debris, test the values of rowTest and colTest to determine which direction to
					//return.
					int testCol = col + colTest;
					int testRow = row + rowTest;
					if (((testCol < 0) || (testRow < 0)) || ((testCol > ROWS) || (testRow > COLS))){
						break;
					}
					else if (area.inspect(testRow, testCol) == DEBRIS)
					{
						//debris location
						// Loc debris = {row+rowTest, col+colTest};
						if (rowTest > row){
							return DOWN;
						}
						else if (rowTest < row){
							return UP;
						}
						if (colTest > col){
							return RIGHT;
						}
						else if (colTest < col){
							return LEFT;
						}
					}
				}
			}
			radius++;
		}
	}
	switch(rand() % 4) {
	case 0: return LEFT;
	case 1: return RIGHT;
	case 2: return UP;
	default: return DOWN;
	}
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) 
{
	int row = loc.r; // current row and column
	int col = loc.c;
	// int decision;

	// if debris, collect
	if (area.inspect(row, col) == DEBRIS)
		return COLLECT;

	// else, test for nearby robots, search for nearby debris with scan(), 
	else 
	{
		Loc currentBot = area.locate(id); //establishes the location of the current bot under the variable currentBot
		Loc * locations = new Loc[NUM]; //establishes an array of locations for each robot

		//scans the region around the robot with radius 1 to test for other robots
		for (int i = 0; i < NUM; i++)
		{
			locations[i] = area.locate(i);
				//if the location around the robot with radius 1 is occupied by another robot (robot i), return opposite positional arguments.
			if ((locations[i].r == currentBot.r + 1) && (locations[i].c == currentBot.c + 1)){
				return LEFT;
			}
			else if ((locations[i].r == currentBot.r + 1) && (locations[i].c == currentBot.c)){
				//if this robot is damaged, repair. Else go up.
				return UP;
			}
			else if ((locations[i].r == currentBot.r) && (locations[i].c == currentBot.c + 1)){
				return LEFT;
			}
			else if ((locations[i].r == currentBot.r - 1) && (locations[i].c == currentBot.c -1)){
				return DOWN;
			}
			else if ((locations[i].r == currentBot.r - 1) && (locations[i].c == currentBot.c)){
				return DOWN;
			}
			else if ((locations[i].r == currentBot.r) && (locations[i].c == currentBot.c - 1)){
				return RIGHT;//beepbeepboop
			}
			else if ((locations[i].r == currentBot.r + 1) && (locations[i].c == currentBot.c - 1)){
				return UP;
			}
			else if ((locations[i].r == currentBot.r - 1) && (locations[i].c == currentBot.c + 1)){
				return LEFT;
			}
			else if (i == NUM - 1){
				break;
			}
		}
	
		//if there's no other robot, run action.
		Action action = scan(row, col, area, id);
		
		//if the action is the same as the last action, return the opposite action.
		// if (action == lastAction)
		// {
		// 	if (action == LEFT){
		// 		return RIGHT;
		// 	}
		// 	else if (action == RIGHT){
		// 		return LEFT;
		// 	}
		// 	else if (action == UP){
		// 		return DOWN;
		// 	}
		// 	else
		// 	{
		// 		return UP;
		// 	}
		// }
		// else {
		// 	return action;
		// }
		// lastAction = action;
		// log << "Robot: " << id << " | Action: " << (int)lastAction << endl;
		// log << "Robot: " << id << action << endl;
		return action;
	}
}

// 	   	 area: information about surrounding area
//       area.inspect(loc): returns whether location is DEBRIS or EMPTY
//       area.locate(id):   returns location of the robot with specified ID

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;

	// Loc brokenBot = area.locate(id); //establishes the location of the broken bot under the variable brokenBot
	// Loc * locations = new Loc[NUM]; //establishes an array of locations for each robot

	// int rowDist = 0, colDist = 0;
	// int rowsFrom, colsFrom;
	// int  closestBot;
	// for (int i = 0; i < NUM; i++)
	// {
	// 	rowsFrom = abs(brokenBot.r - locations[i].r);
	// 	colsFrom = abs(brokenBot.c - locations[i].c);
	// 	if ((rowsFrom > rowDist) || (colsFrom > colDist))
	// 	{
	// 		rowDist = rowsFrom;
	// 		colDist = colsFrom;
	// 		closestBot = i;
	// 	}
	// }
	// Action response = onRobotAction(closestBot, loc, area, log);

}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}
