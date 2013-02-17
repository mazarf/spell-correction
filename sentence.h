//Mazar Farran & Corbin Gomez
#ifndef SENTENCE_H
#define SENTENCE_H

class Sentence : public Element
{
public:
	Sentence();
	~Sentence();
	void complete(const Dict &d);
	void check(const Dict &d);
	void show() const = 0;
private:
	//???
};

#endif