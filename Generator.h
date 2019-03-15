
#ifndef GENERATOR_H // include guard
#define GENERATOR_H



#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Car.h"
#include "Road.h"
#include "TrafficLight.h"


using namespace std;

class Generator {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit;
	TrafficLight *trafficLight;
	double CarGenInt;
	
public:
	Generator();
	void generateCars();
	
	
};


#endif /* GENERATOR_H */

