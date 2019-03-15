#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Road.cpp"
#include "TrafficLight.cpp"
#include "Generator.cpp"

using namespace std;



extern "C" void sim() // Alice is the main process
{
	create("sim");
	
	Road *roadEntrance = new Road(10, 1);
	Road *roadZone = new Road(10, 1);
	Road *roadExit = new Road(10, 1);
	
	TrafficLight *trafficLight = new TrafficLight();
	
	Generator *gen = new Generator(roadEntrance, roadZone, roadExit, trafficLight);
	
	hold(300);// 300 sec = 5 min
	report();
}
