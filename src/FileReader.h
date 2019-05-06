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
	bool LireligneMesure(Mesure&);
	bool LireligneCapteur(Capteur&);
	bool LireligneAttribut(Attribut&);

	set<Capteur> InitListeCapteurs();
	set<Attribut> InitListeAttributs();

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

