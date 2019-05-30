
/*************************************************************************
 Controleur  -  Contient toute les methodes
 -------------------
 dÈbut                : 06/05/19
 copyright            : (C) 2019 par ppetrella
 *************************************************************************/

 //---------- RÈalisation de la classe <Controleur> (fichier Controleur) --

 //---------------------------------------------------------------- INCLUDE

 //-------------------------------------------------------- Include systËme
using namespace std;
#include <iostream>
#include "Controleur.h"
#include <list>
#include <set>
#include <string>

//------------------------------------------------------ Include personnel


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe



//----------------------------------------------------------- Types privÈs


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- MÈthodes publiques
// type Controleur::MÈthode ( liste de paramËtres )
// Algorithme :
//
//{
//} //----- Fin de MÈthode



bool Controleur::InitialiserFichiers(string mesure, string attribut, string capteur)
{
	bool b1 = true;
	bool b2 = true;
	bool b3 = true;

	b1 = fileReader.OpenCsvMesure(mesure);
	b2 = fileReader.OpenCsvCapteur(capteur);
	b3 = fileReader.OpenCsvAttribut(attribut);
	if (b2)
	{
		capteurs = this->fileReader.InitListeCapteurs();
	}
	if (b3)
	{
		attributs = this->fileReader.InitListeAttributs();
	}
	return (b1&&b2&&b3);

}
//pierre



//Guilhem
bool Controleur::testCapteurActif(string capteurID, Date t1, Date t2) {
	//Algorithme:
		// Identifiant du capteur,nombre d’heures à analyser

	//Booléen renvoyant True ou False selon le cas où le capteur est actif ou pas. 
	set<Capteur>::iterator it = capteurs.begin();
	bool capteurFonctionnel = false;
	bool capteurTrouve = false;


	Capteur capteurTest;
	Mesure mesureTest;
	fileReader.reinitLectureFichiers();

	while ((it != capteurs.end()) && !capteurTrouve)
	{
		if (((*it).getID()) == capteurID)
		{
			capteurTest = (*it);
			capteurTrouve = true;
		}
		it++;
	}

	if (!capteurTrouve)
	{
		cerr << "Erreur : pas de capteur portant ce nom" << endl;
	}
	else
	{

		while (fileReader.LireLigneMesure(mesureTest) && !capteurFonctionnel)
		{
			if ((mesureTest.getSensorID() == capteurTest.getID()) && (mesureTest.getTimestamp() >= t1) && (mesureTest.getTimestamp() <= t2))
			{
				capteurFonctionnel = true;
			}
		}
	}
	return capteurFonctionnel;

}


//cette methodes est plus utile, a supprimer
//list <Capteur> * Controleur::afficherVoisinsCapteur(string capteurID, float r)
//{
//	list<Capteur> res;
//	Capteur * centerSensor;
//	set<Capteur>::iterator it;
//
//	for (it = capteurs.begin(); it != capteurs.end(); it++)
//	{
//		if (it->getID().compare(capteurID) == 0)
//		{
//			centerSensor = &Capteur(*it);
//			break;
//		}
//	}
//
//	if (it == capteurs.end())
//	{
//		cerr << "mauvais id passé en pramètre de afficherVoisinsCapteur, il n'existe pas" << endl;
//		return list<Capteur>();
//	}
//	else
//	{
//		return afficherVoisinsPoint(centerSensor->getLongitude(), centerSensor->getLatitude, r);
//	}
//}

list<Capteur> * Controleur::afficherVoisinsPoint(double longitude, double latitude, float r)
{
	list<Capteur> * res = new list<Capteur>;
	set<Capteur>::iterator it;
	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		double latTest = it->getLatitude();
		double lngTest = it->getLongitude();
		double x = longitude - latTest;
		double y = latitude - lngTest;

		if (x*x + y * y < r*r)
		{
			res->push_front(*it);
		}
	}
	return res;
}

//list<Capteur> * Controleur::afficherAttributQualiteCapteur(string attributeID, double qualite, int s) {}


//pair<int, string> Controleur::calculAirQualityCapteur(string attributeID, double lat, double lng, double r, Date t1, Date t2) {}

pair <int, int> Controleur::trouverLongitudeLatitude(string capteurID) {
	bool found = false;
	pair<int, int> res;
	for (set<Capteur>::iterator it = capteurs.begin(); it != capteurs.end() && !found; ++it) {
		if (it->getID() == capteurID) {
			found = true;
			res.first = it->getLatitude();
			res.second = it->getLongitude();
		}
	}
	return res;
}

// methodes intermediaires

//
//donne la moyenne sur un interval pour 1 capteur de ses valeurs pour un attribut.
//double Controleur::trouverMoyenneCapteur(string capteurID, string attributID, Date d1, Date d2){}

//
// donne le capteur le plus proche d’un point. mais pas plus loin que r. revoi en nullprt sinon.
//Capteur Controleur::trouverCapteurLePlusProche(double r, double lat, double lng){}

//service 3
//recupère le capteur le plus proche et calcule le qualité moyenne sur l'intervale precisé en ce point
//pair<int, string> Controleur::CalculeQualiteAirEnUnPoint(double lat, double lng, Date d1, Date d2){}




//----------------------------------------------- Methodes de Tests



//-------------------------------------------- Constructeurs - destructeur


Controleur::Controleur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Controleur>" << endl;
#endif
} //----- Fin de Controleur


Controleur::~Controleur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Controleur>" << endl;
#endif
} //----- Fin de ~Controleur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÈthodes protÈgÈes

//------------------------------------------------------- MÈthodes privÈes
