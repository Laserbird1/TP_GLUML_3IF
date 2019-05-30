
#include <iostream>
#include <string>
#include "Controleur.h"
using namespace std;

Date entrerDate();

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
        cout << "2: Vérifier qu'un capteur a ete actif" << endl;
        cout << "3: " << endl;
        cout << "4: " << endl;
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
            case 2: //Activité du capteur
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
