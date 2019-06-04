
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
#include <Capteur.h>

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
	
	if (b1)
	{
		mesures = this->fileReader.InitListeMesures();
	}
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

void Controleur::reinitialiserLectureFichiers()
{
	fileReader.reinitLectureFichiers();
}

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
		while (fileReader.LireLigneMesure(mesureTest) && (mesureTest.getTimestamp() < t1))
		while (fileReader.LireLigneMesure(mesureTest) && !capteurFonctionnel && (mesureTest.getTimestamp() <= t2))
		{
			if ((mesureTest.getSensorID() == capteurTest.getID()))
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
		double x = longitude - lngTest;
		double y = latitude - latTest;

		if (x*x + y * y < r*r)
		{
			res->push_front(*it);
		}
	}
	return res;
}

//list<Capteur> * Controleur::afficherAttributQualiteCapteur(string attributeID, double qualite, int s) {}


pair<int, string> Controleur::calculAirQualityCapteur(string attributeID, double lat, double lng, double r, Date t1, Date t2)
{
	Mesure mesureTest;
	bool existenceAttribut;
	int compteurMesures = 0;
	double sommeValeurs = 0;
	double moyenne;
	int indiceATMO = -1;
	string description = "Pas de capteur dans cette zone";
	list<Capteur> * capteursVoisins = afficherVoisinsPoint(lng, lat, r);


	if (attributeID != "O3" && attributeID != "SO2" && attributeID != "NO2" && attributeID != "PM10")
	{
		cerr << "Erreur, l'attribut demande n'existe pas" << endl;
	}
	else
	{
		while (fileReader.LireLigneMesure(mesureTest) && mesureTest.getTimestamp() < t1); // On avance dans le fichier jusqu'à trouver le début de la période voulue
		while (fileReader.LireLigneMesure(mesureTest) && mesureTest.getTimestamp() <= t2) //On parcourt le fichier tant que l'on reste dans la périoe voulue
		{
			bool found = false;
			if (mesureTest.getAttributeID() == attributeID)
			{
				for (list<Capteur>::iterator it = capteursVoisins->begin(); it != capteursVoisins->end() && !found; it++)
				{
					if ((*it).getID() == mesureTest.getSensorID())
					{
						found = true;
						++compteurMesures;
						sommeValeurs += mesureTest.getValue();
					}
				}
			}
		}

		if (compteurMesures != 0)
		{
			moyenne = sommeValeurs / (double)compteurMesures;

			if (attributeID == "O3")
			{
				if (0 <= moyenne && moyenne <= 29)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (30 <= moyenne && moyenne <= 54)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (55 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (80 <= moyenne && moyenne <= 104)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (105 <= moyenne && moyenne <= 129)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (130 <= moyenne && moyenne <= 149)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (150 <= moyenne && moyenne <= 179)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (180 <= moyenne && moyenne <= 209)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (210 <= moyenne && moyenne <= 239)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}

			else if (attributeID == "SO2")
			{
				if (0 <= moyenne && moyenne <= 39)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (40 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (80 <= moyenne && moyenne <= 119)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (120 <= moyenne && moyenne <= 159)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (160 <= moyenne && moyenne <= 199)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (200 <= moyenne && moyenne <= 249)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (250 <= moyenne && moyenne <= 299)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (300 <= moyenne && moyenne <= 399)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (400 <= moyenne && moyenne <= 499)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}

			else if (attributeID == "NO2")
			{
				if (0 <= moyenne && moyenne <= 29)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (30 <= moyenne && moyenne <= 54)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (55 <= moyenne && moyenne <= 84)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (85 <= moyenne && moyenne <= 109)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (110 <= moyenne && moyenne <= 134)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (135 <= moyenne && moyenne <= 164)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (165 <= moyenne && moyenne <= 199)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (200 <= moyenne && moyenne <= 274)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (275 <= moyenne && moyenne <= 399)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}

			}

			else if (attributeID == "PM10")
			{
				if (0 <= moyenne && moyenne <= 6)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (7 <= moyenne && moyenne <= 13)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (14 <= moyenne && moyenne <= 20)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (21 <= moyenne && moyenne <= 27)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (28 <= moyenne && moyenne <= 34)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (35 <= moyenne && moyenne <= 41)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (42 <= moyenne && moyenne <= 49)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (50 <= moyenne && moyenne <= 64)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (65 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}
		}
		else
		{
			cout << "Aucune mesure sur cet intervalle" << endl;
		}
	}

	pair<int, string> paire(indiceATMO, description);
	return paire;

}

pair <int, int> Controleur::trouverLongitudeLatitude(string capteurID) {
	bool found = false;
	pair<int, int> res (0,0);
	for (set<Capteur>::iterator it = capteurs.begin(); it != capteurs.end() && !found; ++it) {
		if (it->getID() == capteurID) {
			found = true;
			res.first = it->getLongitude();
			res.second = it->getLatitude();
		}
	}
	if (!found)
	{
		cerr << "Erreur, le capteur specifie est introuvable" << endl;
	}
	return res;
}

// methodes intermediaires
//Joël

//
//donne la moyenne sur un interval pour 1 capteur de ses valeurs pour un attribut.
double Controleur::trouverMoyenneCapteur(string capteurID, string attributID, Date d1, Date d2){
	list<Mesure> * res = new list<Mesure>;
	set<Mesure>::iterator it;
	int compteurMesures = 0;
	double moyenneMesures, sommeMesures = 0;
	for (it = mesures.begin(); it != mesures.end(); it++)
	{
		if (it->getSensorID() == capteurID && it->getAttributeID() == attributID && (it->getTimestamp() < d1) && (it->getTimestamp() <= d2)
			res->push_front(*it); 
			sommeMesures +=it->getValue();
			compteurMesures++;
	}

	moyenneMesures = sommeMesures /(float) compteurMesures;

	return moyenneMesures;

}

//
// donne le capteur le plus proche d’un point. mais pas plus loin que r. revoi en nullprt sinon.
Capteur Controleur::trouverCapteurLePlusProche(double r, double lat, double lng){

	Capteur CapteurLePlusProche;
	set<Capteur>::iterator it;
	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		double latTest = it->getLatitude();
		double lngTest = it->getLongitude();
		double x = lng - lngTest;
		double y = lat - latTest;
		double min=INT_MAX
		

		if (x*x + y*y<min)
		{
			min = x * x + y * y;
			CapteurLePlusProche=(*it);
		}
	}
	return CapteurLePlusProche;
}

pair<int, int> Controleur::calculAirQualityCapteur2(string attributeID,string capteurID double lat, double lng, double r, Date t1, Date t2)
{
	Mesure mesureTest;
	bool existenceAttribut;
	int compteurMesures = 0;
	double sommeValeurs = 0;
	double moyenne;
	int indiceATMO = -1;
	string description = "Pas de capteur dans cette zone";
	list<Capteur> * capteursVoisins = afficherVoisinsPoint(lng, lat, r);


	if (attributeID != "O3" && attributeID != "SO2" && attributeID != "NO2" && attributeID != "PM10")
	{
		cerr << "Erreur, l'attribut demande n'existe pas" << endl;
	}
	else
	{
		while (fileReader.LireLigneMesure(mesureTest) && mesureTest.getTimestamp() < t1); // On avance dans le fichier jusqu'à trouver le début de la période voulue
		while (fileReader.LireLigneMesure(mesureTest) && mesureTest.getTimestamp() <= t2) //On parcourt le fichier tant que l'on reste dans la périoe voulue
		{
			bool found = false;
			if (mesureTest.getAttributeID() == attributeID)
			{
				for (list<Capteur>::iterator it = capteursVoisins->begin(); it != capteursVoisins->end() && !found; it++)
				{
					if ((*it).getID() == capteurID)
					{
						found = true;
						++compteurMesures;
						sommeValeurs += mesureTest.getValue();
					}
				}
			}
		}

		if (compteurMesures != 0)
		{
			moyenne = sommeValeurs / (double)compteurMesures;

			if (attributeID == "O3")
			{
				if (0 <= moyenne && moyenne <= 29)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (30 <= moyenne && moyenne <= 54)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (55 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (80 <= moyenne && moyenne <= 104)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (105 <= moyenne && moyenne <= 129)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (130 <= moyenne && moyenne <= 149)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (150 <= moyenne && moyenne <= 179)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (180 <= moyenne && moyenne <= 209)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (210 <= moyenne && moyenne <= 239)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}

			else if (attributeID == "SO2")
			{
				if (0 <= moyenne && moyenne <= 39)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (40 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (80 <= moyenne && moyenne <= 119)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (120 <= moyenne && moyenne <= 159)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (160 <= moyenne && moyenne <= 199)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (200 <= moyenne && moyenne <= 249)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (250 <= moyenne && moyenne <= 299)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (300 <= moyenne && moyenne <= 399)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (400 <= moyenne && moyenne <= 499)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}

			else if (attributeID == "NO2")
			{
				if (0 <= moyenne && moyenne <= 29)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (30 <= moyenne && moyenne <= 54)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (55 <= moyenne && moyenne <= 84)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (85 <= moyenne && moyenne <= 109)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (110 <= moyenne && moyenne <= 134)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (135 <= moyenne && moyenne <= 164)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (165 <= moyenne && moyenne <= 199)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (200 <= moyenne && moyenne <= 274)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (275 <= moyenne && moyenne <= 399)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}

			}

			else if (attributeID == "PM10")
			{
				if (0 <= moyenne && moyenne <= 6)
				{
					indiceATMO = 1;
					description = "Tres bon";
				}
				else if (7 <= moyenne && moyenne <= 13)
				{
					indiceATMO = 2;
					description = "Tres bon";
				}
				else if (14 <= moyenne && moyenne <= 20)
				{
					indiceATMO = 3;
					description = "Bon";
				}
				else if (21 <= moyenne && moyenne <= 27)
				{
					indiceATMO = 4;
					description = "Bon";
				}
				else if (28 <= moyenne && moyenne <= 34)
				{
					indiceATMO = 5;
					description = "Moyen";
				}
				else if (35 <= moyenne && moyenne <= 41)
				{
					indiceATMO = 6;
					description = "Mediocre";
				}
				else if (42 <= moyenne && moyenne <= 49)
				{
					indiceATMO = 7;
					description = "Mediocre";
				}
				else if (50 <= moyenne && moyenne <= 64)
				{
					indiceATMO = 8;
					description = "Mauvais";
				}
				else if (65 <= moyenne && moyenne <= 79)
				{
					indiceATMO = 9;
					description = "Mauvais";
				}
				else
				{
					indiceATMO = 10;
					description = "Très mauvais";
				}
			}
		}
		else
		{
			cout << "Aucune mesure sur cet intervalle" << endl;
		}
	}

	pair<int, int> paire(moyenne, indiceATMO);

}


}

//service 3
//recupère le capteur le plus proche et calcule le qualité moyenne sur l'intervale precisé en ce point
int Controleur::CalculeQualiteAirEnUnPoint(double lat, double lng, Date d1, Date d2){

	int indiceAtmo;
	Capteur CapteurLePlusProche = trouverCapteurLePlusProche(double r, double lat, double lng);
	double  indiceAtmoO3CapteurLePlusProche = calculAirQualityCapteur2(O3, CapteurLePlusProche.getID(), lat,  lng,  r, d1, d2).first;
	double  indiceAtmoNO2CapteurLePlusProche = calculAirQualityCapteur2(NO2, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).first;
	double  indiceAtmoSO2CapteurLePlusProche = calculAirQualityCapteur2(SO2, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).first);
	double  indiceAtmoPM10CapteurLePlusProche = calculAirQualityCapteur2(PM10, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).first;

	if ((indiceAtmoO3CapteurLePlusProche = > indiceAtmoNO2CapteurLePlusProche) && (indiceAtmoO3CapteurLePlusProche = > indiceAtmoPM10CapteurLePlusProche) &&
		(indiceAtmoO3CapteurLePlusProche = > indiceAtmoSO2CapteurLePlusProche))
	{
		indiceAtmo = calculAirQualityCapteur2(O3, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).second;
	}

	if ((indiceAtmoNO2CapteurLePlusProche = > indiceAtmoO3CapteurLePlusProche) && (indiceAtmoNO2CapteurLePlusProche = > indiceAtmoPM10CapteurLePlusProche) &&
		(indiceAtmoNO2CapteurLePlusProche = > indiceAtmoPM10CapteurLePlusProche))
	{
		indiceAtmo = calculAirQualityCapteur2(NO2, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).second;
	}

	if ((indiceAtmoSO2CapteurLePlusProche = > indiceAtmoO3CapteurLePlusProche) && (indiceAtmoSO2CapteurLePlusProche = > indiceAtmoNO2CapteurLePlusProche) &&
		(indiceAtmoSO2CapteurLePlusProche = > indiceAtmoPM10CapteurLePlusProche))
	{
		indiceAtmo = calculAirQualityCapteur2(SO2, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).second;
	}

	if ((indiceAtmoPM10CapteurLePlusProche = > indiceAtmoO3CapteurLePlusProche) && (indiceAtmoPM10CapteurLePlusProche = > indiceAtmoNO2CapteurLePlusProche) &&
		(indiceAtmoPM10CapteurLePlusProche = > indiceAtmoPM10CapteurLePlusProche))
	{
		indiceAtmo = calculAirQualityCapteur2(PM10, CapteurLePlusProche.getID(), lat, lng, r, d1, d2).second;
	}

	return indiceAtmo;

}




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
