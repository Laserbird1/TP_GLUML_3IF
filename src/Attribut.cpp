/*************************************************************************
						   Attribut  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Attribut> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

//------------------------------------------------------ Include personnel
#include "pch.h"
#include "Attribut.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Attribut::setAttributeID(string s)
{
	attributeID = s;
}

string Attribut::getAttributeID() const
{
	return this->attributeID;
}

void Attribut::setUnit(string s)
{
	unit = s;
}
void Attribut::setDescription(string s)
{
	description = s;
}

void Attribut::afficher() const
{
	cout << attributeID << ";" << unit << ";" << description << endl;
}

// type Attribut::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es

