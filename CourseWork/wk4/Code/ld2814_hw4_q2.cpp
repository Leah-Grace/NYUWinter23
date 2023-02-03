//This program reads an decimal number from the user and prints it’s representation in the simplified Roman numerals system.

#include <iostream>
using namespace std;
#include <string>


int main(){

    int userSelectedDecimal = 0;
    cout<<"Enter decimal number:"<<endl;
    cin>>userSelectedDecimal;
    
    //begin output
    cout<<userSelectedDecimal<<" is ";

    //save to temp integer for destructive purposes
    int tempDecimal = userSelectedDecimal; 

    //'M' can apprear an unlimited number of times so cycle through the number with a while loop
    //Output an 'M' for each 1000 and remove the value from the temp integer
    //the loop ends when the number is less than 1000
    while (tempDecimal >= 1000){
        cout<<"M";
        tempDecimal -= 1000;
    }

    //Since 'D' can only apear once the temp integer is evaluated with an if statment
    if (tempDecimal >= 500){
        cout<<"D";
        tempDecimal -= 500;
    }

    //create a variable that will limit the number of times ‘C’, ‘X’ and ‘I’ can appear
    int limitFour = 4;

    while(tempDecimal >= 100 && limitFour > 0){
        cout<<"C";
        tempDecimal -= 100;
        limitFour--;
    }

    limitFour = 4; //set the limit back to 4

    //evaluate 'L' with an if statement since it can only appear once
    if (tempDecimal >= 50){
        cout<<"L";
        tempDecimal -= 50;
    } 

    //evaluate 'X' with a while loop since it can appear 4 times
    while(tempDecimal >= 10 && limitFour > 0){
        cout<<"X";
        tempDecimal -= 10;
        limitFour--;
    }

    limitFour = 4;

    if (tempDecimal > 5){
        cout<<"V";
        tempDecimal -= 5;
    } 

    //evaluate 'I' with while loop since it can appear up to 4 times
    while (tempDecimal >= 1 && limitFour > 0){
        cout<<"I";
        tempDecimal -= 1;
    }

    //End output
    cout<<endl;

    return 0;
}