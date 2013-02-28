//Mazar Farran & Corbin Gomez
#include "phrase.h"
#include <iostream>

using namespace std;

Phrase::Phrase(string s)
{
	input = s;
}//constructor

Phrase::~Phrase()
{

}//destructor

void Phrase::complete(const Dict &d)
{
	int h_distance = 0;
	for(int i = 0; i < d.get_phrase_count(); i++)
	{
		h_distance = this->completion_hammer(d.get_phrase(i));

		for(int j = 0; j < 9; j++)
		{
			if(h_distance <= para_completions[j+1] && h_distance >= para_completions[j])
			{
				for(int k = j; k < 9; k++)
				{
					para_completions[k+1] = para_completions[k];
					completions[k+1] = completions[j];
				}

				para_completions[j] = h_distance;
				completions[j] = input;
			}
		}
	}

}//complete

void Phrase::check(const Dict &d)
{
	int h_distance = 0;
	for(int i = 0; i < d.get_phrase_count(); i++)
	{
		h_distance = this->correction_hammer(d.get_phrase(i));

		for(int j = 0; j < 9; j++)
		{
			if(h_distance <= para_corrections[j+1] && h_distance >= para_corrections[j])
			{
				for(int k = j; k < 9; k++)
				{
					para_corrections[k+1] = para_corrections[k];
					corrections[k+1] = corrections[j];
				}

				para_corrections[j] = h_distance;
				corrections[j] = input;
			}
		}
	}


}//check

void Phrase::show() const
{
	cout << "PHRASE completion for: " << input << endl;
	cout << "------------------------------\n";

	for(int i = 0; i < 10; i++)
	{
		if(completions[i] == "")
			break;
		cout << completions[i] << endl;
	}
	cout << endl;

	cout << "PHRASE correction for : " << input << endl;
	cout << "------------------------------\n";

	for(int i = 0; i < 10; i++)
	{
		if(corrections[i] == "")
			break;
		cout << corrections[i] << endl;
	}
	cout << endl;

}//show

int Phrase::completion_hammer(string w)
{
	if(has_same_start(input,w))
	{
		return (abs(w.length() - input.length()));
	}

	else
		return -1;
}//completion hammer

int Phrase::correction_hammer(string w)
{
	int difference = 0;
	if(input.length() == w.length())
	{
		for(unsigned int i = 0; i < input.length(); i++)
		{
			if(input[i] != w[i])
				difference++;
		}
		return difference;
	}

	else if(input.length() < w.length())
	{
		for(unsigned int i = 0; i < w.length() - input.length(); i++)
		{
			input+= ' ';
		}

		for(unsigned int i = 0; i < input.length(); i++)
		{
			if(input[i] != w[i])
				difference++;
		}
		return difference;
	}

	else if(input.length() > w.length())
	{
		for(unsigned int i = 0; i < input.length() - w.length(); i++)
		{
			w+= ' ';
		}

		for(unsigned int i = 0; i < input.length(); i++)
		{
			if(input[i] != w[i])
				difference++;
		}
		return difference;
	}

	else
		return -1;
}//correction_hammer

bool Phrase::has_same_start(string s1, string s2)
{
	if(s1.length() <= s2.length())
	{
		for(unsigned int i = 0; i < s1.length(); i++)
		{
			if(s1[i] != s2[i])
				return false;
		}

		return true;
	}

	if(s2.length() < s1.length())
	{
		for(unsigned int i = 0; i < s2.length(); i++)
		{
			if(s1[i] != s2[i])
				return false;
		}

		return true;
	}
	cout<<"if it gets to here, ya done messed up";
	int poop;
	cin >> poop;
	return false;
}//