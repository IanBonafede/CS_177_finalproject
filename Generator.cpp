
#include "Generator.h"

#include <iostream>
#include "cpp.h"
#include <string.h>



Generator::Generator() {
	
	
	roadEntrance = new Road(10, 1);
	roadZone = new Road(10, 1);
	roadExit = new Road(10, 1);
	
	trafficLight = new TrafficLight();
	CarGenInt = 25; // sec
	
	
	
	generateCars();
	
}

void Generator::generateCars() {
	create("Car Generator");
	while(true) {
		//create the car
		Car car(roadEntrance, roadZone, roadExit, trafficLight);
		// hold for interval between cars
		hold(CarGenInt);
	}
	
	
}
