//Author: Ace
//Course: CSCI-135
//Instructor: Genady Maryash
//Assignment: Project 3

//This program makes our debris-clearing robots smarter

#include <cstdlib>
#include <iostream>
#include <vector>
#include "bot.h"

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

vector<int> malf;

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	

	log << "Start!" << endl;
}



Action radar(int row, int col, Area &area){
	//check for debris on an increasing radius
	int x = 2;
	while(x < ROWS){
		if(area.inspect(row, col + x) == DEBRIS){//move right towards debris
			return RIGHT;
		
		}else if(area.inspect(row, col - x) == DEBRIS){//move left towards debris
			return LEFT;
		
		}else if(area.inspect(row + x, col) == DEBRIS){//move down towards debris
			return DOWN;
			
		}else if(area.inspect(row - x, col) == DEBRIS){//move up towards debris
			return UP;
		
		}else if(area.inspect(row - x, col + x) == DEBRIS){//check upper right
			return RIGHT;
			
		}else if(area.inspect(row + x, col + x) == DEBRIS){//check lower right
			return DOWN;
		
		}else if(area.inspect(row + x, col - x) == DEBRIS){//check lower left
			return LEFT;
		
		}else if(area.inspect(row - x, col - x) == DEBRIS){//check upper left
			return UP;
		
		}
		x++;	
	}	
	
	//on the off chance that there is no debris on an 'x' by 'x' grid around the bot, move randomly
	switch(rand() % 4) {
		case 0:
			return LEFT;
		case 1:
			return RIGHT;
		case 2:
			return UP;
		default:
			return DOWN;
	}
}


/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	int row = loc.r; // current row and column
	int col = loc.c;
	//check for nearby malfunctioning robots
	for(int i = 0; i < malf.size(); i++){
		int br = area.locate(malf[i]).r;
		int bc = area.locate(malf[i]).c;
		//if the robot is near any broken robots, the broken robot's id will be removed from malf
		//and the proper action will be returned
		if(row == br && col + 1 == bc){
			log << "Robot " << malf[i] << " repaired." << endl;
			int last = malf[malf.size() - 1];
			malf[i] = last;
			malf.pop_back();
			return REPAIR_RIGHT;
		}else if(row == br && col - 1 == bc){
			log << "Robot " << malf[i] << " repaired." << endl;
			int last = malf[malf.size() - 1];
			malf[i] = last;
			malf.pop_back();
			return REPAIR_LEFT;
		}else if(row + 1 == br && col == bc){
			log << "Robot " << malf[i] << " repaired." << endl;
			int last = malf[malf.size() - 1];
			malf[i] = last;
			malf.pop_back();
			return REPAIR_DOWN;	
		}else if(row - 1 == br && col == bc){
			log << "Robot " << malf[i] << " repaired." << endl;
			int last = malf[malf.size() - 1];
			malf[i] = last;
			malf.pop_back();
			return REPAIR_UP;	
		}
	}
	
	if (area.inspect(row, col) == DEBRIS){
		return COLLECT;
		
	}else if(area.inspect(row, col + 1) == DEBRIS){//move right towards debris
		return RIGHT;
		
	}else if(area.inspect(row, col - 1) == DEBRIS){//move left towards debris
		return LEFT;
		
	}else if(area.inspect(row + 1, col) == DEBRIS){//move down towards debris
		return DOWN;
			
	}else if(area.inspect(row - 1, col) == DEBRIS){//move up towards debris
		return UP;
		
	}else if(area.inspect(row - 1, col + 1) == DEBRIS){//check upper right
		return RIGHT;
			
	}else if(area.inspect(row + 1, col + 1) == DEBRIS){//check lower right
		return DOWN;
		
	}else if(area.inspect(row + 1, col - 1) == DEBRIS){//check lower left
		return LEFT;
		
	}else if(area.inspect(row - 1, col - 1) == DEBRIS){//check upper left
		return UP;	
	}
	
	for(int i = 0; i < NUM; i++){//check for neighboring robots and move away from them
		int c = area.locate(i).c;
		int r = area.locate(i).r;
		if(i != id){
			if(row == r && col + 1 == c){
				return LEFT;	
			}else if(row == r && col - 1 == c){
				return RIGHT;	
			}else if(row + 1 == r && col == c){
				return UP;	
			}else if(row - 1 == r && col == c){
				return DOWN;	
			}
		}	
	}
	return radar(row, col, area);
	
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
	malf.push_back(id);
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}


