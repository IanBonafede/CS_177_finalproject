#include "Road.h"


#include <iostream>
#include "cpp.h"
#include <string.h>
#include "math.h"

using namespace std;




Road::Road(double len, double cellLen) {
	
	
	cellLength = cellLen;
	cellNum = floor(len / cellLen); 
	road = new facility_set("Road", cellNum);
	
	
}

facility_set *Road::getRoad() {
	return road;
}

int Road::getEnd() {
	return (cellNum - 1);
}


//function: lookAhead
//return: 0-howFar is how many cells free untill the next car (up to howFar)
//return: 8-15 is how many cells till the end of the road. 10 means 0 cells. 17 means 7 cells free until the end
//examples for howFar = 8
int Road::lookAhead(int carCell, int howFar) {
	int i = 1;
	while(i <= howFar && carCell + i <= cellNum - 1) {
		if(  (*road)[carCell + i].status() == BUSY)
			return i-1; //return cells free in front of you: 1-8 => 0-7
		i++;
	}
	if(i == howFar + 1) // =? 9
		return i - 1; //return max seeing distance: 8 free spots
	else // i < 9
		return i - 1 + howFar; //return the index of end of the road in front of you. i:1-8 => -1:0-7 => +howFar:8-15
}












