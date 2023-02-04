// This program prompts the user for a positive integer, n
// The program prints an (nxn) multiplication table
// Multiples are separated by a horizontal tab


#include <iostream>
using namespace std;

int main(){

    int userInteger = 0;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>userInteger;
    
    // Incriment over each row
    for (int i = 1; i <= userInteger; i++){
        // Incriment over each column
        for (int j = 1; j <= userInteger; j++){
            
            cout<<(i * j);

            if ( j < userInteger){
                //print tabs between multiples
                cout<<"\t";

            } else {

                cout<<endl;

            }
        }
    }

    return 0;
}