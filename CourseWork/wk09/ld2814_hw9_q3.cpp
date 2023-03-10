/*
4 variations of function getPosNums(arr, arrSize)

//int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
//int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
//void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
//void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)



*/
#include <iostream>
#include <string>
using namespace std;

void resizeArray(int *&arr, int currentSize, int newSize);

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

int main(){

    
    int arr[6] = {3, -1, -3, 0, 6, 4};
    int arrSize = sizeof(arr) / 4 ;
    int outPosArrSize = 0;
    

    getPosNums1(arr, arrSize, outPosArrSize);




    return 0;
}

void resizeArray(int *&arr, int currentSize, int newArrSize){

    int *tempArr = new int[newArrSize];

    for(int i = 0; i < currentSize; i++){
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;

}



int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    /*
    returns the base address of the array (containing the positive numbers), 
    updates the output parameter outPosArrSize with the array’s logical size.
    */
     
    int counter = 0;
    
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            outPosArrSize += 1;
            counter++;

        } 
    }

    int newPosArr[counter - 1] = {0};
    counter = 0;
    
    for (int j = 0; j < arrSize; j++){
        if (arr[j] > 0) {
            newPosArr[counter] = arr[j];
            counter++;
        }
    }



    return newPosArr;

}