/*************************************************************************
						   Mesure  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Mesure> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
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

Date Mesure::getTimestamp()
{
	return timestamp;
}

string Mesure::getSensorID()
{
	return sensorID;
}

string Mesure::getAttributeID()
{
	return sensorID;
}

double Mesure::getValue()
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
Mesure & Mesure::operator = (const Mesure & unMesure)
// Algorithme :
//
{
	timestamp = unMesure.timestamp;
	sensorID = unMesure.sensorID;
	attributeID = unMesure.attributeID;
	value = unMesure.value;
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
