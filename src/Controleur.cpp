
/*************************************************************************
 ${file_base}  -  description
 -------------------
 dÈbut                : ${date}
 copyright            : (C) ${year} par ${user}
 *************************************************************************/

//---------- RÈalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systËme
using namespace std;
#include <iostream>
#include "Capteur.h"
#include "Mesure.h"
#include "Controleur.h"
#include <list>
#include <string>

//------------------------------------------------------ Include personnel


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privÈs


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- MÈthodes publiques
// type ${file_base}::MÈthode ( liste de paramËtres )
// Algorithme :
//
//{
//} //----- Fin de MÈthode

bool Controleur::INIT (string a,string b,string c){}

bool Controleur::testCapteurActif(string capteurID, float t){}

bool Controleur::verifCapteur(string capteurID,float p,float t,float s){}

list <Capteur> Controleur::afficherVoisinsCapteur(string capteurID,float r){}

list<Capteur> Controleur::afficherVoisinsPoint(double longitude,double latitude,float r){}

list<Capteur> Controleur::afficherAttributQualiteCapteur(string attributeID,double qualité,float s){}

list<Capteur> Controleur::afficherCapteursSimilaires(string attributeID,string CapteurID,float  s){}

pair<int,string> Controleur::calculAirQualityCapteur(string attributeID,string capteurID,float r,float p,float t){}

pair<int,string> Controleur::calculAirQualityPoint(string attributeID,double longitude,double latitude,float r,float p,float t){}

pair<int,string> Controleur::calculAirQuality(int indiceO3,int indiceSO2,int indiceNO2,int indicePM10){}

pair <int,int> Controleur::trouverLongitudeLatitude(string capteurID){}


//-------------------------------------------- Constructeurs - destructeur
${file_base}::${file_base} ( const ${file_base} & un${file_base} )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <${file_base}>" << endl;
#endif
    } //----- Fin de ${file_base} (constructeur de copie)
    
    
    ${file_base}::${file_base} ( )
    // Algorithme :
    //
    {
#ifdef MAP
        cout << "Appel au constructeur de <${file_base}>" << endl;
#endif
    } //----- Fin de ${file_base}
    
    
    ${file_base}::~${file_base} ( )
    // Algorithme :
    //
    {
#ifdef MAP
        cout << "Appel au destructeur de <${file_base}>" << endl;
#endif
    } //----- Fin de ~${file_base}
    
    
    //------------------------------------------------------------------ PRIVE
    
    //----------------------------------------------------- MÈthodes protÈgÈes
    
    //------------------------------------------------------- MÈthodes privÈes
