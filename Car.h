#ifndef CAR_H // include guard
#define CAR_H


#include "Speed.h"

using namespace std;


class Car {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit; 
	TrafficLight *trafficLight;  
	Stat *stat; 
	double length;
	Speed speed;
	double unloadTime;
	int lookAheadDistance;
	
public:
	Car(Road *ren, Road *rz, Road *rex, TrafficLight *tl);
	void run1();
	void run2();
	Speed updateSpeed(int check);
	
};

#endif /* CAR_H */

