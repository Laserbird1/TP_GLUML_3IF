/*************************************************************************
						   Service_ATMO  -  description
							 -------------------
	d�but                : 03/05/2019
	copyright            : (C) 2019 par Edouard de BRYE
*************************************************************************/

//---------- R�alisation de la classe <Service_ATMO> (fichier Service_ATMO) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <time.h>

//------------------------------------------------------ Include personnel
#include "FileReader.h"
#include "Service_ATMO.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Service_ATMO::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
