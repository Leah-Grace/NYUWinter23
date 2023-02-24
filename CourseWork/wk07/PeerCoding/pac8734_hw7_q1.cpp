#include<iostream>
#include<string>
using namespace std;

const string TAB = "\t";

int printMonthCalendar(int numOfDays, int startingDay);
bool leapYear(int year);
void printYearCalendar(int year, int startingDay);


int main() {
    int startingDay;
    int year;

    cout<<"What is the starting date position (1 for Monday, 2 for Tuesday, etc.)?"<<endl;
    cin>>startingDay;
    cout<<"What is the year?"<<endl;
    cin>>year;
    printYearCalendar(year, startingDay);
}


// Part A
int printMonthCalendar(int numOfDays, int startingDay) {
    cout<<"Mon"<<TAB<<"Tue"<<TAB<<"Wed"<<TAB<<"Thr"<<TAB<<"Fri"<<TAB<<"Sat"<<TAB<<"Sun"<<endl;
    int dayOfWeek = 1;
    int endDate = 0;
    int nextMonthStartDate;
    for(int i =1 ; i <= 6; i++) {
        for(int j = 1; j <= 7; j++) {
            if(i == 1 && j < startingDay) { // there are unnecessary lines skipped
                cout<<TAB;
            } else if (dayOfWeek < numOfDays) {
                cout<<dayOfWeek<<TAB;
                dayOfWeek++;
            } else if (dayOfWeek == numOfDays) {
                cout<<dayOfWeek<<endl;
                dayOfWeek++;
                return j + 1;
            }
        }
        cout<<endl;
    }
}

// Part B
bool leapYear(int year) {
    bool leap = false;
    if(year % 4 == 0 && year % 100 != 0) {
        leap = true;
    } else if(year % 4 == 0 && year % 400 == 0) {
        leap = true;
    }
    return leap;
}

// Part C
void printYearCalendar(int year, int startingDay) {
    int numOfDays;
    for(int i = 1; i <= 12; i++) {
        switch(i) {
            case 1:
                cout<<"January "<<year<<endl;
                numOfDays = 31;
                break;
            case 2:
                cout<<"February "<<year<<endl;
                if (leapYear(year) == true) {
                    numOfDays = 29;
                } else {
                    numOfDays = 28;
                }
                break;
            case 3:
                cout<<"March "<<year<<endl;
                numOfDays = 31;
                break;
            case 4:
                cout<<"April "<<year<<endl;
                numOfDays = 30;
                break;
            case 5:
                cout<<"May "<<year<<endl;
                numOfDays = 31;
                break;
            case 6:
                cout<<"June "<<year<<endl;
                numOfDays = 30;
                break;
            case 7:
                cout<<"July "<<year<<endl;
                numOfDays = 31;
                break;
            case 8:
                cout<<"August "<<year<<endl;
                numOfDays = 31;
                break;
            case 9:
                cout<<"September "<<year<<endl;
                numOfDays = 30;
                break;
            case 10:
                cout<<"October "<<year<<endl;
                numOfDays = 31;
                break;
            case 11:
                cout<<"November "<<year<<endl;
                numOfDays = 30;
                break;
            case 12:
                cout<<"December "<<year<<endl;
                numOfDays = 31;
                break;
        }
        startingDay = printMonthCalendar(numOfDays, startingDay);
        if (startingDay > 7 ){
            startingDay = (startingDay % 7);
        }
        cout<<endl;
    }
}

