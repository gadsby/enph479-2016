#include <stdlib.h>
#include "headers/pump.h"
#include "headers/sensor.h"
#include "headers/settings.h"
#include "headers/states.h"
#include "headers/stateFuncs.h"
#include "hardwareInterfacing.h"
using namespace std;


int main() {

	// Initialization (TODO: still pythonic)
	volts = cd.voltSensors(14);
	temps = cd.tempSensors(10);
	curr  = cd.currSensor();
	pump  = cd.pumpObj(OFF);
	state = NORMAL;



	// Main Loop
	while(true){
		switch(state){

			case NORMAL:
				state = normalState();
				break;

			case CHARGING:
				state = chargeState();
				break;

			case STANDBY:
				state = standbyState();
				break;

			case SAFETY:
				state = safetyState();
				break;

		}
	}
}