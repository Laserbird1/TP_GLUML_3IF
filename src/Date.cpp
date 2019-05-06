/*************************************************************************
                           Date  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) --

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
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = ( const Date & uneDate )
// Algorithme :
//
{
	annee = uneDate.annee;
	mois = uneDate.mois;
	jour = uneDate.jour;
	heure = uneDate.heure;
	minute = uneDate.minute;
	seconde = uneDate.seconde;
} //----- Fin de operator =
bool Date::operator == (const Date &uneDate)
{
	return (annee == uneDate.annee &&
		mois == uneDate.mois &&
		jour == uneDate.jour &&
		heure == uneDate.heure &&
		minute == uneDate.minute &&
		seconde == uneDate.seconde);
}
bool Date::operator != (const Date &uneDate)
{
	return !(operator==(uneDate));
}

bool Date::operator < (const Date &uneDate) 
{
	if (annee < uneDate.annee)
		return true;
	else if (mois < uneDate.mois)
		return true;
	else if (jour < uneDate.jour)
		return true;
	else if (heure < uneDate.heure)
		return true;
	else if (minute < uneDate.minute)
		return true;
	else if (seconde < uneDate.seconde)
		return true;
	else
		return false;

}
bool Date::operator > (const Date &uneDate) 
{
	if (annee > uneDate.annee)
		return true;
	else if (mois > uneDate.mois)
		return true;
	else if (jour > uneDate.jour)
		return true;
	else if (heure > uneDate.heure)
		return true;
	else if (minute > uneDate.minute)
		return true;
	else if (seconde > uneDate.seconde)
		return true;
	else
		return false;
}

bool Date::operator >= (const Date &uneDate)
{
	return !(operator<(uneDate));
}
bool Date::operator <= (const Date &uneDate)
{
	return !(operator>(uneDate));
}

ostream & operator<<(ostream & out, const Date & uneDate)
{
	out << annee << '-' << mois << '-' << jour << 'T' << heure << ':' << minute << ':' << seconde;
	return out;

}

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


