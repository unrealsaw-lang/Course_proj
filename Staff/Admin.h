#pragma once
#include <vector>
#include "Person.h"
using namespace std;

class Order;

class Admin : public Person {
	vector<Order*> managedOrders;

public:
	Admin(const string& name, const string& firstName, const string& lastName, const string& email, const string& phone);
	~Admin() override = default;

	const vector<Order*>& getManagedOrders() const;
	int getManagedOrdersCount() const { return static_cast<int>(managedOrders.size()); }

	void print(ostream& os) const override;
};