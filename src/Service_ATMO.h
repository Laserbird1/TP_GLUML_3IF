/*************************************************************************
						   Service_ATMO  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Service_ATMO> (fichier ${file_name}) ------
#if ! defined ( SERVICE_ATMO_H )
#define SERVICE_ATMO_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Service_ATMO>
//
//
//------------------------------------------------------------------------ 

class Service_ATMO 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
		pair<int,string> calculAirQualityCapteur( int attributeID,int sensorID, int R, struct tm ,  );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
	Service_ATMO (const Service_ATMO &unService_ATMO);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Service_ATMO ();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Service_ATMO ();
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

//----------------------------------------- Types dépendants de <Service_ATMO>

#endif // SERVICE_ATMO_H
