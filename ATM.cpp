
  /*ATM Machine */
#include<iostream>
using namespace std;

class ATM{
private:
    int balance = 10000;
    int withdraw;
    int depositAmount;

public:
    void deposit(){
        cout << "Enter deposit amount: ";
        cin >> depositAmount;

        if (depositAmount <= 0)
        {
            cout << "Invalid Amount" << endl;
        }
        else
        {
            balance += depositAmount;
        }
    }

    void input(){
        cout << "Enter withdraw amount: ";
        cin >> withdraw;
    }

    void process(){
        if (withdraw <= 0)
        {
            cout << "Invalid amount entered" << endl;
        }
        else if (balance >= withdraw)
        {
            balance -= withdraw;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void display(){
        cout << "--------Transaction Detail-----------" << endl;
        cout << "Available Balance: " << balance << endl;
    }
};

int main(){
    ATM a1;
    while (true)
    {
        int choice;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
       if (choice==1)
       {
        a1.deposit();
       }else if (choice==2)
       {
        a1.input();
        a1.process();
       }else if (choice==3)
       {
        a1.display();
       }else if (choice==4)
       {
        exit(0);
        break;
       }
       
       
    }
    

    return 0;
}
