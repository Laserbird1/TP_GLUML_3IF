/*************************************************************************
						   Capteur  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#if ! defined ( Capteur_H )
#define Capteur_H

//--------------------------------------------------- Interfaces utilis�es
#include "pch.h"
#include <string>
#include <iostream>

using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Capteur>
//
//
//------------------------------------------------------------------------ 

class Capteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void setSensorID(string s);
	void setLatitude(double s);
	void setLongitude(double s);
	void setDescription(string s);
	void afficher() const;
		// type M�thode ( liste de param�tres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	bool operator == (const Capteur& c) const;
	bool operator < (const Capteur&c) const;
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur

	Capteur(const Capteur & unCapteur);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Capteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Capteur();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	string sensorID;
	double latitude;
	double longitude;
	string description;

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Capteur>

#endif // Capteur_H


