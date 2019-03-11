#include <iostream>
#include "cpp.h"
#include <string.h>




class Car {
private:
	faciltiy    *stopLight;
	facilitySet *roadEntrance;
	facilitySet *roadZone;
	facilitySet *roadExit;    
	double length;
	
public:
	Car();
	
	
};

Car::Car( facility *sl, facilitySet *ren, facilitySet *rz, facilitySet *rex) {
	stopLight = sl;
	roadEntrance = ren;
	roadZone = rz;
	roadExit = rex;
	
	create("Car");
	
}

