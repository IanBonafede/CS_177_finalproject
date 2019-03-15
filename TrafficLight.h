#ifndef TRAFFICLIGHT_H // include guard
#define TRAFFICLIGHT_H





using namespace std;


class TrafficLight {
private:
	facility *light;
	event *go;
	double goInt;
	
public:
	TrafficLight();
	void run();
	event *getGoEvent();
	facility *getLight();
	
	
};



#endif /* TRAFFICLIGHT_H */
