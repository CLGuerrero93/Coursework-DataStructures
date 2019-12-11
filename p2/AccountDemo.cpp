//Author:          Cassandra Guerrero & Dr. Wang
//Creation Date:   18 September 2015
//Due Date:        20 September 2015
//Course:          CSC 402
//Professor Name:  Dr. Wang
//Assignment:      #2
//Filename:        AccountDemo.cpp
//Purpose:         Implementation and testing of BankAccount base class and
//		   CheckingAccount and SavingsAccount derived classes.

/*
   This program simulates a bank with checking and savings accounts.
*/

#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

const int FREE_WITHDRAWALS = 3;
const int WITHDRAWAL_FEE = 1;

BankAccount::BankAccount()
{
  accountNumber = 0;
  balance = 0.0;
}

BankAccount::BankAccount(int n, float b)
{
  accountNumber = n;
  balance = b;
}

void BankAccount::setAccountNumber(int n){accountNumber = n;}

int BankAccount::getAccountNumber(){return accountNumber;}

void BankAccount::deposit(double amount){balance += amount;}

void BankAccount::withdraw(double amount)
{
  if (balance >= amount)
    balance -= amount;
  else
  {
    cout<<"Amount exceeds balance.";
    if(balance >= WITHDRAWAL_FEE)
      balance -= WITHDRAWAL_FEE;
  }
}

//void BankAccount::monthEnd(){}

double BankAccount::getBalance(){return balance;}

void BankAccount::printAccount(ostream &out)
{
  cout<<"Balance of account "<<accountNumber
      <<" is "<<balance<<endl;
}

SavingsAccount::SavingsAccount():BankAccount(){minBalance = 100.0;}

SavingsAccount::SavingsAccount(int accNum, float thebalance, float theRate):BankAccount(accNum, thebalance)
{
  interestRate = theRate/100;
  minBalance = 100.0;
}

void SavingsAccount::setInterestRate(double rate){interestRate = rate;}

void SavingsAccount::withdraw(double amount)
{
  if (balance-amount >= minBalance)
    balance -= amount;
  else
  {
    cout<<"Amount exceeds minimum balance.";
    if(balance >= WITHDRAWAL_FEE)
      balance -= WITHDRAWAL_FEE;    
  }
}

void SavingsAccount::monthEnd()
{
  float interest = balance * interestRate;
  deposit(interest);
}

double SavingsAccount::getInterestRate(){return interestRate;}

CheckingAccount::CheckingAccount():BankAccount(){withdrawals = 0;}

CheckingAccount::CheckingAccount(int accNum, float thebalance):BankAccount(accNum, thebalance){withdrawals = 0;}

void CheckingAccount::withdraw(double amount)
{
  if (balance >= amount)
  {
    balance -= amount;
    if(withdrawals >= FREE_WITHDRAWALS)
      balance -= WITHDRAWAL_FEE;
    withdrawals++;
  }    

  else
  {
    cout<<"Amount exceeds balance.";
    if(balance >= WITHDRAWAL_FEE)
      balance -= WITHDRAWAL_FEE;    
  }
}

void CheckingAccount::monthEnd(){withdrawals = 0;}


int main()
{
	// Array of BankAccount pointer
	BankAccount* accountList[2];
	accountList[0] = new CheckingAccount(1,1000);
	accountList[0]->withdraw(100);
	accountList[0]->withdraw(100);
	accountList[0]->withdraw(100);
	accountList[0]->withdraw(100);	
	accountList[0]->monthEnd();
	accountList[0]->withdraw(100);	
	accountList[0]->deposit(1000);
	accountList[0]->printAccount(cout);

	accountList[1] = new SavingsAccount(2,1000, 5);
	accountList[1]->withdraw(100);
	accountList[1]->monthEnd();
	accountList[1]->withdraw(100);	
	accountList[1]->printAccount(cout);

	// test your program using the code below.
	// when you turn in your programming assignment, please comment the code below.
	// The grading program can not interact with your code, sorry:()
	
/*
      // Create accounts
	  SavingsAccount savings = SavingsAccount();
	  savings.setAccountNumber(1);
	  savings.setInterestRate(5);
	  
	  CheckingAccount checking = CheckingAccount();
	  checking.setAccountNumber(2);
	  
	  
      bool done = false;
      while (!done)
      {
		 int accountNumber;
		 cout << "Please enter your account number: " ;
		 cin >> accountNumber; 
			
         cout << "D)eposit  W)ithdraw  M)onth end  Q)uit: " << endl; 
         string input;
		 cin >> input;
		 
         if (accountNumber == 1 && (input=="D" || input=="W")) // Deposit or withdrawal
         {
            cout << "Enter amount: " ;
 			double amount;
			cin >> amount;

            if (input=="D") { savings.deposit(amount); }
            else { savings.withdraw(amount); }

            savings.printAccount(cout);
         }
         else if ( accountNumber == 1 && input=="M") // Month end processing
         {
               savings.monthEnd();
               savings.printAccount(cout);
         }
		 else if (accountNumber == 2 && (input=="D" || input=="W")) // Deposit or withdrawal
         {
            cout << "Enter amount: " ;
 			double amount;
			cin >> amount;

            if (input=="D") { checking.deposit(amount); }
            else { checking.withdraw(amount); }

            checking.printAccount(cout);
         }
         else if ( accountNumber == 2 && input=="M") // Month end processing
         {
               checking.monthEnd();
               checking.printAccount(cout);
         }
         else if (input == "Q")
         {
            //done = true;
	    return 0;
         }
   }
   */
   return 0;
}
