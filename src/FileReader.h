#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Mesure.h"
#include "Capteur.h"
#include "Capteur.h"
#include "Attribut.h"


using namespace std;

class FileReader
{

public:
	FileReader();
	~FileReader();
	
	//Méthodes permettant d'ouvrir les fichiers contenant
	//respectivement les données mesure, capteur et attribut
	bool OpenCsvMesure(string chemin);
	bool OpenCsvCapteur(string chemin);
	bool OpenCsvAttribut(string chemin);

	//Met à jour le paramètre en fonction de la ligne lue
	//Renvoie true si la ligne existe bien, et false si la fin du fichier est atteinte
	bool LireligneMesure(Mesure&);
	bool LireligneCapteur(Capteur&);
	bool LireligneAttribut(Attribut&);

	set<Capteur> InitListeCapteurs();
	set<Attribut> InitListeAttributs();

	//Place le curseur au début de chaque fichier
	void reinitLectureFichiers();

private:

	ifstream csvMesure;
	ifstream csvCapteur;
	ifstream csvAttribut;
};

