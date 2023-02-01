//This program will prompt the user for a positive integer, n
//the program will print a tectual image of an hourglass made of 2n lines of asterisks


#include <iostream>
using namespace std;

int main(){

    int userInteger = 0;
    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;

    int rowCounter = 1;
    int starCounter = userInteger;


    for (rowCounter; rowCounter <= userInteger; rowCounter++){

        for(starCounter; starCounter > 0; starCounter--){
            cout<<"*";
        }

        cout<<endl;

        starCounter = userInteger - rowCounter;

    }


//At this point the 
//row counter is equal to the userInput+1
//starCounter is equal to 0
//UserInput is unchanged
/*
    for (rowCounter; rowCounter >= 0; rowCounter--){

        for(starCounter; starCounter >= 0; starCounter++){
            cout<<"*";
        }

        cout<<endl;

        starCounter = userInteger - rowCounter;

    }

*/
    return 0;
}