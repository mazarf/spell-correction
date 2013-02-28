//Mazar Farran & Corbin Gomez
#ifndef WORD_H
#define WORD_H

#include <string>
#include "dict.h"
#include <cstdlib>
#include <cmath>
#include "element.h"

class Word : public Element
{
public:
	Word(string s);
	~Word();
	void complete(const Dict &d);
	void check(const Dict &d);
	void show() const;
	int completion_hammer(string w);
	int correction_hammer(string w);
	bool has_same_start(string s1, string s2);
private:
	string input;
	string completions[10];
	int para_completions[10];
	string corrections[10];
	int para_corrections[10];
};

#endif