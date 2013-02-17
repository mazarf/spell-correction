//Mazar Farran & Corbin Gomez
#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
public:
	virtual void complete(const Dict &d) = 0;
	/*
		Computes the top 10 completions given the dicitonary d.
	*/
	virtual void check(const Dict &d) = 0;
	/*
		Computes the top 10 completions with possible corrections.
	*/
	virtual void show() const = 0;
	/*
		Displays the top 10 completions.
	*/
};

#endif