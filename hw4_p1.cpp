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
// Problem 1 

// Function Prototyping
void reverseString(char* intStr);

int main() {
    // Test cases
    char str1[] = "hello";
    char str2[] = "world!";
    char str3[] = "Hello World";

    cout << "Original: " << str1 << endl;
    reverseString(str1);
    cout << "Reversed: " << str1 << endl << endl;

    cout << "Original: " << str2 << endl;
    reverseString(str2);
    cout << "Reversed: " << str2 << endl << endl;

    cout << "Original: " << str3 << endl;
    reverseString(str3);
    cout << "Reversed: " << str3 << endl;

    return 0;
}

// reverses the given string in place 
// a pointer to a chracter array (C-string) to be reversed 
// does not return a value 
void reverseString(char* inStr){ 
    char* front = inStr;
    char* rear = front + strlen(inStr) - 1;

    // for loop to swap characters from the front and rear of the string
    for(int  i = 0; i < strlen(inStr)/2; i++ ){
        // Swaps the characters 
        char temp = *front; // the next three lines are swapping 
        *front = *rear; 
        *rear = temp;
        front++;
        rear--;
    }
}


/*
Notes for myself 

Using two pointers 
one pointer starts at the beginning (front)
second pointer starts at the end (rear)
the function should use two pointers (front,end)

one character in the front pointer the rear pointer is the length of the string - 1
*/