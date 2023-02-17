// Encapsulation

#include <iostream>
using namespace std;

class Banking
{
private:
  int mCashPool;
  int mMyCash;

public:
  Banking()
  {
    mCashPool = 10000;
    mMyCash = 0;
    cout << "\nThe Bank has $" << mCashPool << " reserved.\n\n";
  }

  bool openMyAccount(int amount)
  {
    mCashPool += amount;
    mMyCash += amount;
    return true;
  }

  int getMyBalance()
  {
    return mMyCash;
  }

  bool withdrawMyCash(int amount)
  {
    if (mMyCash >= amount)
    {
      mCashPool -= amount;
      mMyCash -= amount;
      return true;
    }
    else
    {
      return false;
    }
  }

  bool depositMyCash(int amount)
  {
    mCashPool += amount;
    mMyCash += amount;
    return true;
  }
};

int main()
{
  int cash, transaction;
  Banking myAccount;

  cout << "\nTo open an account, please enter $10 or more:  ";
  cin >> cash;
  if (cash < 10)
  {
    cout << "\nSorry, you can't open an account with less than $10.  Please contact customer services for assistance.\n\n";
    return 0;
  }
  else
  {
    if (myAccount.openMyAccount(cash))
    {
      cout << "\nCongratulations! You've opened an account with $" << myAccount.getMyBalance() << ".";
    };
  }

  do
  {
    cout << "\n\nOther transactions:\n1. Deposit\n2. Withdraw\n3. Get balance\n4. Exit\n\nPlease enter your selection: 1, 2, 3 or 4 --> ";
    cin >> transaction;
    if (transaction == 1)
    {
      cout << "\nPlease enter cash to deposit: ";
      cin >> cash;
      if (myAccount.depositMyCash(cash))
      {
        cout << "\nYou've successfully deposited $" << cash << " in your account.";
        cout << "\nAvailable balance: $" << myAccount.getMyBalance();
      };
    }
    else if (transaction == 2)
    {
      cout << "\nPlease enter cash to withdraw: ";
      cin >> cash;
      if (myAccount.withdrawMyCash(cash))
      {
        cout << "\nDon't forget to pick up your cash!";
        cout << "\nAvailable balance: " << myAccount.getMyBalance();
      }
      else
      {
        cout << "Sorry, you don't have enough cash! You've $ " << myAccount.getMyBalance() << " availabe balance.\n ";
      };
    }
    else if (transaction == 3)
    {
      cout << "\nAvailable Balance: $" << myAccount.getMyBalance();
    }
    else
    {
      cout << "\nThank you for banking with us. Have a great day!\n";
    }
  } while (transaction >= 1 && transaction <= 3);

  return 0;
}