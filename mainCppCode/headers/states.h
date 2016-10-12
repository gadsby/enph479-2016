#ifndef STATES_H
#define STATES_H

#include <stdlib.h>
#include "headers/settings.h"
using namespace std;

// STATES
int normalState(void){ // still pythonic

	//while(true){
	for (int i = 0; i < 5; i++){
		updateVals(volts, temps, curr);
		checkVoltageCondition(volts);
		checkTemperatureCondition(temps, pump);
		checkCurrentCondition(curr);
	}
	return NORMAL;

}


int chargeState(void){

	return NORMAL;

}

int standbyState(void){

	return NORMAL;
	
}

int safetyState(void){

	return NORMAL;
	
}

#endif
