/*************************************************************************
						   Capteur  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ------
#if ! defined ( Capteur_H )
#define Capteur_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------ 

class Capteur
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void setSensorID(string s);
	void setLatitude(float s);
	void setLongitude(float s);
	void setDescription(string s);
	void afficher() const;
		// type Méthode ( liste de paramètres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs
	bool operator == (const Capteur& c) const;
	bool operator < (const Capteur&c) const;
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Capteur(string unSensorID, float uneLatitude, float uneLongitude, string uneDescription);

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
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	string sensorID;
	float latitude;
	float longitude;
	string description;

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Capteur>

#endif // Capteur_H


