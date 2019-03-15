
#include "TrafficLight.h"

TrafficLight::TrafficLight() {
	create("Traffic Light");	
	
	goInt = 20; // sec
	
	light = new facility("Light");
	go = new event("GO");
	
	run();
	
}

void TrafficLight::run() {
	
	
	while(true) {
		//create the car
		go->set();
		// hold for interval between
		hold(goInt);
	}
	
	
}
