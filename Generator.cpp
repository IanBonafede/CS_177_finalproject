
#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Generator.h"
#include "Car.h"
#include "Road.h"
#include "TrafficLight.h"




Generator::Generator() {
	
	
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
