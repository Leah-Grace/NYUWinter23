//this program prompts the user for a positive integer in decimal notation
//the program will convert the decimal representation to binary and print the result

#include <iostream>
#include <string>
using namespace std;

const int BINARY_MULTIPLIER = 2;

int main(){

    int userDecimal = 0;
    cout<<"Enter decimal number:"<<endl;
    cin>>userDecimal;


    //successive division will return remainder, each remainter would be a binary decimal


    int tempDecimal = userDecimal;
    int binaryRepresentation = 0;

    //POWERS OF 2
    //  2^0 == 1  |  2^1 == 2 |  2^2 == 4 |  2^3 == 8 |  2^4 == 16 |  2^



    while (tempDecimal > 0){
        

        int currentDigit = tempDecimal % 2; //Remainder is first digit

        tempDecimal = tempDecimal / 2; //Result is the next number to divide

        cout<<"Current Decimal "<<currentDigit<<endl;

    }



    cout<<"The binary representation of "<<userDecimal<<" is "<<binaryRepresentation<<endl;


    return 0;
}
