#pragma once
#include <string>
#include <ostream>
#include <memory>
using namespace std;

class AuthorizationInfo;

class Person {

	int id;

	string name;
	string firstName;
	string lastName;

	unique_ptr<AuthorizationInfo> authorization;

	string email;
	string phoneNumber;

public:

	Person(const string& n, const string& fName, const string& lName, const string& email, const string& phone);
	virtual ~Person();

	int getId() const { return id; }
	const string& getName() const { return name; }
	const string& getFirstName() const { return firstName; }
	const string& getLastName() const { return lastName; }
	const string& getEmail() const { return email; }
	const string& getPhoneNumber() const { return phoneNumber; }

	void setId(int newId) { id = newId; }
	void setName(const string& newName) { name = newName; }
	void setFirstName(const string& newFirstName) { firstName = newFirstName; }
	void setLastName(const string& newLastName) { lastName = newLastName; }
	void setEmail(const string& newEmail) { email = newEmail; }
	void setPhoneNumber(const string& newPhoneNumber) { phoneNumber = newPhoneNumber; }

	AuthorizationInfo* getAuth() const { return authorization.get();}
	void setAuth(const string& login, const string& password);

	bool signUp();
	bool logIn();
	void runAuthorizationLoop();

	virtual void print(ostream& os) const = 0;

};