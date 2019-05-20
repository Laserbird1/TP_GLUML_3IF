/*************************************************************************
						   Capteur  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "pch.h"
#include "Capteur.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Capteur::setSensorID(string s)
{
	sensorID = s;
}
void Capteur::setLatitude(double s)
{
	latitude = s;
}
void Capteur::setLongitude(double s)
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

// type Capteur::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
bool Capteur::operator == (const Capteur& c) const
{
	return sensorID == c.sensorID;
}

bool Capteur::operator < (const Capteur&c) const
{
	return sensorID.compare(c.sensorID) < 0;
}


//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur(const Capteur & unCapteur)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Capteur>" << endl;
#endif
} //----- Fin de Capteur (constructeur de copie)


Capteur::Capteur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Capteur>" << endl;
#endif
} //----- Fin de Capteur


Capteur::~Capteur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
