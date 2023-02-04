////this program prompts the user for a positive integer in decimal notation
//the program will convert the decimal representation to binary and print the result

#include <iostream>
using namespace std;


int main(){

    int userDecimal = 0;
    cout<<"Enter decimal number:"<<endl;
    cin>>userDecimal;

    int tempDecimal = userDecimal;
    int binaryRepresentation = 0;
    int powerOfTwo = 1;
    int multiplier = 2;

    cout<<"The binary representation of "<<tempDecimal<<" is ";

    //calculate the the first power of two that exceeds the value of the decimal
    while (multiplier < tempDecimal){

        multiplier *= 2;
        powerOfTwo++;

    } 

    //if the decimal is a power of two print the first and last "1"
    if (multiplier == tempDecimal){

        cout<<"1";
        tempDecimal -= multiplier;
        powerOfTwo--;

    } else { //if the decimal is not a power of two print the first "1" 

            multiplier /= 2;
            powerOfTwo--;
            cout<<"1";
            tempDecimal -= multiplier;
            multiplier /= 2;
            powerOfTwo--;

    }



    while (tempDecimal > 1){


        while (multiplier > tempDecimal && tempDecimal > 1){

            cout<<"0";
            multiplier /= 2;
            powerOfTwo--;

        }

        while (multiplier <= tempDecimal && tempDecimal > 1){

            cout<<"1";

            tempDecimal -= multiplier;
            multiplier /= 2;
            powerOfTwo--;

        }


    }

    //if the remaining binary integers are "0" print one for each ramainig power of 2
    while (powerOfTwo >= 1){
        powerOfTwo--;
        cout<<"0";
    }

        //evaluate the last digit
        if (tempDecimal == 1){

            cout<<"1";

            return 0;


        } else {

            cout<<"0";

        }


    cout<<endl;


    return 0;
}