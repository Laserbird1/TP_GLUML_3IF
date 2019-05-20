
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
#include <cmath>

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

//pierre

void Controleur::InitialiserFichiers(FileReader fileReader)
{   this->fileReader = fileReader;
    capteurs = this->fileReader.InitListeCapteurs();
    attributs = this->fileReader.InitListeAttributs(); 
}
//pierre


//Guilhem
bool Controleur::testCapteurActif(string capteurID, Date t1, Date t2) {
	//Algorithme:
		// Identifiant du capteur,nombre d’heures à analyser

	//Booléen renvoyant True ou False selon le cas où le capteur est actif ou pas. 

	set<Capteur> capteurs;
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
	}

	if (capteurTrouve)
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
//Guilhem

bool Controleur::verifCapteur(string capteurID,float p,float t,float s){}

list <Capteur> Controleur::afficherVoisinsCapteur(string capteurID,float r)
{
	list<Capteur> res;
	Capteur * centerSensor;
	set<Capteur>::iterator it;

	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		if (it->getID().compare(capteurID)==0)
		{
			centerSensor = &Capteur(*it);
			break;
		}
	}

	if (it == capteurs.end())
	{
		cerr << "mauvais id passé en pramètre de afficherVoisinsCapteur, il n'existe pas"<<endl;
		return list<Capteur>();
	}
	else
	{
		return afficherVoisinsPoint(centerSensor->getLongitude(), centerSensor->getLatitude, r);
	}
}

list<Capteur> Controleur::afficherVoisinsPoint(double longitude,double latitude,float r)
{
	list<Capteur> res;
	set<Capteur>::iterator it;
	for (it = capteurs.begin(); it != capteurs.end(); it++)
	{
		double latTest = it->getLatitude();
		double lngTest = it->getLongitude();
		double d = distance(latitude, longitude, latTest, lngTest);

		if (d < r)
		{
			res.push_front(*it);
		}
	}
	return res;
}

long double distance(long double lat1, long double long1,
	long double lat2, long double long2)
{
	// Convert the latitudes  
	// and longitudes 
	// from degree to radians. 
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);

	// Haversine Formula 
	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
		cos(lat1) * cos(lat2) *
		pow(sin(dlong / 2), 2);

	ans = 2 * asin(sqrt(ans));

	// Radius of Earth in  
	// Kilometers, R = 6371 
	// Use R = 3956 for miles 
	long double R = 6371;

	// Calculate the result 
	ans = ans * R;

	return ans;
}

long double toRadians(const long double degree)
{
	// cmath library in C++  
	// defines the constant 
	// M_PI as the value of 
	// pi accurate to 1e-30 
	const long double M_PI = 3.14159265358979323846;  // pi
	long double one_deg = (M_PI) / 180;
	return (one_deg * degree);
}

list<Capteur> Controleur::afficherAttributQualiteCapteur(string attributeID,double qualité,float s){}

list<Capteur> Controleur::afficherCapteursSimilaires(string attributeID,string CapteurID,float  s){}

pair<int,string> Controleur::calculAirQualityCapteur(string attributeID,string capteurID,float r,float p,float t){}

pair<int,string> Controleur::calculAirQualityPoint(string attributeID,double longitude,double latitude,float r,float p,float t){}

pair<int,string> Controleur::calculAirQuality(int indiceO3,int indiceSO2,int indiceNO2,int indicePM10){}

pair <int,int> Controleur::trouverLongitudeLatitude(string capteurID){
    bool found=false;
    pair<int,int> res;
    for(set<Capteur>::iterator it=capteurs.begin();it!=capteurs.end() && !found;++it){
        if(it->getID() == capteurID){
            found=true;
            res.first = it->getLatitude();
            res.second = it->getLongitude();
        }
    }
    return res;
}

//

//-------------------------------------------- Constructeurs - destructeur
    
    
    Controleur::Controleur ( )
    // Algorithme :
    //
    {
#ifdef MAP
        cout << "Appel au constructeur de <Controleur>" << endl;
#endif
    } //----- Fin de Controleur
    
    
    Controleur::~Controleur ( )
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
