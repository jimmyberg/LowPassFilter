
#ifndef _LowPassFilter_h_
#define _LowPassFilter_h_

#include <cmath>

class LowPassFilter{
public:
	//constructors
	LowPassFilter(int iOrder, float iCutOffFrequency);
	LowPassFilter(int iOrder, float iCutOffFrequency, float iDeltaTime);
	//variables
	int Order;
	//functions
	float update(float input);
	float update(float input, float deltaTime);
	//get and set funtions
	float getOutput();
	float getCutOffFrequency();
	void setCutOffFrequency(float input);
	void setDeltaTime(float input);
private:
	float output;
	float cutOffFrequency;
	static float ePow;
};

#endif //_LowPassFilter_h_
