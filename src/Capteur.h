#pragma once

#include <iostream>
#include <string>

using namespace std;

class Capteur
{
public:
	Capteur();
	~Capteur();

	void setSensorID(string s);
	void setLatitude(string s);
	void setLongitude(string s);
	void setDescription(string s);
	void afficher() const;

	bool operator == (const Capteur& c) const;
	bool operator < (const Capteur&c) const;

private:
	string sensorID;
	string latitude;
	string longitude;
	string description;
};

