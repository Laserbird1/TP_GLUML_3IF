
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
#include <math.h>

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


bool Controleur::testCapteurActif(string capteurID, float t){
//Algorithme:
    // Identifiant du capteur,nombre d’heures à analyser

//Booléen renvoyant True ou False selon le cas où le capteur est actif ou pas.

    
}

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

pair<int,string> Controleur::calculAirQualityCapteur(string attributeID,double longitude,double latitude,float r,float t1,float t2){
    list<Capteur> voisins = afficherVoisinsPoint(longitude,latitude,r);
    int cantCapteursMoyenne = 0;
    double denominateurMoyenne = 0;
    for(list<Capteur>::iterator it=voisins.begin();it!=voisins.end() ;++it){
        if(testCapteurActif(it->getID(),t1,t2)){
            denominateurMoyenne += it->getMoyenne(attributeID,t1,t2);
            cantCapteursMoyenne += 1;
        }
    }
    pair<int,string> res;
    res.first = denominateurMoyenne/cantCapteursMoyenne;
    //on doit mettre un message associe a la valeur trouvee
    res.second = "";
    return res;
}

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

double getMoyenne(string capteurID,string attributeID,Date d1,Date d2){
    Mesure mesure;
    double denominateurMoyenne = 0;
    int countCapteurs = 0;
    while(fileReader->LireLigneMesure(mesure) && mesure.getTimestamp() < d2 ){
        if(d1 < mesure.getTimestamp()){
            if(mesure.getSensorID() == capteurID && mesure.getAttributeID() == attributeID ){
                denominateurMoyenne += mesure.getValue();
                countCapteurs += 1;
            }
        }
    }
    return denominateurMoyenne/countCapteurs;
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
