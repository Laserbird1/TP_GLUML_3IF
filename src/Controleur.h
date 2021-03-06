#include "Capteur.h"
#include "Mesure.h"
#include "Attribut.h"
#include "FileReader.h"

#include <list>
#include <string>
#include <set>
#include "FileReader.h"
#include "Attribut.h"
#include "Capteur.h"

class Controleur {
public:

	bool initialiserFichiers(string mesure, string attribut, string capteur);

	void reinitialiserLectureFichiers();

	bool testCapteurActif(string capteurID, Date t1, Date t2);

	list <Capteur> * afficherVoisinsPoint(double longitude, double latitude, float r);

	//service 1
	list<Capteur> * afficherAttributQualiteCapteur(string attributeID, int s, Date t1, Date t2);
	//service 2
	pair<int, string> calculAirQualityCapteur(string attributeID, double lat, double lng, double r, Date t1, Date t2);


	float CalculerDistance(double lat1, double lng1, double lat2, int lng2);

	double toRadians(double deg);

	pair <double, double> trouverLongitudeLatitude(string capteurID);

	//
	//donne la moyenne sur un interval pour 1 capteur de ses valeurs pour un attribut.
	double trouverMoyenneCapteur(string capteurID, string attributID, Date d1, Date d2);

	//
	// donne le capteur le plus proche d’un point. mais pas plus loin que r. revoi en nullprt sinon.
	Capteur trouverCapteurLePlusProche(double r, double lat, double lng);

	//service 3
	//recupère le capteur le plus proche et calcule le qualité moyenne sur l'intervale precisé en ce point
	pair<int, string> calculeQualiteAirEnUnPoint(double lat, double lng, Date d1, Date d2);

	//-------------------------------------------- Constructeurs - destructeur
	Controleur();

	~Controleur();

	//-------------------------------------------- Tests

	void lancerTests();

	bool testInitFichier();

	bool testActivite();

	bool testAfficherVoisins();

	bool testCapteurPlusProchePoint();

	bool testTrouverLongLat();

	bool testCalculeQualAirePoint();

	bool testCalculeAireQualityCapteur();

	bool testCalculeQualiteAirEnUnPoint();

	bool testAfficherAttQualCapteur();


private:

	FileReader fileReader;
	set<Capteur> capteurs;
	set<Attribut> attributs;

};
