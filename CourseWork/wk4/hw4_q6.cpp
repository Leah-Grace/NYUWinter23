//this program prompt the user to input a positive integer n
//the program will print all integers from 1 to n where the integer has more even digits than odd digits

#include <iostream>
#include <string>
using namespace std;


const int EVEN_INTEGER_DIVISOR = 2;

int main(){

    int userInteger; // Must remain unchanged

    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;


    //for each digit (for loop where x increments from 1 to userInteger)
    //find the number of digits in the number (use mod % 10 ?)
    //cycle through the digits (Mod % 10 ?)
    //if the digit is even, push to the string
    //if the digit is odd push to odd string
    //compare the length of the two strings (best not to use .length)
    //print the number if there are more even digits than odd digits

    int counter = 1;
    for (counter; counter < userInteger; counter++){ //iterate from 1 to n


        //count digits
        int oddDigits = 0; 
        int evenDigits = 0;


        //Evaluate the current integer from 1 - n using value from counter
        int currentInteger = counter;

        //Iterate over the digits in the current integer from 1 - n 
        while(currentInteger > 0) {

           // cout<<"current integer "<<currentInteger<<endl;

            //find the current digit with % 10
            int currentDigit = currentInteger % 10;

         //   cout<<"current Digit "<<currentDigit<<endl;

            //evaluate the current digit for even or odd
            if (currentDigit % 2 == 0){
                evenDigits++;
            } else{
                oddDigits++;
            }

           // cout<<"Evaluate for even or odd "<<currentDigit<<endl;
           // cout<<"Progress while loop with "<<currentInteger / 10<<endl;

            //remove the least significant digit of the current integer
            currentInteger /= 10;

        }

        // compare the count of even and odd digits
        // if there are more even digits than odd digits, print the original integer
        if (evenDigits > oddDigits){
            cout<<counter<<" has more even digits "<<endl;
        }

        //reassign even/odd counters back to 0
        evenDigits = 0;
        oddDigits = 0;

       // current integer is 0 and must change to counter

    }

    



    return 0;

}