#ifndef STAT_H // include guard
#define STAT_H


class Stat {
private:
	int carCount;
	event *count;
	
public:
	Stat();
	void run();
	void count();
	void printThroughput(double time);
	
};

#endif /* STAT_H */

