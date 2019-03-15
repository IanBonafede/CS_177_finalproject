#ifndef CAR_H // include guard
#define CAR_H


#include "cpp.h"
#include <string.h>
#include "Road.h"
#include "TrafficLight.h"

using namespace std;

enum Speed 
{ 
	
	SPEED0 = 0,
	SPEED1 = (3 / 2),
	SPEED2 = (11 / 12),
	SPEED3 = (1 / 2),
	SPEED4 = (1 / 3),
	SPEED5 = (1 / 4)
	
} Speed;// in cells per second

class Car {
private:
	Road *roadEntrance;
	Road *roadZone;
	Road *roadExit; 
	TrafficLight *trafficLight;   
	double length;
	Speed speed;
	double unloadTime;
	int lookAheadDistance;
	
public:
	Car(Road *ren, Road *rz, Road *rex, TrafficLight *tl);
	void run();
	Speed updateSpeed(int check);
	
};

#endif /* CAR_H */

