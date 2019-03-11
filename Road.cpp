#include <iostream>
#include "cpp.h"
#include <string.h>

using namespace std;





class Road {
private:
	facilitySet *road;
	double cellLength;
	
public:
	Road(double len, double cellLen);
	getRoad();
	
};

Road::Road(double len, double cellLen) {
	
	cellLength = cellLen;
	int cellNum = floor(len / cellLen); 
	road = new facilitySet("Road", cellNum);
	
	
}

facilitySet *Road::getRoad() {
	return road;
}

