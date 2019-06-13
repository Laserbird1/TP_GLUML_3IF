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
#include <map>
#include <string>
#include <algorithm>    // std::max
#include <math.h>
#include "Capteur.h"

//------------------------------------------------------ Include personnel


//------------------------------------------------------------- Constantes
#define pi 3.14159265358979323846
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



bool Controleur::initialiserFichiers(string mesure, string attribut, string capteur)
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

		while (fileReader.LireLigneMesure(mesureTest) && (mesureTest.getTimestamp() < t1));
		bool finFichier = false;
		while (!finFichier && !capteurFonctionnel && (mesureTest.getTimestamp() <= t2))
		{
			if ((mesureTest.getSensorID() == capteurTest.getID()))
			{
				capteurFonctionnel = true;
			}
			finFichier = !fileReader.LireLigneMesure(mesureTest);
		}
	}
	return capteurFonctionnel;

}


list<Capteur> * Controleur::afficherVoisinsPoint(double longitude, double latitude, float r)
{
	list<Capteur> * res = new list<Capteur>;
	set<Capteur>::iterator it;
	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		double latTest = it->getLatitude();
		double lngTest = it->getLongitude();

		if (CalculerDistance(latitude,longitude,latTest,lngTest)<r)
		{
			res->push_front(*it);
		}
	}
	return res;
}

