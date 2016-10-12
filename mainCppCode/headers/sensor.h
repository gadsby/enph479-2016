#ifndef SENSOR_H
#define SENSOR_H

#include <stdlib.h>
#include <deque>
#include <numeric>
using namespace std;


class sensor {
	public:
		sensor(const std::string name, const std::string type, const int pin); // Constructor
		void update(void);
		double nowVal(void);
		double avgVal(void);

	private:
		static int const numPoints2keep = 10;
		std::string name;
		std::string type;
		int pin;
		deque<double> history;
		int readCount;
};

	sensor::sensor(std::string nameIn, std::string typeIn, int pinIn){
		name = nameIn;
		type = typeIn;
		pin = pinIn;
		history = {0,0,0,0,0,0,0,0,0,0}; // FIX make size based on numPoints2keep
		readCount = 0;
	}

	void sensor::update(void){
		int readVal = readPin(pin); // FIX actually want to readPin(pin) when complete
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

			if (readCount < numPoints2keep){
				return sumHist/readCount;
			} else {
				return sumHist/numPoints2keep;
			}
		}
	}

#endif