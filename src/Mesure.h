/*************************************************************************
						   Mesure  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier ${file_name}) ------
#if ! defined ( Mesure_H )
#define Mesure_H

//--------------------------------------------------- Interfaces utilis�es
#include "pch.h"
#include <string>
#include <iostream>

#include "Date.h"

using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Mesure>
//
//
//------------------------------------------------------------------------ 

class Mesure
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void setTimestamp(Date s);
	void setSensorID(string s);
	void setAttributeID(string s);
	void setValue(double s);

	Date getTimestamp( );
	string getSensorID( );
	string getAttributeID( );
	double getValue();

	void afficher();
		// type M�thode ( liste de param�tres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	Mesure & operator = (const Mesure & uneMesure);
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	Date timestamp;
	string sensorID;
	string attributeID;
	double value;

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Mesure>

#endif // Mesure_H
