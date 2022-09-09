//
//  bankAccount.cpp
//  bankingSystemWithClasses
//
//  Created by Mason Schenk on 4/27/22.
//

#include "bankAccount.hpp"
#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
using namespace std;

Contact con;

//Constructor
Account::Account(): accountID(), accountName(), accountBalance(){
    accountContactInfo = nullptr;
}

//Copy Constructor
Account::Account(int actID, string actName, float actBalance, shared_ptr<Contact> actConInfo): accountID(actID),accountName(actName), accountBalance(actBalance), accountContactInfo(actConInfo){}

//Destructor
Account::~Account(){
    cout << "In Account destructor (name is " << accountName<< ")" << endl;
}

//Has the opening setup for an account being made
void Account::opening_setup(){
    //Prompt for name
    cout << "Enter the name: ";
    cin >> accountName;
    
    //Prompt for Balance
    cout << "Enter the balance: ";
    cin >> accountBalance;
    
    cout << endl;
     
    //Gets the id for the next user
    accountID = next_id;
    next_id++;
}

//Intializes the static variable
int Account::next_id = 0;

//Displays the account information
ostream& Account::account_info(ostream &out) const{
    out << "Account ID: " << accountID << " Name: " << accountName << " Balance: $" <<fixed<<setprecision(2) << accountBalance << endl;
    return out;
}

//Ostreams all of the information
ostream& operator<< (ostream& out, const Account& act){
    act.account_info(out);
    //Checks to see if the contact pointer is null, if it isn't it displays the contact information
    if (act.accountContactInfo != nullptr){
        act.accountContactInfo->display_info(out);
    }
    return out;
}

//Adds all the deposit to the balance
Account& Account::operator+=(float value){
    accountBalance += value;
    return *this;
}

//Subtracts the withdraw from the balance
Account& Account::operator-=(float value){
    accountBalance -= value;
    return *this;
}

//Returns the account ID
int Account::get_id() const{
    return accountID;
}

//Returns the account balance
float Account::get_bal() const{
    return accountBalance;
}

//Adds the contact information to the pointer
void Account::add_contact(){
    accountContactInfo = shared_ptr<Contact>(new Contact);
    accountContactInfo->contact_info();
}

//Finds a specific account that the user wants by the account ID
list<Account>::iterator findAccount(const int id, list<Account> &accounts){
    //Tells where the iterator is supposed to begin
    list<Account>::iterator it = accounts.begin();
    
    //Iterates through the whole list
    for (it = accounts.begin(); it != accounts.end(); it++)
        
        //If the ID inputted matches the ID of the account, the account information is returned
        if(id == it->get_id()){
            cout << "Found Account: " << *it;
            return it;
            }
    
    //If the ID doesn't match, the message below is outputted
    cout << "Account not found." << endl;
    cout << endl;
    return accounts.end();
}
