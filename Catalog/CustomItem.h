#pragma once
#include "Item.h"
using namespace std;

enum class PaperFormat {A5, A4, A3, A2, A1};

class CustomItem : public Item {
	PaperFormat format;

	bool doubleSided;
	bool colorPrint;

	string comment;

public:

	CustomItem(const string& title, int pages, PaperFormat fmt, bool dbl, bool color, const string& comment);
	~CustomItem() override = default;

	const PaperFormat getFormat() const { return format; }
	const string& getComment() const { return comment; }

	void setFormat(PaperFormat newFormat) { format = newFormat; }
	void setComment(const string& newComment) { comment = newComment; }
	void setDoubleSided(bool newType) { doubleSided = newType; }
	void setColorPrint(bool newColor) { colorPrint = newColor; }

	bool isDoubleSided() const;
	bool isColorPrint() const;

	void print(ostream& os) const override;
};