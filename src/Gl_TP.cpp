
#include <iostream>
using namespace std;


int main()
{
    int valeur=0;
    bool continuer=true;
    while(continuer){
        cout << "Bienvenu,"<<"\n"<<"Options:"<<endl;
        cout << "1: " << endl;
        cout << "2: " << endl;
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
        cout << "Introduire numero: " << endl;

        cin >> valeur;

        switch (valeur){
            case 1 : cout<<"Recu 1 OK"<<endl;
            break;
            case 12: continuer=false;
            break; 
        }
    }
	return 0;
}
