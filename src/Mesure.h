#pragma once

#include <iostream>
#include <string>

using namespace std;

class Mesure
{
public:
	Mesure();
	~Mesure();

	void setTimestamp(string s);
	void setSensorID(string s);
	void setAttributeID(string s);
	void setValue(string s);

	void afficher();

private:
	string timestamp;
	string sensorID;
	string attributeID;
	string value;
};

