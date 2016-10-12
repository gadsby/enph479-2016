#include <iostream>
#include <string>
#include "headers/pump.h"
#include "headers/sensor.h"
#include "headers/settings.h"
using namespace std;

#define PIN_PUMP 1


int main() {

	// PUMP
	cout << "Testing pump class:" << '\n';
	pumpObj pump(P_OFF, PIN_PUMP);
	for (int i = 0; i < 10; i++){
		pump.setPump(i%4);
	}
	cout<< '\n';

	// SENSOR
	cout << "Testing sensor class:" << '\n';
	sensor sensor1("Name", "temp", 5);
	for (int i = 0; i < 20; i++){
		sensor1.update();
		cout << "Value now: " << sensor1.nowVal() << '\n';
		cout << "Avg val: " << sensor1.avgVal() << '\n';
		cout << '\n';
	}

	// SENSOR LIST
	// TODO


}
