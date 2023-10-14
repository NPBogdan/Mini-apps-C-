#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

void binarySearch(vector<string> &v, vector<int> &v2, string s){
   int low = 0;
   int high = v.size()-1;
   int middle;
   while(low <= high){
       middle = (low + high)/2;
       if(s > v[middle]){
           low = middle+1;
       }
       else if(s < v[middle]){
           high = middle-1;
       }
       else{
           cout << "The age for " << s << " is " << v2[middle] << endl;
           return;
       }
   }
   cout << "The name " << s << " does not exist in the database" << endl;
}

void lower(string &s){
    for(char & i : s){
        i = tolower(i);
    }
}

void sort(vector<string> &v, vector<int> &v2){
    string temp_name;
    int temp_age;
    string insertion_item;
    int sorted_position;
    //Insertion Sort
    for(int i = 0; i < v.size(); i++){
        //set the item position to be inserted into sorted area 
        insertion_item = v[i];
        
        //set the rightmost position of sorted area
        sorted_position = i-1;

        //Swapping loop 
        while(sorted_position >= 0 && v[sorted_position] > insertion_item){
            //Swap name vector
            temp_name = v[sorted_position];
            v[sorted_position] = v[sorted_position+1];
            v[sorted_position+1] = temp_name;

            //Swap age vector to match the name vector
            temp_age = v2[sorted_position];
            v2[sorted_position] = v2[sorted_position+1];
            v2[sorted_position+1] = temp_age;

            //Move our position one to the left inside sorted area 
            sorted_position--;
        }
    }
}

int main(int argc, char *argv[]){
    string name;
    int age;
    string query;
    vector<string> nameVect;
    vector<int> ageVect;
    ifstream instream;
    if(argc != 2){
        cout << "Usage: ./program_name <filename>" << endl;
        exit(-1);
    }
    instream.open(argv[1]);
    while(instream >> name){
        lower(name);
        nameVect.push_back(name);
        instream >> age;
        ageVect.push_back(age);
    }
    instream.close();

    sort(nameVect, ageVect);

    do{
        cout << "Enter a name to be searched in the database (or type 'quit'): ";
        cin >> query;
        lower(query);
        if(query == "quit"){
            break;
        }
        binarySearch(nameVect, ageVect, query);
    }
    while(query != "quit");

    return 0;

    
}