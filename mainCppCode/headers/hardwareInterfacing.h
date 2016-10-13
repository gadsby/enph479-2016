#ifndef HARDWARE_INTERFACE_H
#define HARDWARE_INTERFACE_H


#include <stdlib.h>
using namespace std;


double readAnalogPin(int pinNumber);
void writeDigitalPin(int pinNumber, int value);
void switchMux(int muxState);
double convert_5V(int val);


double readAnalogPin(int pinNumber){
	return convert_5V(rand() % 1024); //*
	// read analog pin instead of rand
}

void writeDigitalPin(int pinNumber, int value){
	//cout << "Wrote " << value << " to pin " << pinNumber << '\n'; //*
	// write to digital pin
}

void switchMux(int muxSelect, int muxState){
	if (muxState != NO_MUX){
		cout << "Switched mux " << muxSelect << " to state " << muxState << '\n'; //*
		// switch mux channel
	}
}

double convert_5V(int val){
	return 5.0 * val / 1023.0;
}


#endif