#ifndef STATES_H
#define STATES_H

#include <stdlib.h>
#include <unistd.h>
#include "settings.h"
#include "stateFuncs.h"
using namespace std;


int normalState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump);
int chargeState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump);
int standbyState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump);
int safetyState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump);


// STATES
int normalState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump){ //*

	//while(true){
	for (int i = 0; i < 5; i++){
		updateVals(volts, temps, curr);
		checkVoltageCondition(volts);
		checkTemperatureCondition(temps, pump);
		checkCurrentCondition(curr);
	}
	return NORMAL;

}


int chargeState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump){

	return NORMAL;

}

int standbyState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump){

	return NORMAL;
	
}

int safetyState(voltSensors volts, tempSensors temps, currSensor curr, pumpObj pump){

	return NORMAL;
	
}

#endif
