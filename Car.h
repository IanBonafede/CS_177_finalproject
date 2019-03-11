#include <iostream>
#include "cpp.h"
#include <string.h>

using namespace std;



extern "C" void sim() // Alice is the main process
{
	create("sim");
	
	
	hold(480);
	report();
}
