# LowPassFilter
The **LowPassFilter** C++ library offers a convenient way to implement low pass filters for applications requiring signal smoothing. This library proves particularly useful in scenarios with constant cycletime as well as dynamic cycletime.

## Example with static cycle time

```c++
#include <iostream>
#include "LowPassFilter.hpp"
using namespace std;

int main(int argc, char** argv){
	// Create a low pass filter with 1 Hz cuttoff freqency. DetltaTime for each
	// cycle equals 0.01 seonds
	LowPassFilter lpf(1.0, 0.01);
	// Cycles 500 times.
	//
	// As the lpf deltaTime set to 0.01 it will simulate 5 seconds of run time.
	for(int i = 0; i < 500; i++){
		cout << lpf.update(1.0) << endl; //Update with 1.0 as input value.
	}
	return 1;
}
```
## Example with dynamic cycle time
```c++
#include <iostream>
#include "LowPassFilter.hpp"
using namespace std;

#include <cmath> //Used for the sin() function.

int main(int argc, char** argv){
	// Create a low pass filter. DetltaTime for each cycle is unknown and will
	// vary.
	LowPassFilter lpf;
	// Cycles 500 times.
	//
	// As the lpf deltaTime set to 0.01 it will simulate 5 seconds of run time.
	for(int i = 0; i < 500; i++){
		// Simulate a slightly varying sampling time. for each cycle.
		float cycleTime = 0.01 + (0.002 * sin((float)i * 0.05));
		cout <<
			"cycleTime = " << cycleTime <<
			",\t Output = " <<
			// Update with 1.0 as input value, the current cycle time as
			// deltaTime and 2 Hz cutoff frequency.
			lpf.update(1.0, cycleTime, 2) <<
			endl;
	}
	return 1;
}
```
