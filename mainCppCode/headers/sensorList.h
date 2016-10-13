#ifndef SENSORLIST_H
#define SENSORLIST_H

#include <stdlib.h>
#include <vector>
#include "sensor.h"
using namespace std;


class sensorList{		

	protected:
		vector<sensor*> listOfSensors;

	public:
		void update(void);
		vector<double> nowVals(void);

};

void sensorList::update(){
	for (int i = 0; i < listOfSensors.size(); i++){
		listOfSensors.at(i)->update();
	}
}

vector<double> sensorList::nowVals(){
	vector<double> nowVal_vect;
	for (int i = 0; i < listOfSensors.size(); i++){
		nowVal_vect.push_back( listOfSensors.at(i)->avgVal() );
	}
	return nowVal_vect;
}


class voltSensors: public sensorList{
	public:
		voltSensors();
};

class tempSensors: public sensorList{
	public:
		tempSensors();
};

class currSensor: public sensorList{
	public:
		currSensor();
};





voltSensors::voltSensors(){

	listOfSensors.push_back(new sensor(   "volt00", "volt", PIN_READ_VOLTAGE_00, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt01", "volt", PIN_READ_VOLTAGE_01, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt02", "volt", PIN_READ_VOLTAGE_02, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt03", "volt", PIN_READ_VOLTAGE_03, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt04", "volt", PIN_READ_VOLTAGE_04, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt05", "volt", PIN_READ_VOLTAGE_05, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt06", "volt", PIN_READ_VOLTAGE_06, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt07", "volt", PIN_READ_VOLTAGE_07, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt08", "volt", PIN_READ_VOLTAGE_08, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt09", "volt", PIN_READ_VOLTAGE_09, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt10", "volt", PIN_READ_VOLTAGE_10, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt11", "volt", PIN_READ_VOLTAGE_11, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt12", "volt", PIN_READ_VOLTAGE_12, NO_MUX    ));
	listOfSensors.push_back(new sensor(   "volt13", "volt", PIN_READ_VOLTAGE_13, NO_MUX    ));

}

tempSensors::tempSensors(){

	listOfSensors.push_back(new sensor(   "temp00", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_00    ));
	listOfSensors.push_back(new sensor(   "temp01", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_01    ));
	listOfSensors.push_back(new sensor(   "temp02", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_02    ));
	listOfSensors.push_back(new sensor(   "temp03", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_03    ));
	listOfSensors.push_back(new sensor(   "temp04", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_04    ));
	listOfSensors.push_back(new sensor(   "temp05", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_05    ));
	listOfSensors.push_back(new sensor(   "temp06", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_06    ));
	listOfSensors.push_back(new sensor(   "temp07", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_07    ));
	listOfSensors.push_back(new sensor(   "temp08", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_08    ));
	listOfSensors.push_back(new sensor(   "temp09", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_09    ));

}

currSensor::currSensor(){
	listOfSensors.push_back(new sensor(   "curr00", "curr", PIN_READ_SENSOR_MUX, MUXCHAN_CURR_00    ));
}




#endif
