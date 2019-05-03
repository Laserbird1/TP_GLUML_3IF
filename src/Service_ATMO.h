/*************************************************************************
						   Service_ATMO  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Service_ATMO> (fichier ${file_name}) ------
#if ! defined ( SERVICE_ATMO_H )
#define SERVICE_ATMO_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Service_ATMO>
//
//
//------------------------------------------------------------------------ 

class Service_ATMO 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
		pair<int,string> calculAirQualityCapteur( int attributeID,int sensorID, int R, struct tm ,  );
		// Mode d'emploi :
		//
		// Contrat :
		//


	//------------------------------------------------- Surcharge d'op�rateurs


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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s



private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Service_ATMO>

#endif // SERVICE_ATMO_H
