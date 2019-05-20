/*************************************************************************
						   Date  -  description
							 -------------------
	début                : ${date}
	copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <FileReader> (fichier FileReader.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

#include "pch.h"
#include "FileReader.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// Algorithme :
//
//{
//} //----- Fin de Méthode
// ouvre le fichier correspondant
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
	else
	{
		string description;
		getline(csvMesure, description);
	}
	return ouvertureReussie;
}//----- Fin de OpenCsvMesure


// ouvre le fichier correspondant
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
	else
	{
		string description;
		getline(csvCapteur, description);
	}
	return ouvertureReussie;
}//----- Fin de OpenCsvCapteur

// ouvre le fichier correspondant
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
	else
	{
		string description;
		getline(csvAttribut, description);
	}
	return ouvertureReussie;
}//----- Fin de OpenCsvAttribut



bool FileReader::LireLigneMesure(Mesure& uneMesure)
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
}//----- Fin de LireLigneMesure

bool FileReader::LireLigneCapteur(Capteur& unCapteur)
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
}//----- Fin de LireLigneCapteur

bool FileReader::LireLigneAttribut(Attribut& unAttribut)
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
}//----- Fin de LireLigneAttribut

set<Capteur> FileReader::InitListeCapteurs()
{
	set<Capteur> liste;
	Capteur unCapteur;

	while (LireLigneCapteur(unCapteur))
	{
		liste.insert(unCapteur);
	}
	return liste;
}//----- Fin de InitListeCapteurs

set<Attribut> FileReader::InitListeAttributs()
{
	set<Attribut> liste;
	Attribut unAttribut;

	while (LireLigneAttribut(unAttribut))
	{
		liste.insert(unAttribut);
	}
	return liste;
}//----- Fin de InitListeAttributs

void FileReader::reinitLectureFichiers()
{
	string descriptions; //chaine à retirer lors des manipulations de fichiers
	csvMesure.seekg(0, ios::beg);
	csvCapteur.seekg(0, ios::beg);
	csvAttribut.seekg(0, ios::beg);

	getline(csvMesure, descriptions);
	getline(csvCapteur, descriptions);
	getline(csvAttribut, descriptions);

}//----- Fin de reinitLectureFichiers

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

FileReader::FileReader()
{
}//----- Fin de FileReader

FileReader::~FileReader()
{
}//----- Fin de ~FileReader

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

Date FileReader::convertStringToDate(string s)
{
	int annee = stoi(s.substr(0, 4));
	int mois = stoi(s.substr(5, 2));
	int jour = stoi(s.substr(8, 2));
	int heure = stoi(s.substr(11, 2));
	int minute = stoi(s.substr(14, 2));
	int seconde = stoi(s.substr(17, 2));

	Date d(annee, mois, jour, heure, minute, seconde);
	return d;

	//2017-01-01T00:01:20.6090000
}//----- Fin de convertStringToDate
