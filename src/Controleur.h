#include "Capteur.h"
#include "Mesure.h"
#include "Attribut.h"
#include "FileReader.h"

#include <list>
#include <string>
#include <set>
#include "FileReader.h"
#include "Attribut.h"

class Controleur{
    public:
    
    void InitialiserFichiers(FileReader fileReader);

    bool testCapteurActif(string capteurID, float t);

    bool verifCapteur(string capteurID,float p,float t,float s);

    list <Capteur> afficherVoisinsCapteur(string capteurID,float r);

    list<Capteur> afficherVoisinsPoint(double longitude,double latitude,float r);

    list<Capteur> afficherAttributQualiteCapteur(string attributeID,double qualité,float s);

    list<Capteur> afficherCapteursSimilaires(string attributeID,string CapteurID,float  s);

    pair<int,string> calculAirQualityCapteur(string attributeID,double longitude,double latitude,float r,Date t1,Date t2);

    pair<int,string> calculAirQuality(int indiceO3,int indiceSO2,int indiceNO2,int indicePM10);

    pair <int,int> trouverLongitudeLatitude(string capteurID);

    double getMoyenne(string CapteurID,string attributeID,Date t1,Date t2);

    private:
    
    FileReader *fileReader;
    set<Capteur> capteurs;
    set<Attribut> attributs;
    
};
