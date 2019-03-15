
#include "TrafficLight.h"


#include "cpp.h"
#include <string.h>


TrafficLight::TrafficLight() {
	create("Traffic Light");	
	
	goInt = 1; // sec
	
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

event *TrafficLight::getGoEvent() {
	return go;
}


facility *TrafficLight::getLight() {
	return light;
}
