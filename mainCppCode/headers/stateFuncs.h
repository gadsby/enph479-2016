#ifndef STATE_FUNCS_H
#define STATE_FUNCS_H

#include <stdlib.h>
#include "headers/settings.h"
using namespace std;


// ALL STILL PYTHONIC; NEED TO CHANGE TO C++


// FUNCTIONS - NORMAL STATE
void updateVals(volts, temps, curr){
	volts.update()
	temps.update()
	curr.update()
}

void checkVoltageCondition(volts){
	if any(voltage < v_min_thresh for voltage in volts.nowVals()):
		print('Voltage too low, shutting down')
}

void checkTemperatureCondition(temps, pump){
	belowMin = any( temperature < t_min_thresh for temperature in temps.nowVals() )
	aboveMax = any( temperature > t_max_thresh for temperature in temps.nowVals() )

	if belowMin:
		pump.setPump(OFF)
	elif aboveMax:
		print('Temperature too high, shutting down')
	else:
		pump.setPump(MID)
}

void checkCurrentCondition(curr){
	if any(current > c_max_thresh for current in curr.nowVals()):
		print('Current too high, shutting down')
}


#endif
