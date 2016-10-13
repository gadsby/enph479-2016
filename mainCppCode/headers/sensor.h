#ifndef SENSOR_H
#define SENSOR_H

#include <stdlib.h>
#include <deque>
#include <numeric>
//#include "settings.h"
using namespace std;


class sensor {
	public:
		sensor(const std::string name, const std::string type, const int pinRead, const int muxChan);
		void update(void);
		double nowVal(void);
		double avgVal(void);

	private:
		std::string name;
		std::string type;
		int pinRead;
		int muxChan;
		deque<double> history;
		int readCount;
};

	sensor::sensor(std::string nameIn, std::string typeIn, int pinReadIn, int muxIn){
		name = nameIn;
		type = typeIn;
		pinRead = pinReadIn;
		muxChan = muxIn;
		readCount = 0;
		for (int i=0; i < HISTORY_LEN; i++){
			history.push_back(0);
		}
	}

	void sensor::update(void){
		switchMux(PIN_SELECT_SENSOR_MUX, muxChan);
		int readVal = readAnalogPin(PIN_READ_SENSOR_MUX);
		history.pop_front();
		history.push_back(readVal); 
		readCount++;
	}


	double sensor::nowVal(void){
		return history.back();
	}


	double sensor::avgVal(void){
		if (readCount == 0){
			return 0;
		} else{

			double sumHist = 0;
			for (int i=0; i<history.size(); i++){
				sumHist += history.at(i);
			}

			if (readCount < HISTORY_LEN){
				return sumHist/readCount;
			} else {
				return sumHist/HISTORY_LEN;
			}
		}
	}

#endif