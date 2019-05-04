#include "pch.h"
#include "Capteur.h"


Capteur::Capteur()
{
}


Capteur::~Capteur()
{
}

void Capteur::setSensorID(string s)
{
	sensorID = s; 
}
void Capteur::setLatitude(string s)
{
	latitude = s;
}
void Capteur::setLongitude(string s)
{
	longitude = s;
}
void Capteur::setDescription(string s)
{
	description = s;
}

void Capteur::afficher() const
{
	cout << sensorID << ";" << latitude << ";" << longitude << ";" << description << endl;
}

bool Capteur::operator == (const Capteur& c) const
{
	return sensorID == c.sensorID;
}

bool Capteur::operator < (const Capteur&c) const
{
	return sensorID.compare(c.sensorID) < 0;
}
