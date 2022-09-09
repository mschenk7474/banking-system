//
//  bankAccount.hpp
//  bankingSystemWithClasses
//
//  Created by Mason Schenk on 4/27/22.
//

#ifndef bankAccount_hpp
#define bankAccount_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include "contact.hpp"
using namespace std;

//WITH HPP FILE, ONLY CALLS TO METHODS AND VARIABLES.
class Account{
private:
    int accountID;
    static int next_id;
    std::string accountName;
    float accountBalance;
    shared_ptr<Contact> accountContactInfo;
    
public:
    Account();
    Account(int actId, string actName, float actBalance, shared_ptr<Contact> accountContactInfo);
    ~Account();
    void opening_setup();
    ostream& account_info(ostream &out) const;
    Account& operator+=(float value);
    Account& operator-=(float value);
    friend ostream &operator<< (ostream &out, const Account& act);
    int get_id() const;
    float get_bal() const;
    shared_ptr<Contact> get_contact_info() const;
    void add_contact();
    void display_contact();
};

//Since this is finding the account from the list, it doesn't need to be apart of the class
list<Account>::iterator  findAccount(const int id, list<Account> &accounts);
#endif /* bankAccount_hpp */
