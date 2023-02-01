//This program will prompt the user for a positive integer, n
//the program will print a tectual image of an hourglass made of 2n lines of asterisks


#include <iostream>
using namespace std;

int main(){

    int userInteger = 0;
    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;

    int rowCounter = userInteger;
    int starCounter = userInteger;
    int totalRows = userInteger * 2;

    cout<<totalRows<<" "<<starCounter<<" "<<rowCounter<<" "<<userInteger<<" "<<endl;

    for(totalRows; totalRows > 0; totalRows--){

        if(totalRows > userInteger){
            
            while (starCounter > 0){
                cout<<"*";

                starCounter--;
            }
            cout<<endl;
            rowCounter--;
            starCounter = rowCounter;

        } else{

            rowCounter++;

            int bottomRowCounter = rowCounter;

            for (starCounter; starCounter < rowCounter; starCounter++){

                for (bottomRowCounter; bottomRowCounter > 0; bottomRowCounter--){

                    cout<<"*";

                }

                cout<<endl;
           
            }

        }
        
    }

    return 0;
    
}