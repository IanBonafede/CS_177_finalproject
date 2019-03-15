
#include "cpp.h"
#include <string.h>




class TrafficLight {
private:
	facility *light;
	event *go;
	double goInt;
	
public:
	TrafficLight();
	void run();
	
	
};

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
		go.set();
		// hold for interval between
		hold(goInt);
	}
	
	
}
