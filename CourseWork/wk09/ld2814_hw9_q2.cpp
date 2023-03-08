#include <iostream>
#include <string>
using namespace std;

const int  COUNT_LETTERS = 26;

void compareAnagrams(bool &isAnagram, string str1, string str2);
void charCount(bool &isAnagram, string str1, string str2);
void populateArray(string string, int * arr); //must pass array by reference.


int main(){

    bool isAnagram = true; 
    string str1 = " ";
    string str2 = " ";

    cout<<"Input a string of characters."<<endl;
    getline(cin, str1);
    cout<<"Input a second string of characters."<<endl;
    getline(cin, str2);

    compareAnagrams(isAnagram, str1, str2);

    return 0;
}

void compareAnagrams(bool &isAnagram, string str1, string str2){

    charCount(isAnagram, str1, str2);

    if (isAnagram){
        cout<<"The two strings are anagrams"<<endl;
    } else {
        cout<<"The two strings are not anagrams"<<endl;
    }
}

void charCount(bool &isAnagram, string str1, string str2){

    int frequencyArr1[COUNT_LETTERS] = {0};
    int frequencyArr2[COUNT_LETTERS] = {0};
    int testArray[COUNT_LETTERS] = {0};

    int str1Length = str1.length();
    int str2Length = str2.length();

    populateArray(str1, frequencyArr1);
    populateArray(str2, frequencyArr2);

    for (int i = 0; i < COUNT_LETTERS; i++){
        if (frequencyArr1[i] != frequencyArr2[i]){
            isAnagram = false;
            return;
        }
    }
}

void populateArray(string string, int * arr){

    int strLength = string.length();

    for (int i = 0; i < strLength; i++){
        if (string[i] >= 65 && string[i] <= 90){ //if the chatacter is alphabetical AND uppercase
            arr[int(string[i]) - (65)] += 1;
        } else if (string[i] >= 97 && string[i] <= 122){ //if the character is alphabetical AND lowercase
            arr[int(string[i]) - (97)] += 1;
        }
    }
}