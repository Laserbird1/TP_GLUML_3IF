/*************************************************************************
						   Attribut  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
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

// type Attribut::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
bool Attribut::operator == (const Attribut& a) const
{
	return attributeID == a.attributeID;
}

bool Attribut::operator < (const Attribut& a) const
{
	return attributeID.compare(a.attributeID) < 0;
}

//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & unAttribut)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Attribut>" << endl;
#endif
} //----- Fin de Attribut (constructeur de copie)


Attribut::Attribut()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

