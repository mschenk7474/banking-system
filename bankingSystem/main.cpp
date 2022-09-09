//
//  main.cpp
//  bankingSystemWithClasses
//
//  Created by Mason Schenk on 4/27/22.
//

#include <iostream>
#include <iomanip>
#include <list>
#include <numeric>
#include "bankAccount.hpp"
#include "contact.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    //Object & List intialization
    typedef list<Account> Container;
    Container accounts;
    Account act;
    Account other_accounts;
    
    
    //Variable intialization
    int choice = 0;
    bool done = false;
    float deposit = 0;
    float withdraw = 0;
    int finder = 0;
    int remover = 0;
    float divi = 0;
    int actCFinder = 0;
    

    //Main Loop
    while (!done)
    {
        //Main menu
        cout<<"Account Menu:"<<endl;
        cout<<"0. Quit Program"<<endl;
        cout<<"1. Display Account Information"<<endl;
        cout<<"2. Add a deposit to an account"<<endl;
        cout<<"3. Withdraw from an account"<<endl;
        cout<<"4. Add new account"<<endl;
        cout<<"5. Find account by ID"<<endl;
        cout<<"6. Remove account"<<endl;
        cout<<"7. Show total balance for all accounts"<<endl;
        cout<<"8. Add a dividend to all accounts"<<endl;
        cout<<"9. Add contact information to an account"<<endl;
        cout<<"Your choice: ";
        cin>> choice;

        //Quits when the user wants to
        if (choice == 0){
            done = true;
        }
        
        //Shows the account information
        else if (choice == 1){
            for_each(accounts.begin(), accounts.end(), [](auto it){
                cout << it;
            });
            cout<< endl;
            
        }
        
        //Has you choose an account and then asks for a deposit and adds it to the balance of the certain account
        else if (choice == 2){
            cout << "Enter the ID of the account to find: ";
            cin >> finder;
            auto it = findAccount(finder, accounts);
            if(it != accounts.end()){
                cout<<"Amount to deposit: ";
                cin >> deposit;
                *it += deposit;
                cout<<endl;
            }
            
        }
        
        //Has you choose an account and then asks for a withdraw and subtracts it from the balance of the certain account
        else if (choice == 3){
            cout << "Enter the ID of the account to find: ";
            cin >> finder;
            auto it = findAccount(finder, accounts);
            if(it != accounts.end()){
                cout<<"Amount to withdraw: ";
                cin>>withdraw;
                *it -= withdraw;
                cout << endl;
            }
            
        }
        
        //Aquires the account information when asked to
        else if (choice == 4){
            other_accounts.opening_setup();
            accounts.push_back(other_accounts);
        }
        
        //Finds the account you want by the ID
        else if (choice == 5){
            cout << "Enter the ID of the account to find: ";
            cin >> finder;
            auto it = findAccount(finder, accounts);
            if (it != accounts.end()){
                *it;
                cout << endl;
            }
        }
        
        //Finds the account you want to remove and removes it
        else if (choice == 6){
            cout<< "Enter the account ID to remove: ";
            cin >> remover;
            
            auto remove = remove_if(accounts.begin(), accounts.end(), [remover](auto &account){
                return account.get_id() == remover;
            });
            
            accounts.erase(remove);
            cout << endl;
        }
        
        //Calculates the total of all the account's balances
        else if (choice == 7){
            float total = accumulate(accounts.begin(), accounts.end(), float(0), [](float acc, auto &account){
                return account.get_bal() + acc;
            });
            //float tot = float(total);
            cout << "Total in all accounts: $" << setprecision(2) << fixed << total << endl;
            cout << endl;
        }
        
        //Gets a dividend of the account and then adds on the dividend to the balance of the certain account
        else if (choice == 8){
            cout << "Enter the dividend as a percentage: ";
            cin >> divi;
            divi = divi * 0.01;
            
            auto begin = accounts.begin();
            transform(accounts.begin(), accounts.end(), begin, [divi](auto &account){
                float add = account.get_bal() * divi;
                account += add;
                return account;
            });
            cout << endl;
        }
        //Adds contact information to an account of the user's choosing
        else if (choice == 9){
            cout << "Enter the ID of the account to find: ";
            cin >> actCFinder;
            auto it = findAccount(actCFinder, accounts);
            if (it != accounts.end()){
                (*it).add_contact();
            }
            
        }
    }
    return 0;
    }

    
