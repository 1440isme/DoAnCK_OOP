#include <iostream>
#include "DateTime.h"
using namespace std;
class Repayment
{
private:
    int repaymentID;
    int loanID;
    double amount;
    DateTime date;
    
public:
    
    Repayment()
    {
        loanID = 0;
        amount = 0;
        date.day = 0;
        date.month = 0;
        date.year = 0;
        date.hour = 0;
        date.minute = 0;

    }
    ;
    void getRepaymentDetails()
    {
        cout << "Enter repayment ID: ";
        cin >> repaymentID;
        cout << "Enter loan ID: ";
        cin >> loanID;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter date: ";
        cin >> date.day >> date.month >> date.year >> date.hour >> date.minute;
    }
    void setRepaymentID(int id) { repaymentID = id; }
    int getRepaymentID() const { return repaymentID; }
    void setLoanID(int id) { loanID = id; }
    int getLoanID() const { return loanID; }
    void setAmount(double amt) { amount = amt; }
    double getAmount() const { return amount; }
    void setDate(const DateTime& dt) { date = dt; }
    DateTime getDate() const { return date; }

    void displayRepaymentDetails() const {
    cout << "Repayment ID: " << repaymentID << endl;
    cout << "Loan ID: " << loanID << endl;
    cout << "Amount: " << amount << endl;
    cout << "Date: " << date.toString() << endl;
    }

    ~Repayment()
    {
        cout << "Repayment object destroyed" << endl;
    }
    
};