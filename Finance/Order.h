#pragma once
#include <string>
#include "Person.h"
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

enum class OrderStatus { Created, Paid, Done, Cancelled };
class Item;
class Order {
	int id;
	Date deadline;
	Item* item;
	OrderStatus status;

	Person* payer;
	Person* receiver;
	int payment; 
	Date orderDate;

public:

	Order(Date deadline, Item* item, Person* payer, Person* receiver, Date orderDate);

	int getId() const { return id; }
	Date getDeadline() const { return deadline; }
	Item* getItem() const { return item; }
	OrderStatus getStatus() const { return status; }
	Person* getPayer() const { return payer; }
	Person* getReceiver() const { return receiver; }
	int getPayment() const { return payment; }
	Date getOrderDate() const { return orderDate; }

	void setId(int newId) { id = newId; }
	void setDeadline(Date newDate) {
		orderDate.year = newDate.year;
		orderDate.month = newDate.month;
		orderDate.day = newDate.day;
	}
	void setDeadline(Date newDeadline) {
		deadline.year = newDeadline.year;
		deadline.month = newDeadline.month;
		deadline.day = newDeadline.day;
	}

	bool pay();
	bool complete(Item* I);
	bool cancel();
};