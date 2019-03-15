#include "Car.h"



#include "cpp.h"
#include <string.h>
#include <math.h>



Car::Car(Road *ren, Road *rz, Road *rex, TrafficLight *tl) {
	create("Car");
	
	roadEntrance = ren;
	roadZone = rz;
	roadExit = rex;
	trafficLight = tl;
	length = 2; // cells (unused)
	lookAheadDistance = 8; // cells
	speed = SPEED0;
	unloadTime = 15; // sec
	
	
	run1();
	
	
}

void Car::run1() {
	
	
	//-----------------traffic light------------------------
	
	trafficLight->getLight()->reserve();
	cout << "At traffic light." << endl;
	trafficLight->getGoEvent()->wait();
	



	
	//------------------road entrace------------------------
	//------------------------------------------------------
	int check = -1;
	int front = -1; // index of front of car
	int tail = -2; // index of back of car
	while( front < roadEntrance->getEnd() ) { // while index of the front of the car is < index of the end
		check = roadEntrance->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance + roadZone->lookAhead(-1, lookAheadDistance - (check - lookAheadDistance)); // look ahead to dropoff zone
			speed = updateSpeed(check);
		}
		if(speed != SPEED0) {
			( * roadEntrance->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail >= 0) 
				( * roadEntrance->getRoad() )[tail].release();
			if(tail == -1) {
				trafficLight->getLight()->release();
				cout << "Leaving traffic light." << endl;
			}
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we have a speed, front is at the last cell, tail is the second to last cell
	
	




	//------------------road zone------------------------
	//---------------------------------------------------
	front = -1; // index of front of car
	tail = -2; // index of back of car
	while(tail < 0 || (speed != SPEED0 && front < roadZone->getEnd()) ) { // while index of the front of the car is < index of the end
		check = roadZone->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance;
			speed = updateSpeed(check); // we want to slow down before we stop at the end of the drop off zone
		}
		if(speed != SPEED0) {
			( * roadZone->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail < 0) 
				( * roadEntrance->getRoad() )[roadEntrance->getEnd() + 1 + tail].release(); // tail could be in entrance
			if(tail >= 0) 
				( * roadZone->getRoad() )[tail].release(); // tail is in zone
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
		
	}// here we are stopped somewhere in the drop off zone
	cout << "Stopped. Front: " << front << " Unloading..." << endl;
	speed = SPEED0;
	hold(abs((int)normal(unloadTime, 3.5)));
	cout << "...Done. Front: " << front << " Departing." << endl;
	
	while( front < roadZone->getEnd() ) { // while index of the front of the car is < index of the end
		check = roadZone->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance + roadExit->lookAhead(-1, lookAheadDistance - (check - lookAheadDistance)); // look ahead to exit
			speed = updateSpeed(check);
		}
		if(speed != SPEED0) {
			( * roadZone->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail >= 0) 
				( * roadZone->getRoad() )[tail].release();
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we have a speed, front is at the last cell, tail is the second to last cell
	
	
	
	
	
	
	
	
	
	//------------------road exit------------------------
	//---------------------------------------------------
	front = -1; // index of front of car
	tail = -2; // index of back of car
	while( front < roadExit->getEnd() + 2) { // while index of the tail of the car is <= index of the end
		check = roadExit->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = lookAheadDistance;
			speed = updateSpeed(check); // we do not want to slow down at the end 
		}
		if(speed != SPEED0) {
			if(front < roadExit->getEnd()) // front will leave the end
				( * roadExit->getRoad() )[front+1].reserve(); 
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail < 0) 
				( * roadZone->getRoad() )[roadZone->getEnd() + 1 + tail].release(); // tail could be in zone
			if(tail >= 0 && tail <= roadExit->getEnd()) {
				( * roadExit->getRoad() )[tail].release(); // tail is in zone
			}
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we are gone 
	cout << "Gone" << endl;
	
}













void Car::run2() {
	
	
	//-----------------traffic light------------------------
	
	trafficLight->getLight()->reserve();
	cout << "At traffic light." << endl;
	trafficLight->getGoEvent()->wait();
	

	

	
	//------------------road entrace------------------------
	//------------------------------------------------------
	
	int zoneEnd = roadZone->getEnd();
	
	int check = -1;
	int front = -1; // index of front of car
	int tail = front - zoneEnd; // index of back of car
	while( front < roadEntrance->getEnd() ) { // while index of the front of the car is < index of the end
		check = roadEntrance->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance + roadZone->lookAhead(-1, lookAheadDistance - (check - lookAheadDistance)); // look ahead to dropoff zone
			speed = updateSpeed(check);
		}
		if(speed != SPEED0) {
			( * roadEntrance->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail >= 0) 
				( * roadEntrance->getRoad() )[tail].release();
			if(tail == -1) {
				trafficLight->getLight()->release();
				cout << "Leaving traffic light." << endl;
			}
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we have a speed, front is at the last cell, tail is the second to last cell
	
	




	//------------------road zone------------------------
	//---------------------------------------------------
	front = -1; // index of front of car
	tail = front - zoneEnd; // index of back of car
	while(tail < 0 || (speed != SPEED0 && front < roadZone->getEnd()) ) { // while index of the front of the car is < index of the end
		check = roadZone->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance;
			speed = updateSpeed(check); // we want to slow down before we stop at the end of the drop off zone
		}
		if(speed != SPEED0) {
			( * roadZone->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail < 0) 
				( * roadEntrance->getRoad() )[roadEntrance->getEnd() + 1 + tail].release(); // tail could be in entrance
			if(tail >= 0) 
				( * roadZone->getRoad() )[tail].release(); // tail is in zone
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
		
	}// here we are stopped somewhere in the drop off zone
	cout << "Stopped. Front: " << front << " Unloading..." << endl;
	speed = SPEED0;
	hold(unloadTime);
	cout << "...Done. Front: " << front << " Departing." << endl;
	
	while( front < roadZone->getEnd() ) { // while index of the front of the car is < index of the end
		check = roadZone->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = check - lookAheadDistance + roadExit->lookAhead(-1, lookAheadDistance - (check - lookAheadDistance)); // look ahead to exit
			speed = updateSpeed(check);
		}
		if(speed != SPEED0) {
			( * roadZone->getRoad() )[front+1].reserve();
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail >= 0) 
				( * roadZone->getRoad() )[tail].release();
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we have a speed, front is at the last cell, tail is the second to last cell
	
	
	
	
	
	
	
	
	
	//------------------road exit------------------------
	//---------------------------------------------------
	front = -1; // index of front of car
	tail = front - zoneEnd; // index of back of car
	while( front < roadExit->getEnd() + 2) { // while index of the tail of the car is <= index of the end
		check = roadExit->lookAhead(front, lookAheadDistance); // get number of free spot in front of you
		if(check <= lookAheadDistance) { // free spots up to lookAheadDistance
			speed = updateSpeed(check);
		}
		else if(check > lookAheadDistance) { // free spots up to end of road
			check = lookAheadDistance;
			speed = updateSpeed(check); // we do not want to slow down at the end 
		}
		if(speed != SPEED0) {
			if(front < roadExit->getEnd()) // front will leave the end
				( * roadExit->getRoad() )[front+1].reserve(); 
			front++;
			hold(speed/100.0); // in this hold, the car length is 3 (most of the time)
			if(tail < 0) 
				( * roadZone->getRoad() )[roadZone->getEnd() + 1 + tail].release(); // tail could be in zone
			if(tail >= 0 && tail <= roadExit->getEnd()) {
				( * roadExit->getRoad() )[tail].release(); // tail is in zone
			}
			tail++; // car length will be 2 (a small fraction of time)
		}
		else
			hold(0.001);
	}// here we are gone 
	cout << "Gone" << endl;
	
}
















Speed Car::updateSpeed(int check) {
	switch(speed) {
		case SPEED0: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED1;
				case 2: return SPEED1;
				case 3: return SPEED1;
				case 4: return SPEED1;
				case 5: return SPEED1;
				case 6: return SPEED1;
				case 7: return SPEED1;
				case 8: return SPEED1;
				default:return SPEED0;
			}; break;
		case SPEED1: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED1;
				case 2: return SPEED1;
				case 3: return SPEED2;
				case 4: return SPEED2;
				case 5: return SPEED2;
				case 6: return SPEED2;
				case 7: return SPEED2;
				case 8: return SPEED2;
				default:return SPEED1;
			}; break;
		case SPEED2: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED1;
				case 2: return SPEED1;
				case 3: return SPEED2;
				case 4: return SPEED3;
				case 5: return SPEED3;
				case 6: return SPEED3;
				case 7: return SPEED3;
				case 8: return SPEED3;
				default:return SPEED2;
			}; break;
		case SPEED3: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED2;
				case 2: return SPEED2;
				case 3: return SPEED2;
				case 4: return SPEED3;
				case 5: return SPEED3;
				case 6: return SPEED4;
				case 7: return SPEED4;
				case 8: return SPEED4;
				default:return SPEED3;
			}; break;
		case SPEED4: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED3;
				case 2: return SPEED3;
				case 3: return SPEED3;
				case 4: return SPEED3;
				case 5: return SPEED3;
				case 6: return SPEED4;
				case 7: return SPEED4;
				case 8: return SPEED5;
				default:return SPEED4;
			}; break;
		case SPEED5: 
			switch(check) {
				case 0: return SPEED0;
				case 1: return SPEED4;
				case 2: return SPEED4;
				case 3: return SPEED4;
				case 4: return SPEED4;
				case 5: return SPEED4;
				case 6: return SPEED4;
				case 7: return SPEED4;
				case 8: return SPEED5;
				default:return SPEED5;
			}; break;
		default: return SPEED0;
	}
		
}



