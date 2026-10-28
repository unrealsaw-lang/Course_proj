#pragma once
#include <string>
using namespace std;

class Person;

class AuthorizationInfo {
	Person* person;
	string login;
	string password;
public:
	AuthorizationInfo(Person* P, const string& log, const string& pass);
	~AuthorizationInfo() = default;

	const string& getLogin() const { return login; }
	const string& getPassword() const { return password; }
	Person* getPerson() const { return person; }

	void setLogin(const string& newLogin) { login = newLogin; }
	void setPassword(const string& newPassword) { password = newPassword; }

};