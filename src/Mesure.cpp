#include "pch.h"
#include "Mesure.h"


Mesure::Mesure()
{
}



Mesure::~Mesure()
{
}

void Mesure::setTimestamp(struct tm s)
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

void Mesure::afficher()
{
	cout << timestamp << ";" << sensorID << ";" << attributeID << ";" << value << endl;
}


/*************************************************************************
						   Mesure  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Mesure::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Mesure & Mesure::operator = (const Mesure & unMesure)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(struct tm unTimestamp, string unSensorID, string unAttributeID, double unValue)
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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
