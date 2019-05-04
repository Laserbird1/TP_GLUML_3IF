#include "pch.h"
#include "Mesure.h"


Mesure::Mesure()
{
}


Mesure::~Mesure()
{
}

void Mesure::setTimestamp(string s)
{
	timestamp = s;
}
void Mesure::setSensorID(string s)
{
	sensorID = s;
}
void Mesure::setAttributeID(string s)
{
	attributeID = s;
}
void Mesure::setValue(string s)
{
	value = s;
}

void Mesure::afficher()
{
	cout << timestamp << ";" << sensorID << ";" << attributeID << ";" << value << endl;
}
