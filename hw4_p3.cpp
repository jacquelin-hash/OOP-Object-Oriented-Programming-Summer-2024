/*
Author: [Jacqueline Guimac] 
Assignment: HW4 
Date due: 06 20
I pledge that I have completed this assignment without the use of AI tools 
or collaborating with anyone else, in conformance with the NYU School of Engineering Policies 
and Procedures on Academic Misconduct. 
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums;
    cout << "Enter student grades (-1 to stop):\n";
    
    // Input grades from the user until -1 is entered
    for (int num; cin >> num && num != -1; ) {
        nums.push_back(num);
    }

    // Check if any grades were entered
    if (nums.empty()) {
        cout << "No grades were entered.\n";
        return 0;
    }

    // Sort the grades
    sort(nums.begin(), nums.end());

    // Determine the maximum grade
    int maxGrade = nums.back();

    // Create a dynamic array (vector) for histogram
    vector<int> histogram(maxGrade + 1, 0);

    // Populate the histogram
    for (int grade : nums) {
        ++histogram[grade];
    }

    // Print the histogram
    for (int i = 0; i <= maxGrade; ++i) {
        if (histogram[i] > 0) {
            cout << "Number of " << i << "s: " << histogram[i] << '\n';
        }
    }

    return 0;
}

// notes for myself
// have a vector of grades,you will get a minimum value of 0 
// and max value of the grade is by the value 
// what they are asking here is to store the maximum value
// need to go thru every element of the vector (so sorting algorithm merge sort or quick sort maybe....)
// and store the value 
// store 30,1
// use a dynamic array in some type of shape and form 