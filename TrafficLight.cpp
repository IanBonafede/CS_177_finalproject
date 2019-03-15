
#include "cpp.h"
#include <string.h>




class TrafficLight {
private:
	facility *light;
	event go;
	double goInt;
	
public:
	TrafficLight();
	run();
	
	
};

TrafficLight::TrafficLight() {
	goInt = 20; // sec
	
	light = new Facility("Light");
	go = new event("GO");
	
	run();
	
}

void TrafficLight::run() {
	create("Traffic Light");
	
	while(true) {
		//create the car
		go.set();
		// hold for interval between
		hold(goInt);
	}
	
	
}
