#ifndef STATE_FUNCS_H
#define STATE_FUNCS_H

#include <stdlib.h>
#include "settings.h"
using namespace std;


bool anyCond(vector<double> inVect, double condition, bool greater);
void updateVals(voltSensors volts, tempSensors temps, currSensor curr);
void checkVoltageCondition(voltSensors volts);
void checkTemperatureCondition(tempSensors temps, pumpObj pump);
void checkCurrentCondition(currSensor curr);



bool anyCond(vector<double> inVect, double condition, bool greater){

	if (greater){
		for (int i = 0; i < inVect.size(); i++){
			if (inVect.at(i) > condition)
				return true;}
		return false;

	} else {
		for (int i = 0; i < inVect.size(); i++){
			if (inVect.at(i) < condition)
				return true;}
		return false;
	}

}







// FUNCTIONS - NORMAL STATE
void updateVals(voltSensors volts, tempSensors temps, currSensor curr){
	volts.update();
	temps.update();
	curr.update();
}

void checkVoltageCondition(voltSensors volts){

	bool belowMin_V = anyCond(volts.nowVals(), V_MIN, false);

	if (belowMin_V){
		cout << "Voltage too low, shutting down" << '\n';
	}
}

void checkTemperatureCondition(tempSensors temps, pumpObj pump){

	bool belowMin_T = anyCond(temps.nowVals(), V_MIN, false);
	bool aboveMax_T = anyCond(temps.nowVals(), T_MAX, true);

	if (belowMin_T){
		pump.setPump(P_OFF);

	} else if (aboveMax_T){
		cout << "Temperature too high, shutting down" << '\n';
		// shut off system

	} else {
		pump.setPump(P_LOW);
	}

}

void checkCurrentCondition(currSensor curr){

	bool aboveMax_C = anyCond(curr.nowVals(), C_MAX, true);

	if (aboveMax_C){
		cout << "Current too high, shutting down" << '\n';
		// shut off system
	}

}


#endif
