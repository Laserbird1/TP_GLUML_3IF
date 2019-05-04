#pragma once

#include <iostream>
#include <string>

using namespace std;

class Attribut
{
public:
	Attribut();
	~Attribut();

	void setAttributeID(string s);
	void setUnit(string s);
	void setDescription(string s);
	void afficher();

	bool operator == (const Attribut& a) const;
	bool operator < (const Attribut& a) const;

private:
	string attributeID;
	string unit;
	string description;
};

