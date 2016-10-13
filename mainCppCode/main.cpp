#include <stdlib.h>
#include "headers/pump.h"
#include "headers/sensor.h"
#include "headers/settings.h"
#include "headers/states.h"
#include "headers/stateFuncs.h"
#include "headers/hardwareInterfacing.h"
using namespace std;


int main() {

	// Initialization
	int state = NORMAL;
	voltSensors volts();
	tempSensors temps();
	currSensor curr();
	pumpObj pump(P_OFF);

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