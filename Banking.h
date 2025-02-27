#pragma once
#ifndef BANKING_H
#define BANKING_H

//Class declaration
class Banking {
public:
	//Setters & getters (declarations)
	void setInitialInvestment(double initialInvestment);
	void setMonthlyDeposit(double monthlyDepositInput);
	void setInterestRate(double interestRateInput);
	void setNumberOfYears(int numberOfYearsInput);
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getInterestRate() const;
	int getNumberOfYears() const;
	//Balance calculations(declarations)
	double calcBalanceWithDeposits(double initialInvestment, double monthlyDepositInput, double interestRateInput, double numberOfYearsInput);
	double calcBalanceWithout(double initialInvestment, double interestRateInput, double numberOfYearsInput);

private:
	//Variable declarations
	double totalBalance;
	double monthlyDeposit;
	double interestAmount;
	double interestTotal;
	double numberOfYears;
};

#endif