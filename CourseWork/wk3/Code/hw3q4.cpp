#include <iostream>
using namespace std;

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    const int FIRST = 1;
    const int SECOND = 2;
    const int THIRD = 3;
    const double HALF = 0.5;

int main(){

    float userNum;
    int userChoice;

    cout<<"Please enter a Real number:"<<endl;
    cin>>userNum;
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>userChoice;

        int roundNum;

        switch(userChoice){
            case 1:
            {
                //store float as integer and 
                roundNum = userNum;
                break;
            }
            case 2:
            {
                roundNum = (userNum + HALF);
                break;
            }
            case 3:
            {
                int wholeNum = userNum;
                if ((userNum - wholeNum) < HALF){
                    roundNum = userNum;
                }
                else {
                    roundNum = (userNum + HALF);
                }    
                break;
            }
            default:
                cout<<"Sorry, that was not an option."<<endl;
                return 0;
        }
        cout<<roundNum<<endl;

    return 0;
}