//s est le resultat l'indice de qualite de l'air attendu
list<Capteur> * Controleur::afficherAttributQualiteCapteur1(string attributeID, int s, Date t1, Date t2)
{
	list<Capteur> * res = new list<Capteur>;
	set<Mesure>::iterator it = mesures.begin();
	set<Capteur>::iterator itc = capteurs.begin();
	bool mesureTrouve = false;
	Mesure mesureTest;
	fileReader.reinitLectureFichiers();

	while ((it != mesures.end()) && !mesureTrouve)
	{
		if (((*it).getAttributeID()) == attributeID)
			{
				mesureTest = (*it);
				mesureTrouve = true;
			}
			it++;
		
	}

	if (!mesureTrouve)
	{
		cerr << "Erreur : pas de mesure de cet attribut" << endl;
	}
	else
	{
		while ((itc != capteurs.end()) && !mesureTrouve) {

			while (fileReader.LireLigneMesure(mesureTest) && (mesureTest.getTimestamp() < t1));
			bool finFichier = false;
			while (!finFichier && (mesureTest.getTimestamp() <= t2))
			{
				if ((mesureTest.getSensorID() == (*itc).getID()) && ((calculAirQualityCapteur(attributeID, (*itc).getLatitude(), (*itc).getLongitude(), 50,  t1, t2).first)==s))
				{
					res->push_front(*itc);
				}
				finFichier = !fileReader.LireLigneMesure(mesureTest);
			}
			itc++;
		}
	}
	return res;

}

	

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


	if ("O3" && attributeID != "SO2" && attributeID != "NO2" && attributeID != "PM10")
	{
		description = "L'attribut demande n'existe pas";
	}
	else
	{
		while (fileReader.LireLigneMesure(mesureTest) && mesureTest.getTimestamp() < t1); // On avance dans le fichier jusqu'à trouver le début de la période voulue
		bool finFichier = false;
		while (!finFichier && mesureTest.getTimestamp() <= t2) //On parcourt le fichier tant que l'on reste dans la périoe voulue
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
			finFichier = !fileReader.LireLigneMesure(mesureTest);
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

pair <double, double> Controleur::trouverLongitudeLatitude(string capteurID) {
	bool found = false;

	pair<double, double> res (0,0);
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

//
//donne la moyenne sur un interval pour 1 capteur de ses valeurs pour un attribut.
double Controleur::trouverMoyenneCapteur(string capteurID, string attributID, Date d1, Date d2) {

	set<Mesure>::iterator it;
	int compteurMesures = 0;
	double moyenneMesures, sommeMesures = 0;
	for (it = mesures.begin(); it != mesures.end(); it++)
	{
		if (((*it).getSensorID == capteurID) && ((*it).getAttributeID== attributID) && ((*it).getTimestamp < d1) && ((*it).getTimestamp <= d2)) {
			sommeMesures += (*it).getValue;
			compteurMesures++;
		}
	}

	moyenneMesures = sommeMesures / (float)compteurMesures;
    return moyenneMesures;

}

	
float CalculerDistance(double lat1, double lng1, double lat2, int lng2) {
	lat1 = toRadians(lat1);
	lng1 = toRadians(lng1);
	lat2 = toRadians(lat2);
	lng2 = toRadians(lng2);

	// Haversine Formula 
	long double dlng = lng2 - lng1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
		cos(lat1) * cos(lat2) *
		pow(sin(dlng / 2), 2);

	ans = 2 * asin(sqrt(ans));

	long double R = 6371;

	ans = ans * R;

	return ans;
}

double toRadians(double deg) {
	return (deg * pi / 180);
}

//
// donne le capteur le plus proche d’un point. mais pas plus loin que r. revoi en nullprt sinon.
Capteur Controleur::trouverCapteurLePlusProche(double r, double lat, double lng) {
	float DistanceMin = r;
	float x;
	float y;
	float dist;
	string IDMin;
	Capteur PlusProche;
	for (set<Capteur>::iterator it = capteurs.begin(); it != capteurs.end(); ++it) {
		x = it->getLatitude();
		y = it->getLongitude();
		dist = CalculerDistance(lat, lng, x, y);
		if (dist < DistanceMin) {
			DistanceMin = dist;
			IDMin = it->getID();
			PlusProche = *it;
		}
	}

	return PlusProche;
}

//service 3
//recupère le capteur le plus proche et calcule le qualité moyenne sur l'intervale precisé en ce point

pair<int, string> Controleur::calculeQualiteAirEnUnPoint(double lat, double lng, Date d1, Date d2){

	//on met r tres grand car ici il n'est pas relevant
	Capteur CProche = trouverCapteurLePlusProche(50, lat, lng);
	pair <int, int> LocCP = trouverLongitudeLatitude(CProche.getID());
	std::set<std::string> attributes;

	attributes.insert("O3");
	attributes.insert("SO2");
	attributes.insert("NO2");
	attributes.insert("PM10");
	//on met rayon 1 car on veut les valeurs que dans ce point donc ceci evite que la fonction suivante face la moyenne de plusiquers capteurs autour 
	pair<int, string> attO3 = calculAirQualityCapteur("O3", LocCP.second, LocCP.first, 1, d1, d2);
	pair<int, string> attSO2 = calculAirQualityCapteur("SO2", LocCP.second, LocCP.first, 1, d1, d2);
	pair<int, string> attNO2 = calculAirQualityCapteur("NO2", LocCP.second, LocCP.first, 1, d1, d2);
	pair<int, string> attPM10 = calculAirQualityCapteur("PM10", LocCP.second, LocCP.first, 1, d1, d2);

	
	int indiceATMO = max(attO3.first , attNO2.first);
	indiceATMO = max(indiceATMO, attPM10.first);
	indiceATMO = max(indiceATMO,attSO2.first);


	string description;
	if (indiceATMO == 1 || indiceATMO == 2) {
		description = "Très Bon";
	}
	if (indiceATMO == 3 || indiceATMO == 4) {
		description = "Bon";
	}
	if (indiceATMO == 5) {
		description = "Moyen";
	}
	if (indiceATMO == 6 || indiceATMO == 7) {
		description = "Mediocre";
	}
	if (indiceATMO == 8 || indiceATMO == 9) {
		description = "Mauvais";
	}
	if (indiceATMO == 10) {
		description = "Très Mauvais";
	}

	pair<int, string> paire(indiceATMO, description);

	return paire;


}


//----------------------------------------------- Methodes de Tests

bool Controleur::testInitFichier(){
	return !initialiserFichiers("mesures inexistantes","attributs inexistants","capteurs inexistants");
}

bool Controleur::testActivite(){
	bool res = true;
	Date debut = Date(2017,1,1,0,0,0);
	Date fin = Date(2017,1,3,0,0,0);
	if(!testCapteurActif("Sensor0",debut,fin)) res=false;
	if(testCapteurActif("Sensor15",debut,fin)) res=false;
	debut = Date(2015,1,1,2,2,2);
	fin = Date(2016,2,3,1,1,1);
	if(testCapteurActif("Sensor0",debut,fin)) res = false;
	return res;
}

bool Controleur::testAfficherVoisins(){
	pair<double, double> coord = trouverLongitudeLatitude("Sensor0");
	list<Capteur> * voisins = afficherVoisinsPoint(coord.first,coord.second,26.5);
	bool zeroFound = false;
	bool oneFound = false;
	bool twoFound = false;
	bool error = false;
	for (list<Capteur>::iterator it = voisins->begin(); it != voisins->end() && !error ; ++it) {
		if(it->getID() == "Sensor0" ){
			error = !zeroFound;
			zeroFound = true;
		}else
			if(it->getID() == "Sensor1") {
				error = !oneFound;
				oneFound = true;
			}else
				if(it->getID() == "Sensor2" ){
					error = !twoFound;
					twoFound = true;
				}else
					error = true;
	}
	return !error;
}


bool Controleur::testTrouverLongLat(){
	//coordonnes pour senseur 0
	pair<double,double> correct (-35.2425725968753,19.4789835505555);
	pair<double,double> testData = trouverLongitudeLatitude("Sensor0");
	return correct.first == testData.first && correct.second == testData.second;
}

bool Controleur::testCapteurPlusProchePoint(){
	//on lui donne les coordonnes du sensor 0
	Capteur aux = trouverCapteurLePlusProche(1,  19.4789835505555,-35.2425725968753);
	return aux.getID().compare("Sensor0") == 0;
}

bool Controleur::testCalculeQualAirePoint(){
	Date debut = Date(2017,1,1,1,20,0);
	Date fin = Date(2017,1,1,1,21,0);
	//on calcule avec un rayon de 1 autour de sensor 0
	pair<int, string> resTest = calculAirQualityCapteur("O3", 19.4789835505555, -35.2425725968753, 1, debut, fin);
	return resTest.first == 1;
}

bool Controleur::testCalculeAireQualityCapteur(){
	Date debut = Date(2017,1,1,1,20,0);
	Date fin = Date(2017,1,1,1,21,0);
	//on calcule avec un rayon de 1 autour de sensor 0
	pair<int, string> resTest = calculAirQualityCapteur("O3", 19.4789835505555, -35.2425725968753, 1, debut, fin);
	return resTest.first == 1;
}

bool Controleur::testCalculeQualiteAirEnUnPoint(){
	Date debut = Date(2017,1,1,1,20,0);
	Date fin = Date(2017,1,1,1,21,0);
	//on met les coords du sensor 0
	pair<int, string> testRes = calculeQualiteAirEnUnPoint(19.4789835505555, -35.2425725968753,debut, fin);
	//on attend un 2
	return testRes.first == 2;
}

bool Controleur::testAfficherAttQualCapteur(){
	Date debut = Date(2017,2,4,2,31,22);
	Date fin = Date(2017,2,4,3,1,14);
	list<Capteur> * resTest = afficherAttributQualiteCapteur1("O3", 7, debut, fin);
	//on veut avoir les capteurs avec indice 7 et 2
	int found = 0;
	for (list<Capteur>::iterator it = resTest->begin(); it != resTest->end() && found < 2; it++){
		if(it->getID().compare("Sensor7") == 0){
			found = 1;
		}else 
			if(it->getID().compare("Sensor2") == 0){
				found = 2;
			}else
				return false;
	}
	return true;
}

void Controleur::lancerTests(){
	int nombreTestsCorrects = 0;
	int nombreTests = 9;

	if(testInitFichier()) nombreTestsCorrects++;
	
	if(testActivite()) nombreTestsCorrects++;

	if(testAfficherVoisins()) nombreTestsCorrects++;

	if(testCapteurPlusProchePoint()) nombreTestsCorrects++;

	if (testTrouverLongLat() )nombreTestsCorrects++;

	if  (testCalculeQualAirePoint()) nombreTestsCorrects++;

	if (testCalculeAireQualityCapteur()) nombreTestsCorrects++;

	if (testCalculeQualiteAirEnUnPoint()) nombreTestsCorrects++;

	if (testAfficherAttQualCapteur()) nombreTestsCorrects++;
	
	cout<< "Vous avez reussi " << nombreTestsCorrects << "sur " << nombreTests <<endl;
}



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