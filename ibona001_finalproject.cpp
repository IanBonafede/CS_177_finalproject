#include <iostream>
#include "cpp.h"
#include <string.h>
#include "Road.cpp"
#include "TrafficLight.cpp"
#include "Car.cpp"
#include "Generator.cpp"
#include "Stat.cpp"

using namespace std;



extern "C" void sim() // The main process
{
	create("sim");
	double time = 1000;
	Stat *stat = new Stat();
	
	Generator *gen = new Generator(stat);
	
	hold(time);// 1000 sec
	report();
	stat->printThroughput(time);
}
