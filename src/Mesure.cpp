/*************************************************************************
						   Mesure  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Mesure> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>

//------------------------------------------------------ Include personnel
#include "pch.h"
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Mesure::setTimestamp(Date s)
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
void Mesure::setValue(double s)
{
	value = s;
}

Date Mesure::getTimestamp()  const
{
	return timestamp;
}

string Mesure::getSensorID()  const
{
	return sensorID;
}

string Mesure::getAttributeID()  const
{
	return attributeID;
}

double Mesure::getValue()  const
{
	return value;
}

void Mesure::afficher()
{
	cout << timestamp << ";" << sensorID << ";" << attributeID << ";" << value << endl;
}
// type Mesure::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
Mesure & Mesure::operator = (const Mesure & uneMesure)
// Algorithme :
//
{
	if (this != &uneMesure)
	{
		timestamp = uneMesure.timestamp;
		sensorID = uneMesure.sensorID;
		attributeID = uneMesure.attributeID;
		value = uneMesure.value;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(Date unTimestamp, string unSensorID, string unAttributeID, double unValue)
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
	timestamp = unTimestamp;
	sensorID = unSensorID;
	attributeID = unAttributeID;
	value = unValue;
}

Mesure::Mesure(const Mesure & unMesure)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
	timestamp = unMesure.timestamp;
	sensorID = unMesure.sensorID;
	attributeID = unMesure.attributeID;
	value = unMesure.value;
} //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
