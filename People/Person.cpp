#include <iostream>
#include "Person.h"
#include "AuthorizationInfo.h"
using namespace std;

Person::Person(const string& n, const string& fName, const string& lName,
	const string& email, const string& phone) : name(n), firstName(fName), lastName(lName), email(email), phoneNumber(phone) {
}
Person::~Person() = default;

void Person::setAuth(const string& login, const string& password) { authorization = make_unique<AuthorizationInfo>(this, login, password); }

bool Person::signUp() {
	cout << "Sign up:" << endl;
	if (this->getAuth() != nullptr) {
		cout << "\nYou already have an authorization";
		return false;
	}

	string newLog, newPass;
	cout << "Enter new login: "; cin >> newLog;
	cout << "Enter new password: "; cin >> newPass;
	
	this->authorization = make_unique<AuthorizationInfo>(this, newLog, newPass);
	cout << "\nSuccess!" << endl;
	return true;
}
bool Person::logIn() {
	cout << "Log in:" << endl;
	if (authorization == nullptr) {
		cout << "\nSign up first!\n";
		return false;
	}

	if (cin.peek() == '\n') cin.ignore();

	string log, pass;
	cout << "Input login: "; getline(cin, log);
	cout << "Input password: "; getline(cin, pass);

	if (this->getAuth()->getLogin() != log) {
		cout << "Invalid login. Try again\n";
		return false;
	}
	if (this->getAuth()->getPassword() != pass) {
		cout << "Invalid password. Try again\n";
		return false;
	}
	cout << "\nSuccess!" << endl;
	return true;
}

void Person::runAuthorizationLoop() {
	while (true) {
		if (this->logIn()) {
			break;
		}
		cout << "\nTry again?   1 - Yes\nChoice: "; 

		string choice;
		getline(cin, choice);
		if (choice != "1") break;
	}	
}
