//this program prompts the user for a sequence of positive integers
//the program calculates and prints the geometric mean using two different approaches

//first version:
//prompts the user for the length of the sequence
//prompts the user for the sequence
//calculates and prints the geometric mean

//Second version
//Prompts the user to enter positive intgers until the sequence is ended with -1
//calculates and prints the geometric mean using a while loop


#include <iostream>
#include <cmath>
using namespace std;

const int END_OF_SEQUENCE = -1;
const int NUMERATOR = 1;

int main (){

    int sequenceLength = 0;

    //First Method : For Loop
    cout<<"Please enter the length of the sequence:"<<endl;
    cin>>sequenceLength;
    cout<<"Please enter your sequence:"<<endl;

    int currentUserInput = 0;
    int inputProduct = 1;
    int iterativeSequenceLength = sequenceLength;

    //iterate through a for loop to store and calculate each input
    for (iterativeSequenceLength; iterativeSequenceLength > 0; iterativeSequenceLength--){
        cin>>currentUserInput;
        inputProduct *= currentUserInput;
    }

    //CALCULATION
    //The nth root is found by multiplying by the power of (1/n)
    double nthRoot = (double)NUMERATOR / sequenceLength;
    double forLoopGeometricMean = pow(inputProduct, nthRoot);

    cout<<"The geometric mean is: "<<forLoopGeometricMean<<endl;


    //Second Method : while loop

    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:"<<endl;
    currentUserInput = 0;
    cin>>currentUserInput; //initialize to first number

    inputProduct = 1;
    int nCounter = 0;

    while (currentUserInput != END_OF_SEQUENCE){ //perform action if input is not -1
        inputProduct *= currentUserInput;
        nCounter++;
        cin>>currentUserInput;
    }

    //CALCULATION
    //The nth root is found by multiplying by the power of (1/n)
    nthRoot = (double)NUMERATOR / nCounter;
    forLoopGeometricMean = pow(inputProduct, nthRoot);

    cout<<"The geometric mean is: "<<forLoopGeometricMean<<endl;

    return 0;
}

