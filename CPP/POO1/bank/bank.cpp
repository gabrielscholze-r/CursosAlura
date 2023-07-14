#include <iostream>
#include <string>
#include "account.hpp"
#include "holder.hpp"
using namespace std;

int main()
{
    cout<< Account::getAccountCount() << endl;
    Account a("1234", Holder("Gabriel", "1234"));
    cout << Account::getAccountCount() << endl;
    Account b("1234", Holder("Gabriel2", "1234"));
    cout << Account::getAccountCount() << endl;
    return 0;
}