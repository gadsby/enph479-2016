#ifndef PUMP_H
#define PUMP_H

#include "settings.h"
#include "hardwareInterfacing.h"
using namespace std;



class pumpObj {
   public:
		pumpObj(int state);
		void setPump(int state);

   private:
	  int state;
	  
};

pumpObj::pumpObj(int stateIn){
	state = stateIn;
	setPump(state);
}


void pumpObj::setPump(int stateIn){
	if (stateIn == state){
		return;
	}

	state = stateIn;

	switch (state)
	{

		// deal with glitch possibility here

		case P_OFF:
			cout << "Turning pump off" << '\n'; //*
			switchMux(PIN_SELECT_PUMP_POWER_MUX, MUXCHAN_P_OFF);
			break;

		case P_LOW:
			cout << "Turning pump on - low" << '\n'; //*
			switchMux(PIN_SELECT_PUMP_POWER_MUX, MUXCHAN_P_LOW);
			break;
			
		case P_HIG:
			cout << "Turning pump on - hig" << '\n'; //*
			switchMux(PIN_SELECT_PUMP_POWER_MUX, MUXCHAN_P_HIG);
			break;
	}

	writeDigitalPin(PIN_WRITE_PUMP_POWER_MUX, DIG_HIG);

}

#endif