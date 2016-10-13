#include <iostream>
#include <string>
#include "headers/pump.h"
#include "headers/sensor.h"
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
	// TODO


}
