/**
   A savings account earns interest on the minimum balance.
   minBalance = 100;
*/

#include <iostream>

using namespace std;

class SavingsAccount : public BankAccount
{
   private:
   double interestRate;
   double minBalance; 

   /**
      Constructs a savings account with a zero balance and 100 minBalance.
   */
   public:
   SavingsAccount();
   SavingsAccount(int accNum, float thebalance, float theRate);
   /**
      Sets the interest rate for this account.
      @param rate the monthly interest rate in percent
   */
   void setInterestRate(double rate);
   void withdraw(double amount);
   void monthEnd();
   
   double getInterestRate();
   
};