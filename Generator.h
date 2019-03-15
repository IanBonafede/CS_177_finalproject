
#ifndef GENERATOR_H // include guard
#define GENERATOR_H





using namespace std;

class Generator {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit;
	TrafficLight *trafficLight;
	Stat *stat;
	double CarGenInt;
	
public:
	Generator(Stat *st);
	void generateCars();
	
	
};


#endif /* GENERATOR_H */

