/*************************************************************************
                           Date  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Date::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = ( const Date & uneDate )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Date::Date ( const Date & uneDate )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Date>" << endl;
#endif

	annee = uneDate.annee;
	mois = uneDate.mois;
	jour = uneDate.jour;
	heure = uneDate.heure;
	minute = uneDate.minute;
	seconde = uneDate.seconde;
} //----- Fin de Date (constructeur de copie)


Date::Date (int a, int mo, int j, int h, int mi, int s)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Date>" << endl;
#endif
	annee = a;
	mois = mo;
	jour = j;
	heure = h;
	minute = mi;
	seconde = s;

} //----- Fin de Date


Date::~Date ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
