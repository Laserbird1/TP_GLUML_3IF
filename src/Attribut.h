/*************************************************************************
						   Attribut  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier ${file_name}) ------
#if ! defined ( Attribut_H )
#define Attribut_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------ 

class Attribut 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	void setAttributeID(string s);
	void setUnit(string s);
	void setDescription(string s);
	void afficher();
	// type Méthode ( liste de paramètres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs
	bool operator == (const Attribut& a) const;
	bool operator < (const Attribut& a) const;
	Attribut & operator = (const Attribut & unAttribut);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Attribut(const Attribut & unAttribut);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Attribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Attribut();
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
	string attributeID;
	string unit;
	string description;
private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Attribut>

#endif // Attribut_H


