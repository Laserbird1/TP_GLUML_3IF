#pragma once

#include <iostream>
#include <fstream>
#include <string>
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
	
	void openCsvMesure(string chemin);
	void openCsvCapteur(string chemin);
	void openCsvAttribut(string chemin);

	Mesure& LireligneMesure(Mesure&);
	Capteur& LireligneCapteur(Capteur&);
	Attribut& LireligneAttribut(Attribut&);
private:

	ifstream* csvMesure;
	ifstream* csvCapteur;
	ifstream* csvAttribut;
};

