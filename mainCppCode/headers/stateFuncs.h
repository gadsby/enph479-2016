#ifndef STATE_FUNCS_H
#define STATE_FUNCS_H

#include <stdlib.h>
#include "headers/settings.h"
using namespace std;


void updateVals(volts, temps, curr);
void checkVoltageCondition(volts);
void checkTemperatureCondition(temps, pump);
void checkCurrentCondition(curr);


// FUNCTIONS - NORMAL STATE
void updateVals(volts, temps, curr){ //*
	volts.update();
	temps.update();
	curr.update();
}

void checkVoltageCondition(volts){ //*
	bool belowMin_V = any(voltage < v_min_thresh for voltage in volts.nowVals())
	if (belowMin_V == true){
		cout << "Voltage too low, shutting down" << '\n';
	}
}

void checkTemperatureCondition(temps, pump){ //*

	bool belowMin_T = any( temperature < T_MIN for temperature in temps.nowVals() ) //*
	bool aboveMax_T = any( temperature > T_MAX for temperature in temps.nowVals() ) //*

	if (belowMin_T == true){
		pump.setPump(P_OFF);

	} else if (aboveMax_T == true){
		cout << "Temperature too high, shutting down" << '\n';
		// shut off system

	} else {
		pump.setPump(P_LOW);
	}

}

void checkCurrentCondition(curr){ //*

	bool aboveMax_C = any( current > c_max_thresh for current in curr.nowVals() ) //*

	if (aboveMax_C == true){
		cout << "Current too high, shutting down" << '\n';
		// shut off system
	}

}


#endif
