/*************************************************************************
						   Date  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ------
#if ! defined ( DATE_H )
#define DATE_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Date>
//
//
//------------------------------------------------------------------------ 

class Date
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
		// type M�thode ( liste de param�tres );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs
	Date &operator = (const Date &uneDate);
	bool operator == (const Date &uneDate);
	bool operator !=(const Date &uneDate);
	bool operator < (const Date &uneDate) ;
	bool operator > (const Date &uneDate) ;
	bool operator <=(const Date &uneDate);
	bool operator >=(const Date &uneDate);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Date (const Date & uneDate);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Date(int a = 0, int mo = 0, int j = 0, int h = 0, int mi = 0, int s = 0);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Date ();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es



	//----------------------------------------------------- Attributs prot�g�s

	int annee;
	int mois;
	int jour;
	int heure;
	int minute;
	int seconde;

};


#endif // DATE_H