#pragma once
#include <vector>
#include "Item.h"
using namespace std;

class Author;

class Article : public Item {
	vector<Author*> authors;
	vector<string> keywords;
	int volumes;

public:

	Article(const string& title, const string& field, int year, int vols, Author* A);
	~Article() override = default;

	const vector<Author*>& getAuthors() const;
	const vector<string>& getKeywords() const;
	int getVolumes() const { return volumes; }

	void setVolumes(int newVolumes) { volumes = newVolumes; }

	void addAuthor(Author* newAuthor);
	void addKeyword(const string& newKeyword);

	void removeAuthor(Author* Author);
	void removeKeyword(const string& keyword);

	void print(ostream& os) const override;
};