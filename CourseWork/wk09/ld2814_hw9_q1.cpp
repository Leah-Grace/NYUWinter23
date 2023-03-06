// UPPERCASE LETTERS 65 - 90
// LOWERCASE LETTERS 97 - 122

#include <iostream>
#include <string>
using namespace std;

int main(){
    int numWords = 1; //declare int to represent word count and instantiate to 1;
    string inputText = "";
    

    //Input: read line of text
    cout<<"Please enter a line of text:"<<endl;
    getline(cin, inputText);

    int stringLength = inputText.length();
    int countUpperLowerCaseLetters = (26 * 2); //count of all upper and lowercase letters
    //int * frequencyArr = new int[countUpperLowerCaseLetters]; //array of int in size of count of all upper and lowercase letters
    int frequencyArr[countUpperLowerCaseLetters] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //interate over the string and evaluate each character in linear time O(n)
    for (int i = 0; i < stringLength; i++){
        //incriment number of words based on non-alphabetical characters and whether or not the next character is a new word (avoid doube counting combinations of special character i.e. ", " or ". ")
        if (inputText[i] == ' ' || inputText[i] == '.' || inputText[i] == ',' || inputText[i] == '\n'){
            if (inputText[i+1]){
                if ((inputText[i+1] >= 65  && inputText[i+1] <= 90) || (inputText[i+1] >= 97 && inputText[i+1] <= 122)){ 
                    numWords++;
                }
            }
        } else if (inputText[i] >= 65 && inputText[i] <= 90){ //if the chatacter is alphabetical AND uppercase
           // cout<<"Character "<<inputText[i]<<" is ascii character "<< int(inputText[i])<<" and it belongs in index "<<int(inputText[i]) - (65)<<" right now the value is "<<frequencyArr[int(inputText[i]) - (65)]<<endl;
            frequencyArr[int(inputText[i]) - (65)] += 1;
        } else if (inputText[i] >= 97 && inputText[i] <= 122){ //if the character is alphabetical AND lowercase
            //cout<<"Character "<<inputText[i]<<" is ascii character "<<int(inputText[i])<<" and it belongs in index "<<int(inputText[i]) - (65 + 7)<<" right now the value is "<< frequencyArr[int(inputText[i]) - (65 + 7)]<<endl;
            frequencyArr[int(inputText[i]) - (65 + 7)] = frequencyArr[int(inputText[i]) - (65 + 7)] + 1;
        }
    }

   cout<<numWords<<" words total."<<endl;

    //interate over int array of letter frequencies with size 52 in linear time O(n) where n - 52
   for (int i = 0; i < countUpperLowerCaseLetters; i++){
    int letterConversion = i; 
        if (frequencyArr[i] > 0){
            if (i < 26){
                letterConversion += 65;
            } else {
                letterConversion += (65 + 7);
            }
            
            cout<<frequencyArr[i]<<"\t"<<(char)letterConversion<<endl;
    }
    
   } 

   delete[] frequencyArr; //delete the array although it is not dynamic?
   
   return 0;
}