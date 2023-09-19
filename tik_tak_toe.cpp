#include <iostream>
#include <iomanip>

using namespace std;

//Functie afisare tabel
void tableShow(char table[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(table[i][j] != 'X' && table[i][j] != 'O'){
                cout << " -";
            }else{
                cout << setw(2) << table[i][j];
            }
        }
    cout << endl;
    }
}

//Functie pentru verificarea tabelului
bool tableCheck(char table[3][3], int playerTurn){
    //Verificare randuri
    if((table[0][0] == table[0][1] && table[0][1] == table[0][2]) || (table[1][0] == table[1][1] && table[1][1] == table[1][2]) || (table[2][0] == table[2][1] && table[2][1] == table[2][2])){
        cout << "Player " << playerTurn << " win ROW!" << endl;
        return true;
    }
    //Verificare coloane
    else if((table[0][0] == table[1][0] && table[1][0] == table[2][0]) || (table[0][1] == table[1][1] && table[1][1] == table[2][1]) || (table[0][2] == table[1][2] && table[1][2] == table[2][2])){
        cout << "Player " << playerTurn << " win COL!" << endl;
         return true;
    }
    //Verificare diagonale
    else if((table[0][0] == table[1][1] && table[1][1] == table[2][2]) || (table[2][0] == table[1][1] && table[1][1] == table[0][2])){
        cout << "Player " << playerTurn << " win DIAG!" << endl;
         return true;
    }

    return false;
}


int main(){
    char table[3][3];
    bool end = 0;
    int row = 0, col = 0;
    int playerTurn = 1;

    cout << "Game started!" << endl;

    while(end == 0){
        if(playerTurn == 1){
            //Introduce valorile rand/coloana
            cout << "Player 1 turn: " << endl;
            tableShow(table);
            cout << "Enter row: ";
            cin >> row;

            //Daca introuduce 0 atunci jocul s-a terminat
            if(row == 0){
                cout << "Game ended!" << endl;
                end = 1;
            }
            else{
                cout << "Enter col: ";
                cin >> col;

                //Verificam ca pozitia introdusa sa nu fie deja ocupata
                bool incorect = false;
                do{
                    if(table[row - 1][col - 1] == 'X' || table[row - 1][col - 1] == 'O'){
                        incorect = true;
                        cout << "This position it is already taken! Pick another one " << end;
                        cout << "Enter row: ";
                        cin >> row;
                        if(row != 0){
                            cout << "Enter col: ";
                            cin >> col;
                        }
                        else{
                            end = true;
                        }    
                    }
                    else{
                        incorect = false;
                        table[row - 1][col - 1] = 'X';
                    }
                }while(incorect == true && end == false);

                //Venim cu verificarea din bucla do/while ca jucatorul sa nu fi introdus cifra 0
                if(end == false){
                    end = tableCheck(table, playerTurn);  
                }
                
                //Trebuie sa verificam din nou variabila "end" deoarece este posibil ca la vaerificarea tabelului sa avem un castigator
                if(end == true){
                    tableShow(table);
                }

                playerTurn = 2;
            }
        }
        else{
            //Introduce valorile rand/coloana
            cout << "Player 2 turn: " << endl;
            tableShow(table);
            cout << "Enter row: ";
            cin >> row;

            //Daca introduce 0 atunci jocul s-a terminat
            if(row == 0){
                cout << "Game ended!" << endl;
                end = 1;
            }
            else{
                cout << "Enter col: ";
                cin >> col;

                ///Verificam ca pozitia introdusa sa nu fie deja ocupata
                bool incorect = false;
                do{
                    if(table[row - 1][col - 1] == 'X' || table[row - 1][col - 1] == 'O'){
                        incorect = true;
                        cout << "This position it is already taken! Pick another one " << endl;
                        cout << "Enter row: ";
                        cin >> row;
                        if(row != 0){
                            cout << "Enter col: ";
                            cin >> col;
                        }
                        else{
                            end = true;
                        } 
                    }
                    else{
                        incorect = false;
                        table[row - 1][col - 1] = 'O';
                    }
                }while(incorect == true && end == false);
                
                //Venim cu verificarea din bucla do/while ca jucatorul sa nu fi introdus cifra 0
                if(end == false){
                    end = tableCheck(table, playerTurn);  
                }
                
                //Trebuie sa verificam din nou variabila "end" deoarece este posibil ca la vaerificarea tabelului sa avem un castigator
                if(end == true){
                    tableShow(table);
                }

                playerTurn = 1;
            }
        }
    }

    return 0;
}