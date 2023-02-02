//this program prompt the user to input a positive integer n
//the program will print all integers from 1 to n where the integer has more even digits than odd digits

#include <iostream>
#include <string>
using namespace std;


const int EVEN_INTEGER_DIVISOR = 2;

int main(){

    int userInteger;

    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;

    //for each digit (for loop where x increments from 1 to userInteger)
    //find the number of digits in the number (use mod % 10 ?)
    //cycle through the digits (Mod % 10 ?)
    //if the digit is even, push to the string
    //if the digit is odd push to odd string
    //compare the length of the two strings (best not to use .length)
    //print the number if there are more even digits than odd digits

        int oddDigits = 0;
        int evenDigits = 0;

        int currentInteger = userInteger;

        while(currentInteger > 0) {

            int currentDigit = currentInteger % 10;

            cout<<"Evaluate for even or odd "<<currentDigit<<endl;
            cout<<"Progress while loop with "<<currentInteger / 10<<endl;

            currentInteger /= 10;

            cout<<currentInteger<<endl;
            
        }

    



    return 0;

}