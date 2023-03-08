/*
ANAGRAMS

INPUT: 2 strings
Input handling: Read string 1/Read string 2 getline(cin str1) getline(cin, str2)
//disregard punctuation and spaces
//Apply use q1 function 
//compare str1 to str2, each letter/frequency 
//bool: if != then false
//if true... predict bugs...

return "The two strings" str1 and str2 (T/F) anagrams.

*/



#include <iostream>
#include <string>
using namespace std;

const int  COUNT_LETTERS = 26;

void compareAnagrams(bool &isAnagram, string str1, string str2);
void wordCount(bool &isAnagram, string str1, string str2);
void populateArray(string string, int * arr); //must pass array by reference.


int main(){

    bool isAnagram = true; 

    /*

    string str1 = " ";
    string str2 = " ";

    cout<<"Input a string of characters."<<endl;
    getline(cin, str1);
    cout<<"Input a second string of characters."<<endl;
    getline(cin, str2);
    */

    string str1 = "Eleven pluss two";
    string str2 = "Twelve plus one";
    int frequencyArrStr1[COUNT_LETTERS] = {0};
    int frequencyArrStr2[COUNT_LETTERS] = {0};

    compareAnagrams(isAnagram, str1, str2);

    cout<<" main function"<<endl;

     if (isAnagram){
        cout<<"The two strings are anagrams"<<endl;
    } else {
        cout<<"The two strings are not anagrams"<<endl;
    }


    
    return 0;
}

void compareAnagrams(bool &isAnagram, string str1, string str2){

    wordCount(isAnagram, str1, str2);

}

void wordCount(bool &isAnagram, string str1, string str2){

    int frequencyArr1[COUNT_LETTERS] = {0};
    int frequencyArr2[COUNT_LETTERS] = {0};
    int testArray[COUNT_LETTERS] = {0};

    int str1Length = str1.length();
    int str2Length = str2.length();

//must be separate function: pass string, calculate string length(), populate array
    for (int i = 0; i < str1Length; i++){
        if (str1[i] >= 65 && str1[i] <= 90){ //if the chatacter is alphabetical AND uppercase
            cout<<"Character "<<str1[i]<<" is ascii character "<< int(str1[i] + 32)<<" and it belongs in index "<<int(str1[i]) + (32) - (97)<<" right now the value is "<<frequencyArr1[int(str1[i]) - (65)]<<endl;
            frequencyArr1[int(str1[i]) - (65)] += 1;
        } else if (str1[i] >= 97 && str1[i] <= 122){ //if the character is alphabetical AND lowercase
            cout<<"Character "<<str1[i]<<" is ascii character "<<int(str1[i])<<" and it belongs in index "<<int(str1[i]) - (97)<<" right now the value is "<< frequencyArr1[int(str1[i]) - (65 + 7)]<<endl;
            frequencyArr1[int(str1[i]) - (97)] += 1;
        }
    }

    for (int i = 0; i < str2Length; i++){
        if (str2[i] >= 65 && str2[i] <= 90){ //if the chatacter is alphabetical AND uppercase
            cout<<"Character "<<str2[i]<<" is ascii character "<< int(str2[i] + 32)<<" and it belongs in index "<<int(str2[i]) + (32) - (97)<<" right now the value is "<<frequencyArr2[int(str2[i]) - (65)]<<endl;
            frequencyArr2[int(str2[i]) - (65)] += 1;
        } else if (str2[i] >= 97 && str2[i] <= 122){ //if the character is alphabetical AND lowercase
            cout<<"Character "<<str2[i]<<" is ascii character "<<int(str1[i])<<" and it belongs in index "<<int(str2[i]) - (97)<<" right now the value is "<< frequencyArr2[int(str2[i]) - (65 + 7)]<<endl;
            frequencyArr2[int(str2[i]) - (97)] += 1;
        }
    
    }

    populateArray(str1, testArray);
   // populateArray(str2, frequencyArr2);

   cout<<" Test array: "<<endl;

   for (int j = 0; j < COUNT_LETTERS; j++){
    cout<<testArray[j]<<endl;
   }



    for (int i = 0; i < COUNT_LETTERS; i++){

        if (frequencyArr1[i] != frequencyArr2[i]){
            isAnagram = false;
        }
    }

}

void populateArray(string string, int * arr){

    int strLength = string.length();

    for (int i = 0; i < strLength; i++){
        if (string[i] >= 65 && string[i] <= 90){ //if the chatacter is alphabetical AND uppercase
            cout<<"Character "<<string[i]<<" is ascii character "<< int(string[i] + 32)<<" and it belongs in index "<<int(string[i]) + (32) - (97)<<" right now the value is "<<arr[int(string[i]) - (65)]<<endl;
            arr[int(string[i]) - (65)] += 1;
        } else if (string[i] >= 97 && string[i] <= 122){ //if the character is alphabetical AND lowercase
            cout<<"Character "<<string[i]<<" is ascii character "<<int(string[i])<<" and it belongs in index "<<int(string[i]) - (97)<<" right now the value is "<< arr[int(string[i]) - (65 + 7)]<<endl;
            arr[int(string[i]) - (97)] += 1;
        }
    }



}