#include "Banking.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Class defenitions for Banking

//Setters & getters(defenitions)
void Banking::setInitialInvestment(double initialInvestment) {
	totalBalance = initialInvestment;
}
void Banking::setMonthlyDeposit(double monthlyDepositInput) {
	monthlyDeposit = monthlyDepositInput;
}
void Banking::setInterestRate(double interestRateInput) {
	interestTotal = interestRateInput;
}
void Banking::setNumberOfYears(int numberOfYearsInput) {
	numberOfYears = numberOfYearsInput;
}
double Banking::getInitialInvestment() const {
	return totalBalance;
}
double Banking::getMonthlyDeposit() const {
	return monthlyDeposit;
}
double Banking::getInterestRate() const {
	return interestTotal;
}
int Banking::getNumberOfYears() const {
	return numberOfYears;
}

//Function to calculate balance with monthly deposits
double Banking::calcBalanceWithDeposits(double initialInvestment, double monthlyDepositInput, double interestRateInput, double numberOfYearsInput) {
	totalBalance = initialInvestment;

	//Display table header
	cout << endl;
	cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
	cout << std::string(60, '=') << endl;
	cout << "Year       Year End Balance         Year End Earned Interest" << endl;
	cout << std::string(60, '-') << endl;

	//Calculate and display table 
	for (int i = 0; i < numberOfYearsInput; ++i) {
		interestTotal = 0;
		for (int j = 0; j < 12; ++j) {
			interestAmount = (totalBalance + monthlyDepositInput) * ((interestRateInput / 100.00) / 12.00);
			interestTotal = interestTotal + interestAmount;
			totalBalance = totalBalance + monthlyDepositInput + interestAmount;
		}
		cout << left << setw(6) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalBalance << "\t\t\t\t$" << interestTotal << endl;
	}
	return totalBalance;
}

//Function to calculate balance without monthly deposits
double Banking::calcBalanceWithout(double initialInvestment, double interestRateInput, double numberOfYearsInput) {
	totalBalance = initialInvestment;

	//Display table header
	cout << endl;
	cout << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << std::string(60, '=') << endl;
	cout << "Year       Year End Balance         Year End Earned Interest" << endl;
	cout << std::string(60, '-') << endl;

	//Calculate and display table 
	for (int i = 0; i < numberOfYearsInput; ++i) {
		interestAmount = totalBalance * (interestRateInput / 100.00);
		totalBalance = totalBalance + interestAmount;
		cout << left << setw(6) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalBalance << "\t\t\t\t$" << interestAmount << endl;
	}
	return totalBalance;
}