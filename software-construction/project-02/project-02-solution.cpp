// How to compile code: g++ filename
// How to run code: ./a.out

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Loan Amount: ";
	double loanAmount; //Amount of credit what we have to pay off
	while (!(cin >> loanAmount) || loanAmount <= 0) {
        cout << "Invalid loan amount. Please enter a positive number: ";
        cin.clear();             // reset the error state after "abc"
        cin.ignore(10000, '\n'); // throw away the bad input
	}

	cout << "Interest Rate (% per year): ";
	double interest_Year; //Rate which we have to pay extra to the loanAmount
	while (!(cin >> interest_Year) || interest_Year < 0) {
        cout << "Invalid interest rate. Please enter a non-negative number: ";
        cin.clear();             // reset the error state after "abc"
        cin.ignore(10000, '\n'); // throw away the bad input
	}


	cout << "Monthly Payments: ";
	double payment_Month; //fix value what we are paying back every month
	while (!(cin >> payment_Month) || payment_Month <= 0) {
        cout << "Invalid monthly payment. Please enter a positive number: ";
        cin.clear();             // reset the error state after "abc"
        cin.ignore(10000, '\n'); // throw away the bad input
	}


	double rate = interest_Year / 12.0; //rate per month

	if (payment_Month <= loanAmount * (rate / 100)) {
        cout << "Error: monthly payment is too small to cover the interest." << endl;
        return 1;
	}

	int month = 0; //Number of Months we have to pay our dept
	double balance = loanAmount; //remaining balance
	double interest_Month = 0;
	double principal = 0; //Tilgung, what you will pay back per month
	double totalInterest = 0;


//cout << loanAmount << interest_Year << payment_Month << endl;

	cout << "**********************************************************" << endl;
	cout << "\t Amortization Table" << endl;
	cout << "**************************************************************" << endl;
	cout << fixed << setprecision(2) << left;

	cout << setw(8) << "Month"
     << setw(13) << "Balance"
     << setw(11) << "Payment"
     << setw(8) << "Rate"
     << setw(11) << "Interest"
     << setw(11) << "Principal" << endl;

	cout << setw(8) << month
     << "$" << setw(12) << balance
     << setw(11) << "N/A"
     << setw(8) << "N/A"
     << setw(11) << "N/A"
     << setw(11) << "N/A" << endl;

	while (balance > 0){
		month++;
		interest_Month = balance * (rate / 100);

		if( balance + interest_Month <= payment_Month){
			payment_Month = balance + interest_Month;
			principal = balance;
			balance = 0;
		} else {
			principal = payment_Month - interest_Month;
			balance -= principal;
		}
		totalInterest += interest_Month;

		cout << fixed << setprecision(2) << left << setw(8) << month
     		<< "$" << setw(12) << balance
     		<< "$" << setw(10) << payment_Month
     		<< setw(8) << rate
     		<< "$" << setw(10) << interest_Month
     		<< "$" << setw(10) << principal << endl;
	}

	cout << "**********************************************************" << endl;
	cout << " " << endl;
	cout << "It takes " << month << " months to pay off the loan." << endl;
	cout << "Total interest paid is: $" << totalInterest << endl;

	return 0;
}
