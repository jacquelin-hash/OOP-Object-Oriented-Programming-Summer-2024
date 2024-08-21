/*
Author: [Jacqueline Guimac] 
Assignment: HW1 
Date due: 05 30
I pledge that I have completed this assignment without the use of AI tools or 
collaborating with anyone else, in conformance with the NYU School of Engineering 
Policies and Procedures on Academic Misconduct. 
*/ 

#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

/*
Question 1
Design a C++ function named isInVector that efficiently determines 
whether a given integer exists within a provided vector or array of 
integers. The function should accept two parameters: the vector/array 
of integers and the integer to search for. It should return a boolean 
value indicating whether the searched integer is present in the provided 
data structure
*/

bool isInVector(const std::vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return true; 
        }
    }
    return false;  
}

// quesiton 2
#include <iostream>
#include <vector>
#include <algorithm>


void makeUnique(const std::vector<int>& inputVector, std::vector<int>& uniqueVector) {
    std::vector<int> tempVector; 
    for (int value : inputVector) {
        if (std::find(tempVector.begin(), tempVector.end(), value) == tempVector.end()) {
            tempVector.push_back(value); 
        }
    }
    uniqueVector = tempVector; 
}

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

/*
Question 3
Implement a C++ function called fillVectFromFile designed to populate a
vector or array of integers with data retrieved from a user-selected input 
file. The function prompts the user for a file name and ensures that the file 
opens correctly before proceeding. If the file fails to open, the function terminates 
gracefully without any further execution.
*/
void fillVectFromFile(std::vector<int>& vec);
void printVectorData(const std::vector<int>& vec);

void fillVectFromFile(std::vector<int>& vec) {
    std::ifstream ifs;
    std::string filename;
    
    while (true) {
        std::cout << "Enter the file name: ";
        std::cin >> filename;
        
        ifs.open(filename);
        if (ifs) {  
            break;  
        } else {
            std::cout << "Failed to open file '" << filename << "'. Please try again.\n";
        }
    }

    int number;
    while (ifs >> number) {
        vec.push_back(number);
    }

    ifs.close();  
}


void printVectorData(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << std::endl;
    }
}

/*
Question 4
Using the functions created in the tasks above, 
solve the following problem: Obtain a set of integers 
stored in a file specified by the user. Write these integers 
into a file named unique_ints, ensuring that duplicate entries
are eliminated.
Your main function should solely create variables and call functions 
to address the problem. There must be NO INPUT and NO OUTPUT within 
the main function.
*/

void fillVectFromFile(std::vector<int>& vec, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    int num;
    while (file >> num) {
        vec.push_back(num);
    }
    file.close();
}

void makeUnique(const std::vector<int>& input, std::vector<int>& unique) {
    std::set<int> seen; 
    for (int num : input) {
        if (seen.insert(num).second) {
            unique.push_back(num);
        }
    }
}

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


