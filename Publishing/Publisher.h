#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Client.h"
#include "Author.h"
#include "Admin.h"
#include "Order.h"
using namespace std;

class Item;

class Publisher {
	int id;
	string name;
	string adress;
	string country;

	vector<Item*> catalog;
	vector<Client*> clients;
	vector<Author*> authors; 
	vector<Admin*> admins;
	vector<Order*> allOrders;

public:
	Publisher(const string& name, const string& adress, const string& country);
	~Publisher() = default;

	int getId() const { return id; }
	const string& getName() const { return name; }
	const string& getAdress() const { return adress; }
	const string& getCountry() const { return country; }
	const vector<Item*>& getWorks() const;
	int getCatalogSize() const { return static_cast<int>(catalog.size()); }
	vector<Person*> getPeople();
	vector<Item*> getItems();
	vector<Order*> getOrders();

	void setId(int newId) { id = newId; }
	void setName(const string& newName) { name = newName; }
	void setAdress(const string& newAdress) { adress = newAdress; }
	void setCountry(const string& newCountry) { country = newCountry; }
	
	Item* findItemById(int id);
	Person* findPersonById(int id);
	Order* findOrderById(int id);

	bool authenticate(const string& login, const string& pass);
	void removeItem(Item* Item);

	void registerClient(Client* C);
	void registerAuthor(Author* A);
	void registerAdmin(Admin* Admin);

	void publish(Item* I);

	void createOrder(Order* O);
};