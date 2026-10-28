#pragma once
#include <vector>
#include "Person.h"
using namespace std;

class Item;
class Book;
class Article;

class Author : public Person {
	string biography;
	vector<Item*> works;

public:
	Author(const string& name, const string& firstName, const string& lastName, const string& email, const string& phone, const string& bio);
	~Author() override = default;

	const vector<Item*>& getWorks() const;
	int getWorksCount() const { return static_cast<int>(works.size()); }
	const string& getBiography() const { return biography; }

	void setBiography(const string& newBiography) { biography = newBiography; }

	void addWork(Item* Item);
	void removeWork(Item* Item);

	Book* writeBook(int id, const string& title, const string& field, int year, int pages);
	Article* writeArticle(int id, const string& title, const string& field, int year, int vols);

	void print(ostream& os) const override;
};