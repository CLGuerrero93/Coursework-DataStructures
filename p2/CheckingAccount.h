/*
   A checking account has a limited number of free withdrawals.
      const int FREE_WITHDRAWALS = 3; //number of free withdrawals. 
      const int WITHDRAWAL_FEE = 1; // transaction fee after 3 free withdrawals
   
*/

#include <iostream>

using namespace std;

class CheckingAccount : public BankAccount
{
   private:
	int withdrawals;

	
   /*
      Constructs a checking account with a zero balance.
   */
   public:
   CheckingAccount(); 
   CheckingAccount(int accNum, float thebalance);

   void withdraw(double amount);
   void monthEnd();
};
