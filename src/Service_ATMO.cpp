/*************************************************************************
						   Service_ATMO  -  description
							 -------------------
	début                : 03/05/2019
	copyright            : (C) 2019 par Edouard de BRYE
*************************************************************************/

//---------- Réalisation de la classe <Service_ATMO> (fichier Service_ATMO) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <time.h>

//------------------------------------------------------ Include personnel
#include "FileReader.h"
#include "Service_ATMO.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Service_ATMO::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Service_ATMO &Service_ATMO::operator = (const Service_ATMO &unService_ATMO)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Service_ATMO::Service_ATMO (const Service_ATMO &unService_ATMO)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Service_ATMO>" << endl;
#endif
} //----- Fin de Service_ATMO (constructeur de copie)


Service_ATMO::Service_ATMO ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Service_ATMO>" << endl;
#endif
} //----- Fin de Service_ATMO


Service_ATMO::~Service_ATMO ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Service_ATMO>" << endl;
#endif
} //----- Fin de ~Service_ATMO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
