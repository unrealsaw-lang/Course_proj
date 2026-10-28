#pragma once
#include <vector>
#include "Item.h"
using namespace std;

class Author;
class Publisher;

class Book: public Item {
	vector<Author*> authors;
	Publisher* publisher;
	vector<string> chapters;
	int pageCount;

public:

	Book(const string& title, const string& field, int pages, int year, Publisher* pub, Author* A);
	~Book() override = default;

	int getPageCount() const { return pageCount; }
	Publisher* getPublisher() const { return publisher; }
	const vector<Author*>& getAuthors() const;
	const vector<string>& getChapters() const;

	void setPageCount(int newPageCount) { pageCount = newPageCount; }
	void setPublisher(Publisher* newPublisher) { publisher = newPublisher; }

	void addAuthor(Author* newAuthor);
	void addChapter(const string& newChapter);

	void removeAuthor(Author* Author);
	void removePublisher();
	void removeChapter(const string& chapter);

	void print(ostream& os) const override;
};