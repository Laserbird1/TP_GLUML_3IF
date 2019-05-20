
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
#include "Capteur.h"
#include "Mesure.h"
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

//pierre
void InitialiserFichiers(FileReader fileReader)
{   this.fileReader = fileReader;
    capteurs = this.fileReader.InitListeCapteurs();
    attributs = this.fileReader.InitListeAttributs(); 
};
//pierre
bool Controleur::INIT (string a,string b,string c){}

bool Controleur::testCapteurActif(string capteurID, float t){}

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
	}
	else
	{

		double latCenter = centerSensor->getLatitude();
		double lngCenter = centerSensor->getLongitude();
		for (it = capteurs.begin(); it != capteurs.end(); it++)
		{
			double latTest = it->getLatitude();
			double lngTest = it->getLongitude();
			double x = latCenter - latTest;
			double y = lngCenter - lngTest;

			if (x*x + y * y < r*r)
			{
				res.push_front(*it);
			}
		}
	}

	return res;

}

list<Capteur> Controleur::afficherVoisinsPoint(double longitude,double latitude,float r){}

list<Capteur> Controleur::afficherAttributQualiteCapteur(string attributeID,double qualité,float s){}

list<Capteur> Controleur::afficherCapteursSimilaires(string attributeID,string CapteurID,float  s){}

pair<int,string> Controleur::calculAirQualityCapteur(string attributeID,string capteurID,float r,float p,float t){}

pair<int,string> Controleur::calculAirQualityPoint(string attributeID,double longitude,double latitude,float r,float p,float t){}

pair<int,string> Controleur::calculAirQuality(int indiceO3,int indiceSO2,int indiceNO2,int indicePM10){}

pair <int,int> Controleur::trouverLongitudeLatitude(string capteurID){}


//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur ( const Controleur & unControleur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Controleur>" << endl;
#endif
    } //----- Fin de Controleur (constructeur de copie)
    
    
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
