#ifndef ROAD_H // include guard
#define ROAD_H



using namespace std;


class Road {
private:
	facility_set *road;
	double cellLength;
	int cellNum;
	
public:
	Road(double len, double cellLen);
	facility_set *getRoad();
	int lookAhead(int carCell, int howMany);
	int getEnd();
	
};



#endif /* ROAD_H */
