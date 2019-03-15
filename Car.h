#ifndef CAR_H // include guard
#define CAR_H


#include "cpp.h"
#include <string.h>
#include "Road.h"
#include "TrafficLight.h"
#include "Speed.h"

using namespace std;


class Car {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit; 
	TrafficLight *trafficLight;   
	double length;
	Speeds speed;
	double unloadTime;
	int lookAheadDistance;
	
public:
	Car(Road *ren, Road *rz, Road *rex, TrafficLight *tl);
	void run();
	Speeds updateSpeed(int check);
	
};

#endif /* CAR_H */

