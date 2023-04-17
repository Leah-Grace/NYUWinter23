#include <iostream>
using namespace std;

    const int ARR_SIZE = 10;

int minAtIndexOf(int arr[], int startIndex, int lastIndex){
    int temp = arr[startIndex];
    int minIndex = startIndex;
    for (int i = (startIndex + 1); i <= lastIndex; i++){
        if (arr[i] < temp){
            minIndex = i;
            temp = arr[i];
        }
    }
    cout << "The minimum is at index: " << minIndex << " the value is :" << arr[minIndex] << endl;
    return minIndex;
}

void selectionSort(int (&arr)[ARR_SIZE], int arrSize){
    int last = (arrSize - 1);
    for (int i = 0; i < arrSize; i++){
        int indexMin = minAtIndexOf(arr, i, last);
        swap(arr[i], arr[indexMin]);
    }
}

void printArr(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << "[ " << arr[i] << " ], ";
    }
    cout << endl;
}

int main(){

    int arr[ARR_SIZE] = {10, 0, 3, 45, 1, 7, 4, 8, 2, 12};
    selectionSort(arr, ARR_SIZE);
    printArr(arr, ARR_SIZE);

    return 0;
}