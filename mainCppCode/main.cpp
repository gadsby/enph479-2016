#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "headers/pump.h"
#include "headers/sensor.h"
#include "headers/sensorList.h"
#include "headers/states.h"
#include "headers/stateFuncs.h"
#include "headers/hardwareInterfacing.h"
#include "headers/settings.h"
using namespace std;


int main() {

	// Initialization
	int state = NORMAL;
	voltSensors volts;
	tempSensors temps;
	currSensor curr;
	pumpObj pump(P_OFF);

	// Main Loop
	while(true){
		switch(state){
			case NORMAL:
				state = normalState(volts, temps, curr, pump);
				break;
			case CHARGING:
				state = chargeState(volts, temps, curr, pump);
				break;
			case STANDBY:
				state = standbyState(volts, temps, curr, pump);
				break;
			case SAFETY:
				state = safetyState(volts, temps, curr, pump);
				break;
		}
		usleep(1);
	}
}