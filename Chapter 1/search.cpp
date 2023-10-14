#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &vector, int num){
    int left = 0;
    int right = vector.size() - 1;
    int middle = (left + right) / 2;
    while(left <= right){
        middle = (left + right) / 2;
        if(num < vector[middle]){
            right = middle - 1;
        }
        else if(num > vector[middle]){
            left = middle + 1;
        }
        else{
            return true;
        }
    }

    return false;
}


int main(){
    vector<int> vect;
    int number;
    cout << "Enter the number to be searched: " << endl;
    int item;
    cin >> item;
    for(int i=0; i < 5; i++){
        cin >> number;
        vect.push_back(number);
    }

    bool result = search(vect, item);

    if(result == true){
        cout << "Founded!" << endl;
    }
    else{
        cout << "It is not here!" << endl;
    }

    return 0;
}