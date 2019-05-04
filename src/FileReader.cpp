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

		uneMesure.setTimestamp(timestamp);
		uneMesure.setSensorID(sensorID);
		uneMesure.setAttributeID(attributeID);
		uneMesure.setValue(value);
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
		unCapteur.setLatitude(latitude);
		unCapteur.setLongitude(longitude);
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


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}
