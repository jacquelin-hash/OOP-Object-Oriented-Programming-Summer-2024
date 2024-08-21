/*
Author: [Jacqueline Guimac] 
Assignment: HW1 
Date due: 06 06
I pledge that I have completed this assignment without the use of AI tools or 
collaborating with anyone else, in conformance with the NYU School of Engineering 
Policies and Procedures on Academic Misconduct. 
*/ 
#include <iostream> 
#include <cmath>

using namespace std;
class Measure{

public:
    // default Constructor
    Measure(): inches(0),feet(0){}

    // constructor with total inches 
    Measure(int user_inches){
        feet = user_inches / 12;
        inches = user_inches % 12;
        if (inches < 0){
            inches += 12;
            feet -= 1;
        }
    }
    // setter for feet 
    void setFeet(int ft){
        feet = ft;
    }
    
    // setter for inches 
    void setInches(int inch){
        feet += inch / 12;
        inches = inch % 12;
        if (inches < 0){
            inches += 12;
            feet -= 1;
        }
    }
    // getter for feet
    int getFeet() const{
        return feet;
    }
    // getter for inches 
    int getInches() const{
        return inches;
    }
    // displaying the measurements accord to assignemnt 
    void display() const{
        cout << feet << " feet, " << inches << " inches" << endl;
    }
private:
    int feet;
    int inches;
};


int main(){
    // execution 1
    Measure m1;
    m1.display();

    // execution 2
    Measure m2(25);
    m2.display();

    
    Measure m3(130);
    m3.display();

    // execution 3
    m2.setFeet(-2);
    m2.display();

    m3.setInches(30);
    m3.display();

    m3.setInches(-25);
    m3.display();

    return 0;
}
// cannot intialize with negatives 
// maybe with using cmath not entirely sure 
