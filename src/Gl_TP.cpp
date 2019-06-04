
#include <iostream>
#include <string>
#include "Controleur.h"
using namespace std;

Date entrerDate();
float entrerRayon();
double entrerCoords();

int main()
{
    int valeur=0;
    bool continuer=true;
    Controleur* controleur= new Controleur();

	string nomCsvMesures;
	string nomCsvCapteurs;
	string nomCsvAttributs;

    //demander nom fichiers csv

	do {

		cout << "Ecrire le nom du fichier Mesures " << endl;
		cin >> nomCsvMesures;
		cout << "Ecrire le nom du fichier Capteurs " << endl;
		cin >> nomCsvCapteurs;
		cout << "Ecrire le nom du fichier Attributs " << endl;
		cin >> nomCsvAttributs;
	} while (!controleur->initialiserFichiers(nomCsvMesures, nomCsvAttributs, nomCsvCapteurs));


    
    while(continuer){
		controleur->reinitialiserLectureFichiers();
        cout << "Bienvenue,"<<"\n"<<"Options:"<<endl;
        
        cout << "1: Verifier qu'un capteur a ete actif" << endl;
        cout << "2: Retrouver des capteurs similaire sur un intervalle de temps" << endl;
        cout << "3: Trouver l'indice ATOM pour un attribut dans une zone et un interval de temps" << endl;
        cout << "4: Trouver l'etat de l'aire moyen en un point donnée" << endl;
     
        cout << "5: Afficher les capteurs voisins à un point" << endl;
        cout << "6: Trouver la longitude et la lattitude d'un capteur" << endl;
        cout << "7: Mesurer la qualite de l'air dans une zone" << endl;
        cout << "8: Lancer le jeu de test" << endl;
        cout << "9: Sortir" << endl;
        cout << "Introduire numero: \n" << endl;

        cin >> valeur;

        switch (valeur){
           
            case 1: //Activité du capteur (fonctionnel)
			{
                
				string nomCapteur;
				Date d1;
				Date d2;
				do
				{
					cout << "Date du debut de l intervalle" << endl;
					d1 = entrerDate();
					cout << "Date de fin de l intervalle" << endl;
					d2 = entrerDate();
					if (d1 >= d2) cout << "La date de debut doit etre inferieure a la date de fin !" << endl;
				} while (d1 >= d2);
				cout << "Saisir le nom du capteur" << endl;
				cin >> nomCapteur;
				bool actif = controleur->testCapteurActif(nomCapteur, d1, d2);
				if (actif)
				{
					cout << "Le capteur a bien été actif sur cette période" << endl;
				}
				else
				{
					cout << "Le capteur a été inactif sur cette période, ou n'existe pas" << endl;
				}
				
				break;
			}
            case 2:
            {
				//demander les attributs
				//List<Capteur> * afficherAttributQualiteCapteur(attributeID,qualité,s)
	
               break;
            }
            
            
            case 3:
            {
				// demander les attributs
				//pair<int, string> Controleur.calculAirQualityCapteur(attributeID, lat,  lng, r,  t1, t2);

                break;
            }
            
            case 4:
            {
				//demander les attributs 
				//pair<int, string> Controleur.calculeQualiteAirEnUnPoint(lat, lng, d1,  d2);;

                break;
            }
            




			//a supprimer un fois que tout fonctionne
			case 5: //Capteurs voisins (fonctionnel)
			{

				list<Capteur> * liste;
				double lat;
				double lng;
				float r;
		
				cout << "Saisir la latitude :" << endl;
				lat = entrerCoords();
				cout << "Saisir la longitude :" << endl;
				lng = entrerCoords();
				cout << "Saisir le rayon (en km) :" << endl;
				r = entrerRayon();
				liste = controleur->afficherVoisinsPoint(lng, lat, r);

				if (!liste->empty())
				{
					for (list<Capteur>::iterator it = liste->begin(); it != liste->end(); ++it)
					{
						(*it).afficher();
					}
				}
				else
				{
					cout << "Aucun capteur n'est présent dans le rayon" << endl;
				}
				break;
			}

			case 6: //lattitude et longitude d'un capteur (fonctionnel)
			{

				pair<int, int> paire;
				string nomCapteur;
	
				cout << "Saisir le nom du capteur :" << endl;
				cin >> nomCapteur;
				paire = controleur->trouverLongitudeLatitude(nomCapteur);

				cout << "Longitude :" << paire.first << endl;
				cout << "Lattitude:" << paire.second << endl;
				break;
			}

			case 7: //Qualité de l'air dans une zone (fonctionnel)
			{
				double lat;
				double lng;
				float r;
				Date d1;
				Date d2;
				string attributeID;

				cout << "Saisir le nom de l'attribut :" << endl;
				cin >> attributeID;
				cout << "Saisir la latitude :" << endl;
				lat = entrerCoords();
				cout << "Saisir la longitude :" << endl;
				lng = entrerCoords();
				cout << "Saisir le rayon (en km) :" << endl;
				r = entrerRayon();
				do
				{
					cout << "Date du debut de l intervalle" << endl;
					d1 = entrerDate();
					cout << "Date de fin de l intervalle" << endl;
					d2 = entrerDate();
					if (d1 >= d2) cout << "La date de debut doit etre inferieure a la date de fin !" << endl;
				} while (d1 >= d2);

				pair<int, string> paire = controleur->calculAirQualityCapteur(attributeID, lat, lng, r, d1, d2);
				cout << "Indice ATMO :" << paire.first << endl;
				cout << "Description :" << paire.second << endl;
				break;
			}

            case 8:
                controleur.lancerTests();
                break;
            
            case 9:
				continuer=false;
				break; 
        }
    }
	return 0;
}

