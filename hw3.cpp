/*
Author: [Jacqueline Guimac] 
Assignment: HW3
Date due: 06 15
I pledge that I have completed this assignment without the use of AI tools 
or collaborating with anyone else, in conformance with the NYU School of Engineering Policies 
and Procedures on Academic Misconduct. 
*/ 

#include "Money.cpp"
#include <iostream>
#include <vector>
using namespace std;

/* CLASS: Check */
class Check{
    // output operator
    friend ostream& operator<<(ostream& os, Check& check);
public:
    // constructor
    Check(int num, int amount, bool status);

    // getter for cashing status
    bool getStatus() const;
    // getter for checkAmount value
    double getValue();
private:
    int checkNumber;
    Money checkAmount;
    bool isCashed;
};


/* FUNCTION DECLARATIONS */
double calculateTotalCashed(vector<Check>& checks); // Calculate money cashed from acc
double calculateTotalDepsited(vector<double> deposits); // Calculate money deposited into acc
void displayChecks(vector<Check>& checks); // Display all checking info


/* MAIN */
int main() {
    // variables
    vector<Check> checks;
    vector<double> depositAmounts;
    double oldBalance;
    double newBalance;


    // gather user data
    cout << "Enter old account balance: ";
    cin >> oldBalance;

    cout << "Enter the number of deposits: ";
    int numDeposits;
    cin >> numDeposits;
    
    cout << "Enter deposit amounts: ";
    int amount;
    for (int i = 0; i < numDeposits; ++i) {
        cin >> amount;
        depositAmounts.push_back(amount);
    }

    cout << "Enter the number of checks: ";
    int numChecks;
    cin >> numChecks;

    cout << "Enter check details (number, amount, cashed status) one by one: " << endl;
    for (int i = 0; i < numChecks; ++i) {
        int checkNumber;
        double checkAmount;
        int isCashed;
        cin >> checkNumber >> checkAmount >> isCashed;
        checks.emplace_back(checkNumber, checkAmount, isCashed);
    }

    cout << "Enter the new account balance reported by the bank: ";
    cin >> newBalance;


    // calculations
    double totalCashed = calculateTotalCashed(checks);
    cout << "Total value of cashed checks: $" << totalCashed << ".00\n";

    double totalDeposited = calculateTotalDepsited(depositAmounts);
    cout << "Total deposit amount: $" << totalDeposited << ".00\n";

    double projNewBalance = (oldBalance + totalDeposited) - totalCashed;
    cout << "Projected new balance: $" << projNewBalance << ".00\n";

    double variance = newBalance - projNewBalance;
    cout << "Variance from the bank's reported new balance: "
         << (variance < 0 ? "-$" : "$") << abs(variance) << ".00\n";


    // display checking info
    displayChecks(checks);
}


/* CHECK IMPLEMENTATION CODE */
ostream& operator<<(ostream& os, Check& check) {
    os << "Check Number: " << check.checkNumber
        << ", Amount: ";
    check.checkAmount.output(os);
    os << ", Cashed Status: " << (check.isCashed ? "Cashed" : "Uncashed");
    return os;
}
Check::Check(int num, int amount, bool status) : checkNumber(num), checkAmount(amount), isCashed(status) {}
bool Check::getStatus() const { return isCashed; }
double Check::getValue() { return checkAmount.getValue(); }


/* FUNCTION DEFINITIONS */
double calculateTotalCashed(vector<Check>& checks) { 
    double totalCashed = 0;
    for (size_t i = 0; i < checks.size(); ++i) {
        if (checks[i].getStatus()) { 
            totalCashed += checks[i].getValue();
        }
    }
    return totalCashed;
}
double calculateTotalDepsited(vector<double> deposits) {
    double totalDeposited = 0;
    for (size_t i = 0; i < deposits.size(); ++i) {
        totalDeposited += deposits[i];
    }
    return totalDeposited;
}
void displayChecks(vector<Check>& checks) {
    cout << "Cashed Checks:";
    for (size_t i = 0; i < checks.size(); ++i) {
        if (checks[i].getStatus()) { cout << '\n' << checks[i]; }
    }
    cout << "\nUncashed Checks:";
    for (size_t i = 0; i < checks.size(); ++i) {
       if (!checks[i].getStatus()) { cout << '\n' << checks[i]; }
    }
}
