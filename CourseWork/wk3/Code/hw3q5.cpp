//This program returns a weight status correlating to a BMI Range
// The program calculates a human's BMI by prompting the user to input a weight in pounds and a height in inches
// The BMI is calculated and evaluated against the BMI Ranges
// A BMI range is returned


#include <iostream>
#include <string>
using namespace std;

const float POUND_CONVERSION = 0.453592;
const float INCH_CONVERSION = 0.0254;

int main(){

    int weight, height;
    string status;
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<"Please enter height (in inches): ";
    cin>>height;

    //Convert height and weight
    float kilos = weight * POUND_CONVERSION;
    float meters = height * INCH_CONVERSION;

    //Calculate BMI
    float bmi = kilos / (meters * meters);

    //Evaluate BMI for Weight Status
    if (bmi < 18.5){
        status = "Underweight";
    }
    else if (bmi >= 18.5 && bmi <= 25){
        status = "Normal";
    }
    else if (bmi >= 25 && bmi <= 30){
        status = "Overweight";
    }
    else {
        status = "Obese";
    }
    
    cout<<"The weight status is: "<<status<<endl;

    return 0;
}