#include "pch.h"
#include "FileReader.h"


void FileReader::openCsvMesure(string chemin)
{
	ifstream file(chemin);
	if (file)
	{
		csvMesure = &file;
	}
	else
	{
		cerr << "Erreur : fichier introuvable" << endl;
	}
}

void FileReader::openCsvCapteur(string chemin)
{
	ifstream file(chemin);
	if (file)
	{
		csvCapteur = &file;
	}
	else
	{
		cerr << "Erreur : fichier introuvable" << endl;
	}
}

void FileReader::openCsvAttribut(string chemin)
{
	ifstream file(chemin);
	if (file)
	{
		csvAttribut = &file;
	}
	else
	{
		cerr << "Erreur : fichier introuvable" << endl;
	}
}

Mesure& FileReader::LireligneMesure(Mesure& uneMesure)
{
	string timestamp;
	string sensorID;
	string attributeID;
	string value;
	getline(*csvMesure, timestamp, ';');
	getline(*csvMesure, sensorID, ';');
	getline(*csvMesure, attributeID, ';');
	getline(*csvMesure, value);

	uneMesure.setTimestamp(timestamp);
	uneMesure.setSensorID(sensorID);
	uneMesure.setAttributeID(attributeID);
	uneMesure.setValue(value);
	return uneMesure;
}
Capteur& FileReader::LireligneCapteur(Capteur& unCapteur)
{
	string sensorID;
	string latitude;
	string longitude;
	string description;
	getline(*csvCapteur, sensorID, ';');
	getline(*csvCapteur, latitude, ';');
	getline(*csvCapteur, longitude, ';');
	getline(*csvCapteur, description);

	unCapteur.setTimestamp(sensorID);
	unCapteur.setSensorID(latitude);
	unCapteur.setAttributeID(longitude);
	unCapteur.setValue(description);
	return unCapteur;
}
Attribut& FileReader::LireligneAttribut(Attribut& unAttribut)
{
	string attributeID;
	string unit;
	string description;

	getline(*csvAttribut, attributeID, ';');
	getline(*csvAttribut, unit, ';');
	getline(*csvAttribut, description);

	unAttribut.setAttributeID(attributeID);
	unAttribut.setUnit(unit);
	unAttribut.setAttributeID(description);
	return unAttribut;
}


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}
