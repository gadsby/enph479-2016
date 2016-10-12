#ifndef PUMP_H
#define PUMP_H

#include "settings.h"
using namespace std;


class pumpObj {
   public: //Methods
		pumpObj(int state, int pumpPin);  // This is the constructor
		void setPump(int state);

   private:	//Values
	  int state;
	  int pumpPin;
	  
};

pumpObj::pumpObj(int stateIn, int pinIn){
	state = stateIn;
	setPump(state);
	pumpPin = pinIn;
}


void pumpObj::setPump(int stateIn){
	if (stateIn == state){
		return;
	}

	state = stateIn;

	switch (state)
	{
		case P_OFF:
			cout << "Turning pump off" << '\n';
			// set pump off pin
			break;
		case P_LOW:
			cout << "Turning pump on - low" << '\n';
			// set pump low pin
			break;
		case P_MID:
			cout << "Turning pump on - mid" << '\n';
			// set pump mid pin
			break;
		case P_HIG:
			cout << "Turning pump on - hig" << '\n';
			// set pump hig pin
			break;
	}

}

#endif