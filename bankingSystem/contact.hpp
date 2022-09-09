//
//  contact.hpp
//  bankingSystemWithClasses
//
//  Created by Mason Schenk on 5/20/22.
//

#ifndef contact_hpp
#define contact_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

class Contact{
private:
    string street_address;
    string city;
    string state;
    string zipcode;
    string phone_number;
    
public:
    Contact();
    Contact(string street_add, string city, string state, string zipcode, string phone_num);
    ~Contact();
    void contact_info();
    ostream& display_info(ostream &out) const;
};

#endif /* contact_hpp */
