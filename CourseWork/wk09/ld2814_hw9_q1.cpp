
#include <iostream>
#include <string>
using namespace std;

const int  COUNT_LETTERS = 26; //count of all upper and lowercase letters

int main(){
    int numWords = 1; //declare int to represent word count and instantiate to 1;
    string inputText = "";
    

    //Input: read line of text
    cout<<"Please enter a line of text:"<<endl;
    getline(cin, inputText);

    int stringLength = inputText.length();
    int frequencyArr[COUNT_LETTERS] = {0};

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
            //cout<<"Character "<<inputText[i]<<" is ascii character "<< int(inputText[i] + 32)<<" and it belongs in index "<<int(inputText[i]) + (32) - (97)<<" right now the value is "<<frequencyArr[int(inputText[i]) - (65)]<<endl;
            frequencyArr[int(inputText[i]) - (65)] += 1;
        } else if (inputText[i] >= 97 && inputText[i] <= 122){ //if the character is alphabetical AND lowercase
            //cout<<"Character "<<inputText[i]<<" is ascii character "<<int(inputText[i])<<" and it belongs in index "<<int(inputText[i]) - (97)<<" right now the value is "<< frequencyArr[int(inputText[i]) - (65 + 7)]<<endl;
            frequencyArr[int(inputText[i]) - (97)] += 1;
        }
    }

   cout<<numWords<<" words total."<<endl;

    //interate over int array of letter frequencies with size 52 in linear time O(n) where n - 52
   for (int i = 0; i < COUNT_LETTERS; i++){
    int letterConversion = i; 
        if (frequencyArr[i] > 0){
            letterConversion += (97);
            cout<<frequencyArr[i]<<"\t"<<(char)letterConversion<<endl;
        }
    
   } 
   
   return 0;
}