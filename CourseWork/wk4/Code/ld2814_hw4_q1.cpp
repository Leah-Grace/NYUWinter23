//This program reads a positive integer n from the user 
//The program will print even integers using a while loop
//The number of even integers printed will be equal to n, the number input from the user
//The program prompts the user for a second positive integer
//The program will use a for loop to print n even integers 
//The count of the printed integers will be equal to the number provided by the user

#include <iostream>
using namespace std;

const int EVEN_NUMBER_MULTIPLIER = 2;

int main(){

    //obtain input from user
    int userSelectedInput;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>userSelectedInput;

    int counter = 1;
    //iterate through while loop from 1 - n with counter and increment eah time 
    while (counter <= userSelectedInput){
        cout<<counter * EVEN_NUMBER_MULTIPLIER<<endl;
        counter++;
    }

    //Set counter back to 1 in preparation for second loop
    counter = 1;

    //
    cout<<"Please enter a positive integer: "<<endl;
    cin>>userSelectedInput;

    //iterate through for loop from 1 - n using the counter
    for (counter; counter <= userSelectedInput; counter++){
        cout<<counter * EVEN_NUMBER_MULTIPLIER<<endl;
    }

    
    return 0;
}