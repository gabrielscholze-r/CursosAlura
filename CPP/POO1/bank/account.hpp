#pragma once
#include <string>
#include "holder.hpp"
class Account
{

    std::string number;
    Holder holder;

    float balance=0;

public:
    static int accountCount;
    static int getAccountCount();
    Account(std::string number, Holder h);
    ~Account();
    void withdraw(float value);
    void deposit(float value);
    float getBalance() const;
};