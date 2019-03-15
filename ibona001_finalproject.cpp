#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Road.cpp"
#include "TrafficLight.cpp"
#include "Car.cpp"
#include "Generator.cpp"


using namespace std;



extern "C" void sim() // Alice is the main process
{
	create("sim");
	
	
	Generator *gen = new Generator();
	
	hold(1000);// 1000 sec
	report();
}
