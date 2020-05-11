		// find the location by scanning
		Loc debrisAddress = scan(row, col, area);
		// make the row distance = to the debrisDistance location plus the current location
		int rowDist = debrisAddress.r - row + 1; // if positive, we want to go up, else down
		int colDist = debrisAddress.c - col + 1; // if positive, we want to go right, else left

		log << "Robot: " << id << " RowDist: " << rowDist << " | ColDist: " << colDist << endl;

		// if the row and column is positive
			// and the row distance is greater than or equal to the column distance
		if ((rowDist > 0) && (colDist > 0) && (rowDist >= colDist)) { return UP;}
			// and the row distance is less than the column distance
		else if ((rowDist > 0) && (colDist > 0) && (rowDist < colDist)) { return RIGHT;}

		// if the row is positive and the column is negative
			// and the row distance is greater than or equal to the column distance
		else if ((rowDist > 0) && (colDist < 0) && (rowDist >= abs(colDist))) { return UP;}
			// and the row distance is less than the column distance
		else if ((rowDist > 0) && (colDist < 0) && (rowDist < abs(colDist))) { return LEFT;}

		// if the row is negative and the column is positive
			// and the row distance is greater than or equal to the column distance
		else if ((rowDist < 0) && (colDist > 0) && (abs(rowDist) >= colDist)) { return DOWN;}
		else if ((rowDist < 0) && (colDist > 0) && (abs(rowDist) < colDist)) { return RIGHT;}
			// and the row distance is less than the column distance

		// if the row and column is negative
			// and the row distance is greater than or equal to the column distance
		else if ((rowDist < 0) && (colDist < 0) && (abs(rowDist) >= abs(colDist))) { return DOWN;}
			// and the row distance is less than the column distance
		else if ((rowDist < 0) && (colDist < 0) && (abs(rowDist) < abs(colDist))) { return LEFT;}


		
//Needs to return the address of the nearest debris
Loc scan(int row, int col, Area &area)
{
	Loc debris;
	int a = 0;
	while (a < 10)
	{
		for (int i = row - a; i < row + a+1; i++)
		{
			for(int j = col - a; j < col + a+1; j++)
			{
				Place test = area.inspect(i, j);
				debris.r = i;
				debris.c = j;
				if (test == DEBRIS)
				{
					return debris;
				}
				else{continue;}
			}
		}
		a++;
	}
	Loc currentLoc;
	currentLoc.r = row;
	currentLoc.c = col;
	return currentLoc;	
}

//Needs to return the address of the nearest debris
Action scan(int row, int col, Area &area, int id)
{
	// int direction = 5;
	int radius = 1;
	while (radius < ROWS)
	{
		for (int a = 0; a < radius; a++)
		{
			if (intervalScan < 3)
			{
				return lastAction;
				intervalScan++;
			}
			else
			{
				intervalScan = 0;
				if (area.inspect(row + a, col +a) == DEBRIS) {
					return RIGHT;
					// intervalScan++;
					lastAction = RIGHT;
					// direction = 1;
				}
				else if (area.inspect(row + a, col) == DEBRIS) {
					return DOWN;
					// intervalScan++;
					lastAction = DOWN;
					// direction = 3
				}
				else if (area.inspect(row + a, col - a) == DEBRIS) {
					return DOWN;
					// intervalScan++;
					lastAction = DOWN;
					// direction = 3;
				}
				else if (area.inspect(row, col - a) == DEBRIS) {
					return LEFT;
					// intervalScan++;
					lastAction = LEFT;
					// direction = 0;
				}
				else if (area.inspect(row - a, col - a) == DEBRIS) {
					return LEFT;
					// intervalScan++;
					lastAction = LEFT;
					// direction = 0;
				}
				else if (area.inspect(row - a, col) == DEBRIS) {
					return UP;
					// intervalScan++;
					lastAction = UP;
					// direction = 2;
				}
				else if (area.inspect(row - a, col + a) == DEBRIS) {
					return UP;
					// intervalScan++;
					lastAction = UP;
					// direction = 2;
				}
				else if (area.inspect(row, col + a) == DEBRIS) {
					return RIGHT;
					lastAction = RIGHT;
					// intervalScan++;
				}
			}		
		}
		radius++;
	}
	return UP;
}



//Needs to return the address of the nearest debris
Action scan(int row, int col, Area &area, int id)
{
	// int direction = 5;
	int radius = 1;
	while (radius < ROWS)
	{
		for (int a = 0; a < radius; a++)
		{
			if (area.inspect(row + a, col +a) == DEBRIS) {
				// if (lastAction != LEFT){
				// 	return RIGHT;
				// 	lastAction = RIGHT;
				// }
				// else { return lastAction;}
				return RIGHT;
			}
			else if (area.inspect(row + a, col) == DEBRIS) {
				// if (lastAction != UP){
				// 	return DOWN;
				// 	lastAction = DOWN;
				// }
				// else { return lastAction;}
				return DOWN;
			}
			else if (area.inspect(row + a, col - a) == DEBRIS) {
				// if (lastAction != UP){
				// 	return DOWN;
				// 	lastAction = DOWN;
				// }
				// else { return lastAction;}
				return DOWN;
			}
			else if (area.inspect(row, col - a) == DEBRIS) {
				// if (lastAction != RIGHT){
				// 	return LEFT;
				// 	lastAction = LEFT;
				// }
				// else { return lastAction;}
				return LEFT;
			}
			else if (area.inspect(row - a, col - a) == DEBRIS) {
				// if (lastAction != RIGHT){
				// 	return LEFT;
				// 	lastAction = LEFT;
				// }
				// else { return lastAction;}
				return LEFT;
			}
			else if (area.inspect(row - a, col) == DEBRIS) {
				// if (lastAction != DOWN){
				// 	return UP;
				// 	lastAction = UP;
				// }
				// else { return lastAction;}
				return UP;
			}
			else if (area.inspect(row - a, col + a) == DEBRIS) {
				// if (lastAction != DOWN){
				// 	return UP;
				// 	lastAction = UP;
				// }
				// else { return lastAction;}
				return UP;
			}
			else if (area.inspect(row, col + a) == DEBRIS) {
				// if (lastAction != LEFT){
				// 	return RIGHT;
				// 	lastAction = RIGHT;
				// }
				// else { return lastAction;}
				return RIGHT;
			}		
		}
		radius++;
	}
	return UP;
}