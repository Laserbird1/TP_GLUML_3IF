
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
	} while (!controleur->InitialiserFichiers(nomCsvMesures, nomCsvAttributs, nomCsvCapteurs));


    
    while(continuer){
        cout << "Bienvenue,"<<"\n"<<"Options:"<<endl;
        cout << "1: " << endl;
        cout << "2: Verifier qu'un capteur a ete actif" << endl;
        cout << "3: Afficher les capteurs voisins à un point" << endl;
        cout << "4: Trouver la longitude et la lattitude d'un capteur " << endl;
        cout << "5: " << endl;
        cout << "6: " << endl;
        cout << "7: " << endl;
        cout << "8: " << endl;
        cout << "9: " << endl;
        cout << "10: " << endl;
        cout << "11: " << endl;
        cout << "12: Sortir" << endl;
        cout << "Introduire numero: \n" << endl;

        cin >> valeur;

        switch (valeur){
            case 1 : 
				cout<<"Recu 1 OK"<<endl;
				break;
            case 2: //Activité du capteur (fonctionne)
			{

				string nomCapteur;
				cout << "Date du debut de l intervalle" << endl;
				Date d1 = entrerDate();
				cout << "Date de fin de l intervalle" << endl;
				Date d2 = entrerDate();
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
			}

			case 3: //Capteurs voisins (fonctionne)
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
			}

			case 4: //lattitude et longitude d'un capteur (fonctionne)
			{

				pair<int, int> paire;
				string nomCapteur;
	
				cout << "Saisir le nom du capteur :" << endl;
				cin >> nomCapteur;
				paire = controleur->trouverLongitudeLatitude(nomCapteur);

				cout << "Longitude :" << paire.first << endl;
				cout << "Lattitude:" << paire.second << endl;
			}
            case 12: 
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
