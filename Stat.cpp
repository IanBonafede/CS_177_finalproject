#include "Stat.h"


#include "cpp.h"
#include <string.h>





Stat::Stat() {
	create("Stat");
	carCount = 0;
	count = new event("Count");
	run();
}

void Stat::run() {
	while(true) {
		count->wait();
		carCount++;
		hold(0.0001);
	}
}

void Stat::setCount() {
	count->set();
}

void Stat::printThroughput(double time) {
	cout << "Throughput: " << count / time << endl;
}
