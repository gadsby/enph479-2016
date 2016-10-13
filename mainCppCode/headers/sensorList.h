#ifndef SENSORLIST_H
#define SENSORLIST_H

#include <stdlib.h>
#include <vector>
#include "sensor.h"
using namespace std;


class sensorList{

	private:
		sensorList();

	protected:
		vector<sensor*> sensorList;

	public:
		void update(void);
		vector<double> nowVals(void);
};


void sensorList::update(){
	for (int i = 0; i < sensorList.size(); i++){
		sensorList.at(i).update();
	}
}

vector<double> sensorList::nowVals(){
	vector<double> nowVal_vect;
	for (int i = 0; i < numElements; i++){
		nowVal_vect.push_back( sensorList.at(i).avgVal() );
	}
	return nowVal_vect
}




class voltSensors: public sensorList{
	private:
		voltSensors();
};



class tempSensors: public sensorList{
	private:
		tempSensors();
};



class currSensor: public sensorList{
	private:
		currSensor();
};





voltSensors::voltSensors(){

	sensorList.push_back(new sensor(   "volt00", "volt", PIN_VOLTAGE_00, NO_MUX   );
	sensorList.push_back(new sensor(   "volt01", "volt", PIN_VOLTAGE_01, NO_MUX   );
	sensorList.push_back(new sensor(   "volt02", "volt", PIN_VOLTAGE_02, NO_MUX   );
	sensorList.push_back(new sensor(   "volt03", "volt", PIN_VOLTAGE_03, NO_MUX   );
	sensorList.push_back(new sensor(   "volt04", "volt", PIN_VOLTAGE_04, NO_MUX   );
	sensorList.push_back(new sensor(   "volt05", "volt", PIN_VOLTAGE_05, NO_MUX   );
	sensorList.push_back(new sensor(   "volt06", "volt", PIN_VOLTAGE_06, NO_MUX   );
	sensorList.push_back(new sensor(   "volt07", "volt", PIN_VOLTAGE_07, NO_MUX   );
	sensorList.push_back(new sensor(   "volt08", "volt", PIN_VOLTAGE_08, NO_MUX   );
	sensorList.push_back(new sensor(   "volt09", "volt", PIN_VOLTAGE_09, NO_MUX   );
	sensorList.push_back(new sensor(   "volt10", "volt", PIN_VOLTAGE_10, NO_MUX   );
	sensorList.push_back(new sensor(   "volt11", "volt", PIN_VOLTAGE_11, NO_MUX   );
	sensorList.push_back(new sensor(   "volt12", "volt", PIN_VOLTAGE_12, NO_MUX   );
	sensorList.push_back(new sensor(   "volt13", "volt", PIN_VOLTAGE_13, NO_MUX   );

}

tempSensors::tempSensors(){

	sensorList.push_back(new sensor(   "temp00", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_00   );
	sensorList.push_back(new sensor(   "temp01", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_01   );
	sensorList.push_back(new sensor(   "temp02", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_02   );
	sensorList.push_back(new sensor(   "temp03", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_03   );
	sensorList.push_back(new sensor(   "temp04", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_04   );
	sensorList.push_back(new sensor(   "temp05", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_05   );
	sensorList.push_back(new sensor(   "temp06", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_06   );
	sensorList.push_back(new sensor(   "temp07", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_07   );
	sensorList.push_back(new sensor(   "temp08", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_08   );
	sensorList.push_back(new sensor(   "temp09", "temp", PIN_READ_SENSOR_MUX, MUXCHAN_TEMP_09   );

}

currSensor::currSensor(){
	sensorList.push_back(new sensor(   "curr00", "curr", PIN_READ_SENSOR_MUX, MUXCHAN_CURR_00   );
}




#endif