Date entrerDate()
{
	unsigned int annee;
	unsigned int mois;
	unsigned int jour;
	unsigned int heure;

	string getInfos;
	bool entreeCorrecte = true;

	//Annee
	do
	{
		entreeCorrecte = true;
		cout << "Saisir l'annee" << endl;
		cin >> getInfos;
		try {
			annee = stoi(getInfos);
			if (annee < 1800)
			{
				cerr << "Veuillez saisir une annee valide" << endl;
				entreeCorrecte = false;
			}
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un entier" << endl;
		}
	} while (entreeCorrecte == false);

	//mois
	do
	{
		entreeCorrecte = true;
		cout << "Saisir le mois" << endl;
		cin >> getInfos;
		try {
			mois = stoi(getInfos);
			if (mois <= 0 || mois>=13)
			{
				cerr << "Veuillez saisir un mois valide" << endl;
				entreeCorrecte = false;
			}
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un entier" << endl;
		}
	} while (entreeCorrecte == false);

	//jour
	do
	{
		entreeCorrecte = true;
		cout << "Saisir le jour" << endl;
		cin >> getInfos;
		try {
			jour = stoi(getInfos);
			if (jour <= 0 || jour >= 32)
			{
				cerr << "Veuillez saisir un jour valide" << endl;
				entreeCorrecte = false;
			}
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un entier" << endl;
		}
	} while (entreeCorrecte == false);

	//heure
	do
	{
		entreeCorrecte = true;
		cout << "Saisir l heure" << endl;
		cin >> getInfos;
		try {
			heure = stoi(getInfos);
			if (heure < 0 || heure >= 24)
			{
				cerr << "Veuillez saisir une heure valide" << endl;
				entreeCorrecte = false;
			}
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un entier" << endl;
		}
	} while (entreeCorrecte == false);

	Date d(annee, mois, jour, heure, 0, 0);
	return d;
}

float entrerRayon()
{
	string getInfos;
	bool entreeCorrecte = true;
	float f;

	do
	{
		entreeCorrecte = true;
		cin >> getInfos;
		try {
			f = stof(getInfos);
			if (f<0)
			{
				cerr << "Veuillez saisir un rayon valide" << endl;
				entreeCorrecte = false;
			}
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un flottant" << endl;
		}
	} while (entreeCorrecte == false);

	return f;
}

double entrerCoords()
{
	string getInfos;
	bool entreeCorrecte = true;
	double d;

	do
	{
		entreeCorrecte = true;
		cin >> getInfos;
		try {
			d = stod(getInfos);
		}
		catch (exception e) {
			entreeCorrecte = false;
			cerr << "Erreur, veuillez saisir un flottant" << endl;
		}
	} while (entreeCorrecte == false);

	return d;
}
