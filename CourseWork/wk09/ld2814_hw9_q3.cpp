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

const int ARR_SIZE = 6;

//void resizeArray(int *&arr, int currentSize, int newSize);

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void printNonStaticArray(int arr[], int arrSize);

int main(){

    int arr[ARR_SIZE] = {3, -1, -3, 0, 6, 4};
    cout<<"Initial Array: ";
    printNonStaticArray(arr, ARR_SIZE);

  //FUNCTIONS  
    int outPosArrSize = 0;
    //int* posNums1 = getPosNums1(arr, ARR_SIZE, outPosArrSize);

    int outPosArrSizePtr; 
    //int* posNums2 = getPosNums2(arr, ARR_SIZE, &outPosArrSizePtr);

    int *outPosArr3 = nullptr;
    int outPosArrSize3 = 0;
    //getPosNums3(arr, ARR_SIZE, outPosArr3, outPosArrSize3);

    int outPosArrSizePtr4;
    int* outPosArrPtr4 = nullptr;
    printNonStaticArray(arr, ARR_SIZE);
    getPosNums4(arr, ARR_SIZE, &outPosArrPtr4, &outPosArrSizePtr4);

//TESTS
    cout<<"Function 1: "<<endl;
    //printNonStaticArray(posNums1, outPosArrSize);
    cout<<"Function 2: "<<endl;
    //printNonStaticArray(posNums2, outPosArrSizePtr);
    cout<<"Function 3: "<<endl;
    //printNonStaticArray(outPosArr3, outPosArrSize3);
    cout<<"Function 4: "<<endl;
    printNonStaticArray(&outPosArrSizePtr4, outPosArrSizePtr4);



    //delete [] posNums1;
    //delete [] posNums2;
    //delete [] outPosArr3;
    delete [] outPosArrPtr4;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    /*
    returns the base address of the array (containing the positive numbers), 
    updates the output parameter outPosArrSize with the array’s logical size.
    */
    int posNumsArr1Size = 0;
    int *posNumsArr1 = new int[arrSize];

    printNonStaticArray(posNumsArr1, arrSize); //This array has length 6 but within scope of main it will have size 3

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posNumsArr1[posNumsArr1Size++] = arr[i];
        } 
    }

    outPosArrSize = posNumsArr1Size;

    return posNumsArr1;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
/* returns the base address of the array (containing the positive numbers), 
uses the pointer outPosArrSizePtr to update the array’s logical size.
*/
    int posNumsArr2Size = 0;
    int *posNumsArr2 = new int[arrSize];

    printNonStaticArray(posNumsArr2, arrSize);
    

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posNumsArr2[posNumsArr2Size++] = arr[i];
        }

    }

    *outPosArrSizePtr = posNumsArr2Size;

    printNonStaticArray(posNumsArr2, posNumsArr2Size);

    return posNumsArr2;

}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){

    int posNumsCount = 0;
    int *posNumsArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posNumsArr[posNumsCount++] = arr[i];
        }
    }

    printNonStaticArray(posNumsArr, posNumsCount);

    outPosArr = posNumsArr;
    outPosArrSize = posNumsCount;

}
/*
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int posNumsCount = 0;
    int* posNumsArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posNumsArr[posNumsCount++] = arr[i];
        }
    }

    *outPosArrPtr = posNumsArr;
    *outPosArrSizePtr = posNumsCount;

}
*/

void getPosNums4(int* arr, int arr_size, int** out_pos_arr_ptr, int* out_pos_arr_size_ptr) {
    int pos_count = 0;
    int* pos_nums = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > 0) {
            cout<<arr[i]<<" is positive"<<endl;
            pos_nums[pos_count++] = arr[i];
        }
    }

    printNonStaticArray(pos_nums, pos_count);

    *out_pos_arr_ptr = pos_nums;
    *out_pos_arr_size_ptr = pos_count;
}






void printNonStaticArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/*
void printNonStaticArray(int *arr, int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout<<arr[i]<<endl;
    }
}

*/