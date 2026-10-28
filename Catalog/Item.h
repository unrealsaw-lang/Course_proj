#pragma once
#include<ostream>
#include <string>
using namespace std;

class Item {
	int id;
	int pageCount;
	string title;
	string field;
	int year;

public:

	Item(const string& title, const string& field, int year);
	virtual ~Item() = default;

	int getId() const { return id; }
	int getPageCount() const { return pageCount; }
	int getYear() const { return year; }
	const string& getTitle() const { return title; }
	const string& getField() const { return field; }

	void setId(int newId) { id = newId; }
	void setPageCount(int newPageCount) { pageCount = newPageCount; }
	void setYear(int newYear) { year = newYear; }
	void setTitle(const string& newTitle) { title = newTitle; }
	void setField(const string& newField) { field = newField; }  

	virtual void print(ostream& os) const = 0;
	virtual int calculatePrice() const = 0;
};