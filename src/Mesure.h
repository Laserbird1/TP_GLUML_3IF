/*************************************************************************
						   Mesure  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure) ------
#if ! defined ( Mesure_H )
#define Mesure_H

//--------------------------------------------------- Interfaces utilisées

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

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Mesure>

#endif // Mesure_H
