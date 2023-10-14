#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//ADT Angajat
struct Angajat{
    int id;
    string nume;
    string jobTitle;
};

//ADT Cladiri
struct Building{
    int buildingNumber;
    int numEmployees;
    vector<Angajat*> employees;
};

int main(){
    int numarCladiri;
    vector<Building*> cladiri;

    cout << "Numarul de cladiri: " << endl;
    cin >> numarCladiri;

    for(int i = 0; i < numarCladiri; i++){
        Building *b = new Building;
        b -> buildingNumber = i;
        cout << "Introdu numarul de angajati: " << endl;
        cin >> b -> numEmployees;

            for(int j = 0; j < b->numEmployees; j++){
                Angajat *angajat = new Angajat;
                angajat->id = j;
                cout << "Angajatul " << j << " Numele: \n";
                cin >> angajat->nume;
                cout << "Angajatul " << j << " Titlul serviciului: \n";
                cin >> angajat->jobTitle;
                b -> employees.push_back(angajat);
                cout << endl;
            }
        cladiri.push_back(b);
    }

    for(int i = 0; i < cladiri.size(); ++i){
        cout << "Cladirea cu numarul #" << cladiri[i] -> buildingNumber << endl;
        for(int j = 0; j < cladiri[i] -> employees.size(); j++){
            cout << "\t Id " << cladiri[i] -> employees[j] -> id << endl;
            cout << "\t Nume " << cladiri[i] -> employees[j] -> nume << endl;
            cout << "\t Titlul job-ului " << cladiri[i] -> employees[j] -> jobTitle << endl;
        }
        cout << "\n\n";
    }
    return 0;
}