#include "Capteur.h"
#include "Mesure.h"

#include <list>
#include <string>
#include <set>
#include "FileReader.h"
#include "Attribut.h"

class Controleur{
    public:
    
    void InitialiserFichiers(FileReader fileReader);
    
    bool INIT (string,string,string);

    bool testCapteurActif(string capteurID, float t);

    bool verifCapteur(string capteurID,float p,float t,float s);

    list <Capteur> afficherVoisinsCapteur(string capteurID,float r);

    list<Capteur> afficherVoisinsPoint(double longitude,double latitude,float r);

    list<Capteur> afficherAttributQualiteCapteur(string attributeID,double qualité,float s);

    list<Capteur> afficherCapteursSimilaires(string attributeID,string CapteurID,float  s);

    pair<int,string> calculAirQualityCapteur(string attributeID,string capteurID,float r,float p,float t);

    pair<int,string> calculAirQualityPoint(string attributeID,double longitude,double latitude,float r,float p,float t);

    pair<int,string> calculAirQuality(int indiceO3,int indiceSO2,int indiceNO2,int indicePM10);

    pair <int,int> trouverLongitudeLatitude(string capteurID);


    private:
    
    
    FileReader fileReader;
    set<Capteur> capteurs;
    set<Attribut> attributs;
    
};
