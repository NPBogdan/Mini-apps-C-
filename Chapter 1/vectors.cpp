#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<double> myVect;

    myVect.push_back(3);

    cout << myVect.size() << endl;
    cout << myVect[0] << endl;

    myVect.push_back(5);
    cout << myVect.size() << endl;
    cout << myVect[1] << endl;

    myVect.pop_back();
    cout << myVect.size() << endl;

    return 0;
}