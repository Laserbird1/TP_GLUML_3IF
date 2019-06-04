/*************************************************************************
						   Attribut  -  description
							 -------------------
	d�but                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <FileReader> (fichier FileReader.h) ------
#if ! defined ( FILEREADER_H )
#define FILEREADER_H

//--------------------------------------------------- Interfaces utilis�es

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <list>
#include "Mesure.h"
#include "Capteur.h"
#include "Capteur.h"
#include "Attribut.h"
#include "Date.h"


using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <FileReader>
//
//
//------------------------------------------------------------------------ 

class FileReader
{

	//----------------------------------------------------------------- PUBLIC

public:
	
	//----------------------------------------------------- M�thodes publiques

	//M�thodes permettant d'ouvrir les fichiers contenant
	//respectivement les donn�es mesure, capteur et attribut
	bool OpenCsvMesure(string chemin);
	bool OpenCsvCapteur(string chemin);
	bool OpenCsvAttribut(string chemin);

	//Met � jour le param�tre en fonction de la ligne lue
	//Renvoie true si la ligne existe bien, et false si la fin du fichier est atteinte
	bool LireLigneMesure(Mesure&);
	bool LireLigneCapteur(Capteur&);
	bool LireLigneAttribut(Attribut&);

	set<Capteur> InitListeCapteurs();
	set<Attribut> InitListeAttributs();
	set<Mesure> InitListeMesures();


	list<Date> getDatesLimites();
	//contrat : fichier de mesure déjà ouvert, tête de lecture en en-tête
	//remet la tête de lecture en place à la fin
	//première date = date de début
	//seconde date = date de fin

	//Place le curseur au d�but de chaque fichier
	void reinitLectureFichiers();

	//------------------------------------------------- Surcharge d'op�rateurs


	//-------------------------------------------- Constructeurs - destructeur
	
	FileReader();
	~FileReader();
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

private:

	//------------------------------------------------------- M�thodes priv�es

	Date convertStringToDate(string s);

	//------------------------------------------------------- Attributs priv�s

	ifstream csvMesure;
	ifstream csvCapteur;
	ifstream csvAttribut;
};

#endif //FILEREADER_H
