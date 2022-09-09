//
//  contact.cpp
//  bankingSystemWithClasses
//
//  Created by Mason Schenk on 5/20/22.
//

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
using namespace std;

//Constructor
Contact::Contact(): street_address(), city(), state(), zipcode(), phone_number() {}

//Copy Constructor
Contact::Contact(string street_add, string city, string state, string zipcode, string phone_num): street_address(street_add), city(city), state(state), zipcode(zipcode),phone_number(phone_num){
    
}

//Destructor
Contact::~Contact(){
    cout << "In Account destructor (address is " << street_address << ")" << endl;
}

//Gets all the contact information
void Contact::contact_info(){
    //This makes it so address can actually input something
    cin.ignore(1000, '\n');
    
    //the getlines make sure that you can get the input despite the spaces
    cout << "Enter Address: ";
    getline(cin, street_address);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Enter State: ";
    getline(cin, state);

    cout << "Enter Zip Code: ";
    getline(cin, zipcode);

    cout << "Enter Phone Number: ";
    getline(cin, phone_number);
    cout << endl;
}

//Displays the contact information when asked
ostream& Contact::display_info(ostream &out) const{
    out << "+ Contact Information: " << "Address: " << street_address << " City: " << city << " State: " << state << " Zip: " << zipcode << " Phone: " << phone_number << endl;
    return out;
}
