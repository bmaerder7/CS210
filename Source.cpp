//Brooks Maerder
//CS210 Project 2
//2-8-25

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Banking.h"

using namespace std;

//variable & function declarations
Banking myInvestment;
double initialInvestment;
double monthlyDeposit;
double interestRate;
double months;
int years;
char userIn = 'a';
int validInteger();
double validDouble();
void displayMenu();

//Validate integer input
int validInteger() {
	int x;

	while (true) {
		//make sure it is type int
		if (cin >> x) {
			// then make sure it is non-negative
			if (x >= 0) {
				//only break if the two statements above are met
				break;
			}
			else {
				cout << "Invalid input, please enter a non-negative number" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
		}
		else {
			cout << "Invalid input, please enter a number" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return x;
}

//Validate double input
double validDouble() {
	double x;

	while (true) {
		//make sure it is type double
		if (cin >> x) {
			//then make sure it is non-negative
			if (x >= 0) {
				//only break if the two statements above are met
				break;
			}
			else {
				cout << "Invalid input, please enter a non-negative number" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
		}
		else {
			cout << "Invalid input, please enter a non-negative number" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
	}
	return x;
}

//Displays menu and gathers input
void displayMenu() {
	while (userIn != 'q') {
		cout << std::string(40, '*') << endl;
		cout << std::string(14, '*') << " Data Input " << std::string(14, '*') << endl;
		cout << "Initial Investment Amount: $";
		initialInvestment = validDouble();
		myInvestment.setInitialInvestment(initialInvestment);
		cout << endl << "Monthly Deposit: $";
		monthlyDeposit = validDouble();
		myInvestment.setMonthlyDeposit(monthlyDeposit);
		cout << endl << "Annual Interest: %";
		interestRate = validDouble();
		myInvestment.setInterestRate(interestRate);
		cout << endl << "Number of Years: ";
		years = validInteger();
		myInvestment.setNumberOfYears(years);
		cout << "Calculating..." << endl;

		myInvestment.calcBalanceWithout(myInvestment.getInitialInvestment(), myInvestment.getInterestRate(), myInvestment.getNumberOfYears());
		myInvestment.calcBalanceWithDeposits(myInvestment.getInitialInvestment(), myInvestment.getMonthlyDeposit(), myInvestment.getInterestRate(), myInvestment.getNumberOfYears());

		cout << "Press 'q' to quit, or any other key to run a new investment report" << endl;
		cin >> userIn;
	}
}

int main() {
	displayMenu();
	return 0;
}