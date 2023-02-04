/*
Write a program that reads a positive integer n from the user and prints out a nxn
multiplication table. The columns should be spaced by a tab.
Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer:

*/


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
            
            //Print each multiple
            cout<<(i * j)<<"\t";

        }

        cout<<endl;

    }

    return 0;
}