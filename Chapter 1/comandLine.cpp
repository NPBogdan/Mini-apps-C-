#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    ifstream myInStream;
    myInStream.open(argv[1]);
    int value;
    int position = 0;
    int numCount;

    myInStream >> numCount;
    cout << "Pe prima linie scrie " << numCount << endl;

    int *numbers = new int[numCount];

    while(myInStream >> value){
        numbers[position] = value;
        cout << numbers[position] << " " << endl;
        position++;
    }
    
    myInStream.close();

    delete[]numbers;
    return 0;
}
