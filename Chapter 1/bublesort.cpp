#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vect;
    int number;
    for(int i = 0; i < 5; i++){
        cin >> number;
        vect.push_back(number);
    }

    int aux;
    bool had_swaps = false;
    for(int i = 0; i < vect.size(); i++){
        had_swaps = false;
        for(int j = 0; j < vect.size() - i - 1; j++){
            if(vect[j] > vect[j + 1]){
            aux = vect[j + 1];
            vect[j + 1] = vect[j];
            vect[j] = aux;
            had_swaps = true;
            }
        }  
        if(!had_swaps){
            break;
        }    
    }
   
    for(int i = 0; i < 5; i++){
        cout << vect[i] << " "; 
    }

    return 0;
}