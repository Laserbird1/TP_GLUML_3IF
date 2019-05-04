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

private:

	ifstream csvMesure;
	ifstream csvCapteur;
	ifstream csvAttribut;
};

