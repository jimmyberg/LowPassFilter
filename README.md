# LowPassFilter
C++ library for low pass filters.

It can be used in applications where the cycletime will be constant and where it is dynamic.
The cycletime setting can also be canged on the fly.
Note that using with dynamic cycle time is much slower becouse e^(cutOffFrequency * deltaTime) has to be calculated over and over again.

##Example with static cycle time

```c++
#include <iostream>
#include "LowPassFilter.hpp"
using namespace std;

int main(int argc, char** argv){
	//Create a low pass filter with 1 hz cuttoff freqency. DetltaTime for each cycle equals 0.01 seonds
	LowPassFilter lpf(1.0, 0.01);
	//Cycles 500 times. With the lpf deltaTime set to 0.01 it will simulate 5 seconds of run time
	for(int i = 0; i < 500; i++){
		cout << lpf.update(1.0) << endl;
	}
	return 1;
}
```
##Example with dynamic time
```c++
#include <iostream>
#include "LowPassFilter.hpp"
using namespace std;

#include <cmath> //Used for the sin() function.

int main(int argc, char** argv){
	//Create a low pass filter with 1 hz cuttoff freqency. DetltaTime for each cycle is unknown and will vary.
	LowPassFilter lpf(1.0);
	//Cycles 500 times. cycle time will be about 0.01 seconds so this code will simulate a 5 seconds of run time.
	for(int i = 0; i < 500; i++){
		float cycleTime = 0.01 + (0.002 * sin((float)i * 0.05));
		cout << 
			"cycleTime = " << cycleTime << 
			",\t Output = " << lpf.update(1.0, cycleTime) << 
			endl;
	}
	return 1;
}
```
