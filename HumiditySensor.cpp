#pragma once
#include <iostream>
#include <string>
#include "Sensor.h"
#include "System.h"
#include "HumiditySensor.h"
using namespace std;

HumiditySensor::HumiditySensor(){
	cout << "HumiditySensor default constructor" << endl;
}
HumiditySensor::HumiditySensor(SensorSystem* sys, string name, string link, double h_min, double h_max,double h_crit)
	:Sensor(sys, name, link), h_min(h_min), h_max(h_max), h_crit(h_crit)
{
	cout << "HumiditySensor: " << name << " ," << link << "." << endl;

}
HumiditySensor::~HumiditySensor(){
}
void HumiditySensor::measure(SensorSystem* sys){
	current_measure=((rand() % (int)(h_max - h_min)) + h_min);
	cout<<"Wilgotnosc " <<name<<" : "<<current_measure<<"%"<< endl;
	if (h_crit <= current_measure)
	{
		sys->CriticalValue(this);
	}
}