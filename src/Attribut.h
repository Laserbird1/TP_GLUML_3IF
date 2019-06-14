/*************************************************************************
						   Attribut  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier ${file_name}) ------
#if ! defined ( Attribut_H )
#define Attribut_H

//--------------------------------------------------- Interfaces utilis�es

#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Attribut>
//
//
//------------------------------------------------------------------------ 

class Attribut 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	void setAttributeID(string s);
	string getAttributeID() const;
	void setUnit(string s);
	void setDescription(string s);
	void afficher() const;
	// type M�thode ( liste de param�tres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	bool operator == (const Attribut& a) const;
	bool operator < (const Attribut& a) const;
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
	//----------------------------------------------------- M�thodes prot�g�es

	string attributeID;
	string unit;
	string description;

private:
	//------------------------------------------------------- M�thodes priv�es

	//----------------------------------------------------- Attributs prot�g�s

	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Attribut>

#endif // Attribut_H


