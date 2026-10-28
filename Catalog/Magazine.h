#pragma once
#include <vector>
#include "Item.h"
using namespace std;

class Publisher;
class Article;

class Magazine : public Item {
	vector<Article*> articles;
	int magazineNumber;
	Publisher* publisher;

public:

	Magazine(const string& title, const string& field, int pages, int year, int num, Publisher* pub);
	~Magazine() override = default;

	const vector<Article*>& getArticles() const { return articles; }
	int getMagazineNumber() const { return magazineNumber; }
	Publisher* getPublisher() const { return publisher; }

	void setMagazineNumber(int newMagazineNumber) { magazineNumber = newMagazineNumber; }
	void setPublisher(Publisher* newPublisher){ publisher = newPublisher; }

	void addArticle(Article* newArticle);
	void removeArticle(Article* Article);

	void print(ostream& os) const override;
};