
#include "LowPassFilter.h"

LowPassFilter::LowPassFilter(int iOrder, float iCutOffFrequency): 
	cutOffFrequency(iCutOffFrequency), 
	Order(iOrder),
	ePow(0){}

LowPassFilter::LowPassFilter(int iOrder, float iCutOffFrequency, float iDeltaTime): 
	cutOffFrequency(iCutOffFrequency), 
	Order(iOrder),
	ePow(1-exp(-iDeltaTime * cutOffFrequency)){}

float LowPassFilter::update(float input){
	return output += (input - output) * ePow;
}

float LowPassFilter::update(float input, float deltaTime){
	setDeltaTime(deltaTime); //Changes ePow accordingly.
	return output += (input - output) * ePow);
}

float LowPassFilter::getOutput(){
	return output;
}

float LowPassFilter::getCutOffFrequency(){
	return cutOffFrequency;
}

void LowPassFilter::setCutOffFrequency(float input){
	if (input >= 0){
		cutOffFrequency = input;
	}
	else{
		cutOffFrequency = 0;
		cout << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
	}
}

void LowPassFilter::setDeltaTime(float deltaTime){
	if (deltaTime >= 0){
		ePow = 1-exp(-deltaTime * cutOffFrequency);
	}
	else{
		ePow = 0;
		cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
	}
}