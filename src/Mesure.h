/*************************************************************************
						   Mesure  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier ${file_name}) ------
#if ! defined ( Mesure_H )
#define Mesure_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>

#include "Date.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------ 

class Mesure
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void setTimestamp(Date s);
	void setSensorID(string s);
	void setAttributeID(string s);
	void setValue(double s);

	void afficher();
		// type Méthode ( liste de paramètres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs
	Mesure & operator = (const Mesure & unMesure);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Mesure(Date unTimestamp, string unSensorID, string unAttributeID, double unValue);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Mesure(const Mesure & unMesure);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	Date timestamp;
	string sensorID;
	string attributeID;
	double value;

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Mesure>

#endif // Mesure_H
