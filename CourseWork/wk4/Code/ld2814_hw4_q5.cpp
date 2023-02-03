//This program will prompt the user for a positive integer, n
//the program will print a textual image of an hourglass made of 2n lines of asterisks


#include <iostream>
using namespace std;

const char STAR = '*';
const char SPACE = ' ';


int main(){

    int userInteger = 0;
    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;

    int rows = userInteger;
    int starCounter = (2 * userInteger) - 1;
    int spaces = 0;

    //Iterate from n to 0 to print each row in the top half 
    while (rows > 0 ){
        //Print spaces where necessary
        if(spaces > 0){
            for (int i = spaces; i >= 1; i--){
                cout<<SPACE;
            }
        }

        //Print stars
        for (int j = starCounter; j > 0; j--){
            cout<<STAR;       
        }

        cout<<endl; 

        //Decriment the count of stars by 2 but do not allow the value to decrease below 1
        if (starCounter > 1){
            starCounter -= 2;
        }
        
        spaces++;
        rows--;
    }

    //Print the bottom half of the pyramid
    while (rows < userInteger){

        //Print spaces when neccesary
        for (int k = spaces; k > 1; k--){
            cout<<SPACE;
        }

        //Print stars
        for (int l = 0; l < starCounter; l++){
            cout<<STAR;
        }

        cout<<endl;
        starCounter += 2;
        spaces--;
        rows++;

    }

    return 0; 
}
