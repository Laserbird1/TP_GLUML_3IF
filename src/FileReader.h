/*************************************************************************
						   Attribut  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <FileReader> (fichier FileReader.h) ------
#if ! defined ( FILEREADER_H )
#define FILEREADER_H

//--------------------------------------------------- Interfaces utilisées

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
// Rôle de la classe <FileReader>
//
//
//------------------------------------------------------------------------ 

class FileReader
{

	//----------------------------------------------------------------- PUBLIC

public:
	
	//----------------------------------------------------- Méthodes publiques

	//Méthodes permettant d'ouvrir les fichiers contenant
	//respectivement les données mesure, capteur et attribut
	bool OpenCsvMesure(string chemin);
	bool OpenCsvCapteur(string chemin);
	bool OpenCsvAttribut(string chemin);

	//Met à jour le paramètre en fonction de la ligne lue
	//Renvoie true si la ligne existe bien, et false si la fin du fichier est atteinte
	bool LireLigneMesure(Mesure&);
	bool LireLigneCapteur(Capteur&);
	bool LireLigneAttribut(Attribut&);

	set<Capteur> InitListeCapteurs();
	set<Attribut> InitListeAttributs();

	//Place le curseur au début de chaque fichier
	void reinitLectureFichiers();

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	FileReader();
	~FileReader();
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

private:

	//------------------------------------------------------- Méthodes privées

	Date convertStringToDate(string s);

	//------------------------------------------------------- Attributs privés

	ifstream csvMesure;
	ifstream csvCapteur;
	ifstream csvAttribut;
};

#endif //FILEREADER_H
