#ifndef TRAFFICLIGHT_H // include guard
#define TRAFFICLIGHT_H





using namespace std;


class TrafficLight {
private:
	facility *light;
	facility_ms *lights;
	event *go;
	double goInt;
	
public:
	TrafficLight();
	void run();
	event *getGoEvent();
	facility *getLight();
	facility_ms *getLights();
	
	
};



#endif /* TRAFFICLIGHT_H */
