#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

//Binary Search
double wordSearch(vector<string> &v, string word)
{
        int left = 0;
        int right = v.size() - 1;
        int middle;
 
        while(left <= right){
            middle = (left + right) / 2;
            if(word > v[middle]){
                left = middle + 1;
            }
            else if(word < v[middle]){
                right = middle - 1;
            }
            else{
                return middle;
            }
        }
        return -1;
}

//Transforma string-ul in lowercase
void lower(string &s){
    for(char &i : s){
        i = tolower(i);
    }
}

int main(){
    //Part1 facem partea de extragere a cuvintelor din fisier
    vector<string> names;
    vector<string> ages;
    string line = "";
    string substring = "";

    ifstream istream;
    istream.open("project2_names.txt");

    int spacePosition = 0;
    //Extragem fiecare linie din fisier pe rand
    while(getline(istream, line)){
        //Vom salva pozitia "spatiu" pentru a sti locul de impartire a liniei pentru nume si varsta
        for(int i = line.size() - 1; i >= 0; i--){
            if(line[i] == ' '){
                spacePosition = i;
                break;
            }
        }

        //Extragem varsta
        substring = line.substr(spacePosition + 1);
        ages.push_back(substring);

        //Extragem numele
        substring = line.substr(0,spacePosition);
        lower(substring);
        names.push_back(substring);
    }

    istream.close();
  
    //Part 2, trebuie sa sa le sortam crescator intr-un vector
    int sorted_pos = 0;
    string current_item = "";
    string tem = "";

    for(int i = 0; i < names.size(); i++){
        current_item = names[i];
        sorted_pos = i - 1;
        tem = "";

        while(sorted_pos >= 0 && names[sorted_pos] > current_item){
            tem = names[sorted_pos];
            names[sorted_pos] = names[sorted_pos + 1];
            names[sorted_pos + 1] = tem;

            //Sortam si vectorul de numere
            tem = ages[sorted_pos];
            ages[sorted_pos] = ages[sorted_pos + 1];
            ages[sorted_pos + 1] = tem; 
        
            sorted_pos--;
        }  
    }

    //Partea 3, trebuie sa implementam algoritmul de cautare binara si afisam varsta numelui cautat
    cout << "Enter a name to find the age for it: " << endl;
    cin >> tem;

    double wordAgePosition = wordSearch(names, tem);
    if(wordAgePosition != -1){
        cout << "The age is : " << ages[wordAgePosition] << endl;
    }
}