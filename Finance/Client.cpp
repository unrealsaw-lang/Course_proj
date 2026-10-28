#include <iostream>
#include "Person.h"
#include "Client.h"
#include "AuthorizationInfo.h"
using namespace std;

Client::Client(const string& n, const string& fName, const string& lName,const string& em, const string& ph, const string& adr, int b): Person(n, fName, lName, em, ph), 
adress(adr), balance(b) {};

void Client::print(ostream& os) const {
	os << "\nClient (id=" << getId() << ")"
		<< "\nFIO: " << getFirstName() << " " << getName() << " " << getLastName()
		<< "\nEmail: " << getEmail()
		<< "\nPhone: " << getPhoneNumber()
		<< "\naddress: " << adress 
		<< "\nbalance:" << balance << endl;
}