#include "pch.h"
#include "FileReader.h"


bool FileReader::OpenCsvMesure(string chemin)
{
	bool ouvertureReussie = true;
	if (csvMesure.is_open())
	{
		csvMesure.close();
	}
	csvMesure.open(chemin);
	if (!csvMesure)
	{
		cerr << "Erreur lors de l'ouverture, réessayer" << endl;
		ouvertureReussie = false;
	}
	return ouvertureReussie;
}

bool FileReader::OpenCsvCapteur(string chemin)
{
	bool ouvertureReussie = true;
	if (csvCapteur.is_open())
	{
		csvCapteur.close();
	}
	csvCapteur.open(chemin);
	if (!csvCapteur)
	{
		cerr << "Erreur lors de l'ouverture, réessayer" << endl;
		ouvertureReussie = false;
	}
	return ouvertureReussie;
}

bool FileReader::OpenCsvAttribut(string chemin)
{
	bool ouvertureReussie = true;
	if (csvAttribut.is_open())
	{
		csvAttribut.close();
	}
	csvAttribut.open(chemin);
	if (!csvAttribut)
	{
		cerr << "Erreur lors de l'ouverture, réessayer" << endl;
		ouvertureReussie = false;
	}
	return ouvertureReussie;
}

bool FileReader::LireligneMesure(Mesure& uneMesure)
{
	bool lectureReussie = true;
	string timestamp;
	string sensorID;
	string attributeID;
	string value;
	if (csvMesure.eof())
	{
		lectureReussie = false;
	}
	else
	{
		getline(csvMesure, timestamp, ';');
		getline(csvMesure, sensorID, ';');
		getline(csvMesure, attributeID, ';');
		getline(csvMesure, value, ';');
		csvMesure.ignore();

		Date date = convertStringToDate(timestamp);
		double valueDouble = stod(value);

		uneMesure.setTimestamp(date);
		uneMesure.setSensorID(sensorID);
		uneMesure.setAttributeID(attributeID);
		uneMesure.setValue(valueDouble);
	}

	return lectureReussie;
}

bool FileReader::LireligneCapteur(Capteur& unCapteur)
{
	bool lectureReussie = true;
	string sensorID;
	string latitude;
	string longitude;
	string description;

	if (csvCapteur.eof())
	{
		lectureReussie = false;
	}
	else
	{
		getline(csvCapteur, sensorID, ';');
		getline(csvCapteur, latitude, ';');
		getline(csvCapteur, longitude, ';');
		getline(csvCapteur, description, ';');
		csvCapteur.ignore();

		unCapteur.setSensorID(sensorID);
		unCapteur.setLatitude(stod(latitude));
		unCapteur.setLongitude(stod(longitude));
		unCapteur.setDescription(description);
	}
	return lectureReussie;
}

bool FileReader::LireligneAttribut(Attribut& unAttribut)
{
	bool lectureReussie = true;
	string attributeID;
	string unit;
	string description;

	if (csvAttribut.eof())
	{
		lectureReussie = false;
	}
	else
	{
		getline(csvAttribut, attributeID, ';');
		getline(csvAttribut, unit, ';');
		getline(csvAttribut, description, ';');
		csvAttribut.ignore();

		unAttribut.setAttributeID(attributeID);
		unAttribut.setUnit(unit);
		unAttribut.setDescription(description);
	}
	return lectureReussie;
}

set<Capteur> FileReader::InitListeCapteurs()
{
	set<Capteur> liste;
	Capteur unCapteur;

	while (LireligneCapteur(unCapteur))
	{
		liste.insert(unCapteur);
	}
	return liste;
}

void FileReader::reinitLectureFichiers()
{
	csvMesure.seekg(0, ios::beg);
	csvCapteur.seekg(0, ios::beg);
	csvAttribut.seekg(0, ios::beg);
}

Date FileReader::convertStringToDate(string s)
{
	int annee = stoi(substr(0, 4));
	int mois=stoi(substr(5, 2));
	int jour = stoi(substr(8, 2));
	int heure = stoi(substr(11,2));
	int minute = stoi(substr(14, 2));
	int seconde = stoi(substr(17, 2));

	Date d(annee, mois, jour, heure, minute, seconde);
	return d;

	//2017-01-01T00:01:20.6090000
}


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}
