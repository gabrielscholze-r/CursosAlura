#include "account.hpp"
#include <iostream>

int Account::accountCount = 0;

Account::Account(std::string number, Holder h) : number(number),
                                                 holder(h),
                                                 balance(0)
{
    accountCount++;
}
Account::~Account()
{
    accountCount--;
}

int Account::getAccountCount()
{
    return accountCount;
}

void Account::withdraw(float value)
{
    if (balance >= value && value > 0)
    {

        balance -= value;
        std::cout << "Success!" << std::endl;
    }
    else
    {
        std::cout << "Value invalid or you don't have this amount of balance!" << std::endl;
    }
}

void Account::deposit(float value)
{
    if (value > 0)
    {
        balance += value;
        std::cout << "Success!" << std::endl;
    }
    else
    {
        std::cout << "Value of deposit invalid" << std::endl;
    }
}

float Account::getBalance() const
{
    return balance;
}