
#include <iostream>
#include <Controleur.cpp>
using namespace std;


int main()
{
    int valeur=0;
    bool continuer=true;
    Controleur* C= new Controleur();

    //demander nom fichiers csv, 
    string nomCsvMesures;
    string nomCsvCaptures;
    string nomCsvAttributs;
    cout << "Ecrire le nom du fichier Mesures " <<endl;
    cin >> nomCsvMesures;
    cout << "Ecrire le nom du fichier Captures " <<endl;
    cin >> nomCsvCaptures;
    cout << "Ecrire le nom du fichier Attributs " <<endl;
    cin >> nomCsvAttributs;

    FileReader *FR =  new FileReader();

    FR->OpenCsvMesure(nomCsvMesures);
    FR->OpenCsvCapteur(nomCsvCaptures);
    FR->OpenCsvAttribut(nomCsvAttributs);
    
    while(continuer){
        cout << "Bienvenu,"<<"\n"<<"Options:"<<endl;
        cout << "1: " << endl;
        cout << "2: Verifier coherence d'un capteur" << endl;
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
            case 1 : cout<<"Recu 1 OK"<<endl;
            break;
            case 2: 
                string idCapteur;
                int p;
                int t;
                float s;
                
                cout<<"Rentrer l'identifiant du capteur"<<endl;
                cin >> idCapteur;
                cout<<"Rentrer le nombre d’heures a prendre en compte pour la verification"<<endl;
                cin >> p ;
                cout <<"Rentrer l'heure jusqu'a laquelle verifier "<<endl;
                cin >> t;
                cout<< "Rentrer le pourcentage de tolerance (valeur entre 0 et 1)" <<endl;
                cin >> s;//s
                bool res = C->verifCapteur(idCapteur,p,t,s);
            break;
            case 12: continuer=false;
            break; 
        }
    }
	return 0;
}
