/*************************************************************************
						   Capteur  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Capteur> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "pch.h"
#include "Capteur.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
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

// type Capteur::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
