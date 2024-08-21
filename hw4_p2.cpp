/*
Author: [Jacqueline Guimac] 
Assignment: HW4 
Date due: 06 20
I pledge that I have completed this assignment without the use of AI tools 
or collaborating with anyone else, in conformance with the NYU School of Engineering Policies 
and Procedures on Academic Misconduct. 
*/ 
#include <iostream>
#include <string>
using namespace std;

// new array will be current size + 1
// will go through every element and will be checking if the current element is less than the element in that
// position 
// you will check if the new int value is greater or less than the new value 

// like insertion sort 

// Function Prototype 
void insertAndSort(int*& arr,int& size,int newInt);

int main() {
    // Sample execution
    int size = 5;
    int* arr = new int[size]{1, 3, 5, 7, 9};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newInt = 6;
    insertAndSort(arr, size, newInt);

    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    // Clean up
    // add you cleaning up code here;
    delete []arr;

    return 0;
}

// Function Definition 
void insertAndSort(int*& arr,int& size,int newInt){
    // create a new array will be the current size + 1
    int* newArr = new int[size + 1];
    int latest_index = 0;
    // iterate thru every item in the array
    for(int i = 0; i < size; i++){
        newArr[latest_index] = arr[i];
        ++ latest_index;
        if (arr[i] < newInt && newInt < arr[i+1]) {
            newArr[latest_index] = newInt;
            ++ latest_index;
        }
        // newArr[latest_index] = arr[i];
        // ++ latest_index;
    }
    delete [] arr; // deallocating old array 
    arr = newArr;
    ++ size;
}
