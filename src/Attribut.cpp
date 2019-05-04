#include "pch.h"
#include "Attribut.h"


Attribut::Attribut()
{
}


Attribut::~Attribut()
{
}


void Attribut::setAttributeID(string s)
{
	attributeID = s;
}
void Attribut::setUnit(string s)
{
	unit = s;
}
void Attribut::setDescription(string s)
{
	description = s;
}

void Attribut::afficher()
{
	cout << attributeID << ";" << unit << ";" << description << endl;
}

bool Attribut::operator == (const Attribut& a) const
{
	return attributeID == a.attributeID;
}

bool Attribut::operator < (const Attribut& a) const
{
	return attributeID.compare(a.attributeID) < 0;
}
