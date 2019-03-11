
#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Car.cpp"




class TrafficLight {
private:
	facilitySet *roadEntrance;
	facilitySet *roadZone;
	facilitySet *roadExit;
	facility *stopLight;
	double CarGenInt;
	
public:
	TrafficLight();
	getStopLight();
	
	
};

TrafficLight::TrafficLight(facilitySet *ren, facilitySet *rz, facilitySet *rex) {
	roadEntrance = ren;
	roadZone = rz;
	roadExit = rex;
	stopLight = new facility("STOP LIGHT");
	CarGenInt = 30;
	
	create("Traffic Light");
	
	generateCars(stopLight, ren, rz, rex);
	
}

void TrafficLight::generateCars(facility *sl, facilitySet *ren, facilitySet *rz, facilitySet *rex) {
	while(true) {
		//create the car
		Car car = new Car(sl, ren, rz, rex);
		// hold for interval between cars
		hold(CarGenInt);
	}
	
	
}

facility *getStopLight() {
	return stopLight;
}
