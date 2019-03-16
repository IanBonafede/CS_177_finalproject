
#include "TrafficLight.h"


#include "cpp.h"
#include <string.h>


TrafficLight::TrafficLight() {
	create("Traffic Light");	
	
	goInt = 10; // sec
	
	light = new facility("Light");
	lights = new facility_ms("Lights", 5);
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


facility_ms *TrafficLight::getLights() {
	return lights;
}
