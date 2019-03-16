#ifndef STAT_H // include guard
#define STAT_H


class Stat {
private:
	int carCount;
	event *count;
	
public:
	Stat();
	void run();
	void setCount();
	void printThroughput(double time);
	
};

#endif /* STAT_H */

