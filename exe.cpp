#include <iostream>
using namespace std;
class Bank {
private:
    int balance;   // hidden data

public:
    void setBalance(int b) {
        if (b >= 0)
            balance = b;
    }

    int getBalance() {
        return balance;
    }
};