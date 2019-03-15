
#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Car.cpp"
#include "Road.cpp"
#include "TrafficLight.cpp"





class Generator {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit;
	TrafficLight *trafficLight;
	double CarGenInt;
	
public:
	Generator();
	generateCars();
	
	
};

Generator::Generator(Road *ren, Road *rz, Road *rex, TrafficLight *tl) {
	
	
	roadEntrance = new Road(10, 1);
	roadZone = new Road(10, 1);
	roadExit = new Road(10, 1);
	
	trafficLight = new TrafficLight();
	CarGenInt = 30; // sec
	
	
	
	generateCars();
	
}

void Generator::generateCars() {
	create("Car Generator");
	while(true) {
		//create the car
		Car car = new Car(roadEntrance, roadZone, roadExit, trafficLight);
		// hold for interval between cars
		hold(CarGenInt);
	}
	
	
}
