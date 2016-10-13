#include <iostream>
#include <string>
#include "headers/pump.h"
#include "headers/sensor.h"
#include "headers/sensorList.h"
#include "headers/stateFuncs.h"
#include "headers/settings.h"
using namespace std;


int main() {

	// PUMP
	cout << "Testing pump class:" << '\n';
	pumpObj pump(P_OFF);
	for (int i = 0; i < 10; i++){
		pump.setPump(i%4);
	}
	cout<< '\n';

	// SENSOR
	cout << "Testing sensor class:" << '\n';
	sensor sensor1("temp00", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_00);
	for (int i = 0; i < 15; i++){
		sensor1.update();
		cout << "Value now: " << sensor1.nowVal() << '\n';
		cout << "Avg val: " << sensor1.avgVal() << '\n';
		cout << '\n';
	}

	// SENSOR LIST
	cout << "Testing sensorList class:" << '\n';
	voltSensors volts;
	tempSensors temps;
	currSensor curr;

	vector<double> nowVals_V;
	vector<double> nowVals_T;
	vector<double> nowVals_C;

	for (int i = 0; i < 15; i++){
		volts.update();
		temps.update();
		curr.update();

		nowVals_V = volts.nowVals();
		cout << "V Values: " << '\n';
		for (int i = 0; i < nowVals_V.size(); i++){
			cout << nowVals_V.at(i) << '	';
		}
		cout << '\n';

		nowVals_T = temps.nowVals();
		cout << "T Values: " << '\n';
		for (int i = 0; i < nowVals_T.size(); i++){
			cout << nowVals_T.at(i) << '	';
		}
		cout << '\n';

		nowVals_C = curr.nowVals();
		cout << "C Values: " << '\n';
		for (int i = 0; i < nowVals_C.size(); i++){
			cout << nowVals_C.at(i) << '	';
		}
		cout << '\n';

	}



}
