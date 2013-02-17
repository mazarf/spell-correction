//Mazar Farran & Corbin Gomez
#ifndef WORD_H
#define WORD_H

class Word : public Element
{
public:
	Word();
	~Word();
	void complete(const Dict &d);
	void check(const Dict &d);
	void show() const = 0;
private:
	//???
};

#endif