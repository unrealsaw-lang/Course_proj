#pragma once
#include "Person.h"
#include <vector>
using namespace std;

class Order;
class Client : public Person {
	vector<Order*> orders; 
	int balance;
	string adress;

public:
	Client(const string& name, const string& firstName, const string& lastName, const string& email, const string& phone, const string& adress, int balance);
	~Client() override = default;

	const string& getAdress() const { return adress; }
	int getBalance() const { return balance; }
	const vector<Order*>& getOrders() const;
	void setAdress(const string& newAdress) { adress = newAdress; }
	
	void deposit(int amount);
	int withdraw(int amount);

	Order* placeOrder(int id, const string& title, const string& deadline, int budget);
	void cancelOrder(Order* O);

	void print(ostream& os) const override;
};