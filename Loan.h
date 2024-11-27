#include <iostream>
#include <list>
#include <string>
#include "DateTime.h"
#include "Repayment.h"
using namespace std;


struct User
{
    
    
};

class Loan
{
private:
    string loanID;
    string lender;
    string borrower;
    double amount;
    double interestRate;
    DateTime startDate;
    DateTime endDate;
    string status;
    bool isLoan;
    string note;
    User user;
    list<Repayment> repaymentHistory;
public:
    Loan()
    {
        loanID = "";
        lender = "";
        borrower = "";
        amount = 0;
        interestRate = 0;
        startDate.day = 0;
        startDate.month = 0;
        startDate.year = 0;
        endDate.day = 0;
        endDate.month = 0;
        endDate.year = 0;
        status = "";
        isLoan = false;
        note = "";
    }
    list<Repayment> getRepaymentSchedule()
    {
        list<Repayment> repaymentSchedule;
        int numRepayments;
        cout << "Enter number of repayments: ";
        cin >> numRepayments;
        for (int i = 0; i < numRepayments; i++)
        {
            Repayment repayment;
            repayment.getRepaymentDetails();
            repaymentSchedule.push_back(repayment);
        }
        return repaymentSchedule;
    }
    double caclculateInterest()
    {
        return amount * interestRate;
    }
    void addRepayment()
    {
        Repayment repayment;
        repayment.getRepaymentDetails();
        repaymentHistory.push_back(repayment);
       
    }
    void updateRepayment()
    {
        int repaymentID;
        cout << "Enter repayment ID: ";
        cin >> repaymentID;
        list<Repayment>::iterator it;
        for (it = repaymentHistory.begin(); it != repaymentHistory.end(); it++)
        {
            if (it->getRepaymentID() == repaymentID)
            {
                it->getRepaymentDetails();
                break;
            }
        }
        
    }
    void removeRepayment()
    {
        int repaymentID;
        cout << "Enter repayment ID: ";
        cin >> repaymentID;
        list<Repayment>::iterator it;
        for (it = repaymentHistory.begin(); it != repaymentHistory.end(); it++)
        {
            if (it->getRepaymentID() == repaymentID)
            {
                repaymentHistory.erase(it);
                break;
            }
        }
    }
    void sendReminder() {
    // Giả định bạn đã có hàm lấy ngày hiện tại trong DateTime
    DateTime currentDate = getCurrentDate();
    int daysOverdue = calculateDaysDifference(endDate, currentDate);

    if (daysOverdue > 15) {
        cout << "Loan ID: " << loanID << " is overdue by " << daysOverdue << " days!" << endl;
        cout << "Reminder sent to borrower: " << borrower << endl;
    } else {
        cout << "Loan ID: " << loanID << " is not overdue yet." << endl;
    }
    }

    void displayRepaymentHistory() const {
        for (const auto &repayment : repaymentHistory) {
            repayment.displayRepaymentDetails();
        }
    }

    ~Loan()
    {
        cout << "Loan object destroyed" << endl;
    }
    friend class Repayment;


};



