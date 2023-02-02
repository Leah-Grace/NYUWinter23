//this program prompt the user to input a positive integer n
//the program will print all integers from 1 to n where the integer has more even digits than odd digits

#include <iostream>
#include <string>
using namespace std;


const int EVEN_INTEGER_DIVISOR = 2;
const int DECIMAL_DIVISOR = 10;

int main(){

    int userInteger;

    cout<<"Enter a positive integer"<<endl;
    cin>>userInteger;

    int counter = 1;
    for (counter; counter <= userInteger; counter++){ //iterate from 1 to n with counter

        int oddDigitsCount = 0; 
        int evenDigitsCount = 0;

        //Evaluate the current integer from 1 - n using value from counter
        int currentInteger = counter;

        //Iterate over the digits in the current integer with a while loop
        //At the beginning of each while loop the currentInteger will be the same value as the current integer
        //with each iteration of the while loop the least signifiant digit of the current integer will be removed
        //eventually the integer will reach 0 when the most significant digit is divided by 10 
        while(currentInteger > 0) {

            //isolate the lest significant digit of the current integer with % 10
            int currentDigit = currentInteger % DECIMAL_DIVISOR;

            //evaluate the current digit as even or odd and add to count
            if (currentDigit % EVEN_INTEGER_DIVISOR == 0){
                evenDigitsCount++;
            } else{
                oddDigitsCount++;
            }

            //remove the least significant digit of the current integer by dividing the integer by 10
            currentInteger /= DECIMAL_DIVISOR;

        }

        // compare the count of even and odd digits
        // if there are more even digits than odd digits, print the original integer
        if (evenDigitsCount > oddDigitsCount){
            cout<<counter<<endl;
        }

        //reassign even/odd counters back to 0 to evaluate the next value of the counter
        evenDigitsCount = 0;
        oddDigitsCount = 0;

    }

    return 0;

}