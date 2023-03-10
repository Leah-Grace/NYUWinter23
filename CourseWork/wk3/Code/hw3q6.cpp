//This program calculates the cost of a long-distance call
//The user is prompted to input the day of the week, the time the call started and the length of the call in minutes

#include <iostream>
#include <string>
using namespace std;

const float WEEKDAY_RATE = 0.4;
const float WEEKNIGHT_RATE = 0.25;
const float WEEKEND_RATE = 0.15;

int main(){

    char colon;
    string day;
    int start, length, minutes;
    float total_cost;

    cout<<"Please input the day of the week: ";
    cin>>day;
    cout<<"Please input the time that the call started: ";
    cin>>start >> colon >> minutes;
    cout<<"Please input the length of time of the call in minutes: ";
    cin>>length;

    //Evaluate day and start time to determine with rate to calculate cost
    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr"){
        if (start >= 8 && start <= 18){
            total_cost = length * WEEKDAY_RATE;
        }
        else{
            total_cost = length * WEEKNIGHT_RATE;
        }
    }
    else if (day == "Sa" || day == "Su"){
        total_cost = length * WEEKEND_RATE;
    }
    else{

        cout<<"Couldn't understand day"<<endl;

        //end program since cost of call could not be calculated
        return 0;
    }

    cout<<"Cost of call: $"<<total_cost<<endl;

    return 0;
}