#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Sensor.h"
#include "System.h"
#include "TempSensor.h"
#include "HumiditySensor.h"

int main()
{

	// wartosci krytyczne, zapamietac uchwyt do systemu
	// czujnik musi asynchronicznie wywolac metode z sys. 
	// sekcja krytyczna lub kolejka komunikatow (jesli bedzie wielowatkowosc)
/*
system
{
void notify()
{
mutex.lock();
mutex.unlock();
}
}*/
	srand(time(NULL));
	SensorSystem* syst = new SensorSystem();
	//dlaczego wywoluje sie domyslny konstruktor Sensor??
	Sensor* newSensor = new TempSensor(syst, "w kuchni", "COM", +10.0, +30.0, +23.0);
	newSensor = new HumiditySensor(syst, "w pokoju", "UDP", +0.0, +120.0,+80.0);
	syst->ShowAll();
	newSensor = new TempSensor(syst, "w kiblu", "UDP", +18.0, +35.0, +20.0);
	//newSensor = new TempSensor(syst, "w pokoju", "Ethernet", +18.0, +21.0);
	syst->MeasureAll();
	//syst->ShowAll();
	syst->MeasureToFile();
	delete syst;
	_getch();
	return 0;
	
}