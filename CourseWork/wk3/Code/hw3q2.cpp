#include <iostream>
#include <string.h>
using namespace std;

const int ZERO_YEARS = 0;
const int ONE_YEARS = 1;
const int TWO_YEARS = 2;
const int THREE_YEARS = 3;
const int FOUR_YEARS = 4;

int main(){

    string name;
    string status;
    int graduationYear, currentYear;

    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;

    //Calculate the number of years
    int yearDifference = graduationYear - currentYear;

    //Evaluate the number of years for the correct and output correct response
    if (yearDifference <= ZERO_YEARS){
        cout<<name<<", you are Graduated"<<endl;
    }
    else if (yearDifference == ONE_YEARS){
        cout<<name<<", you are a Senior"<<endl;
    }
    else if (yearDifference == TWO_YEARS){
        cout<<name<<", you are a Junior"<<endl;
    }
    else if (yearDifference == THREE_YEARS){
        cout<<name<<", you are a Sophomore"<<endl;
    }
    else if (yearDifference == FOUR_YEARS){
        cout<<name<<", you are a Freshman"<<endl;
    }
    else {
        cout<<name<<", you are not in college yet"<<endl;
    }

    return 0;
}