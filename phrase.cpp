//Mazar Farran & Corbin Gomez
#include "phrase.h"
#include <iostream>

using namespace std;

Phrase::Phrase(string s)
{
	input = s;
	for(int i = 0; i < 10; i++)
  {
    corrections[i] = "";
    para_corrections[i] = 100;

    completions[i] = "";
    para_completions[i] = 100;
  }
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
		/*cout << "h_distance: " << h_distance << endl;
		cout << "d.get_phrase(i): " << d.get_phrase(i) << endl;*/

		if(h_distance == -1)
			continue;
		for(int j = 0; j < 10; j++)
		{
			if(h_distance > para_completions[j])
				continue;
			else
				if(h_distance < para_completions[j])
				{
					for(int k = 8; k >= j; k--)
					{
						para_completions[k+1] = para_completions[k];
						completions[k+1] = completions[k];
					}

					para_completions[j] = h_distance;
					completions[j] = d.get_phrase(i);
					break;
				}
				else
          			if(h_distance == para_completions[j])
          			{
            			if(d.get_phrase(i) < completions[j])
            			{
                 		  //makes space
				      		for(int k = 8; k >= j; k--)
				     		{
					      		para_completions[k+1] = para_completions[k];
					      		completions[k+1] = completions[k];
				      		}
				      		//puts new phrase and distance in space
				      		para_completions[j] = h_distance;
				      		completions[j] = d.get_phrase(i);

              				break;
           				}
            			else // doesn't come before, try next one
              				if(j < 9 && h_distance <= para_completions[j + 1])
                				continue;
              				else
                				break;
                	}
		}
	}
}//complete

void Phrase::check(const Dict &d)
{
	int h_distance = 0;
  //cout << input.length() << endl;
	for(int i = 0; i < d.get_phrase_count(); i++)
	{

		h_distance = this->correction_hammer(d.get_phrase(i));
    //if(h_distance <= 0) continue;

		for(int j = 0; j < 10; j++)
		{
      if(h_distance > para_corrections[j])
        continue;
      else
        if(h_distance < para_corrections[j])
        {
          		  //makes space
				  for(int k = 8; k >= j; k--)
				  {
					  para_corrections[k+1] = para_corrections[k];
					  corrections[k+1] = corrections[k];
				  }
				  //puts phrase and distance in new space
				  para_corrections[j] = h_distance;
				  corrections[j] = d.get_phrase(i);
          break;

        }
        else
          if(h_distance == para_corrections[j])
          {
            if(d.get_phrase(i) < corrections[j])
            {
                 	  //makes space
				      for(int k = 8; k >= j; k--)
				      {
					      para_corrections[k+1] = para_corrections[k];
					      corrections[k+1] = corrections[k];
				      }
				      //puts new phrase and distance in space
				      para_corrections[j] = h_distance;
				      corrections[j] = d.get_phrase(i);

              break;
            }
            else // doesn't come before, try next one
              if(j < 9 && h_distance <= para_corrections[j + 1])
                continue;
              else
                break;
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
		cout << completions[i] <<endl;
	}
	cout << endl;

	cout << "PHRASE correction for: " << input << endl;
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
    string temp_input = input;
/*    int amt_spaces_w = 0;
    int amt_spaces_input = 0;*/
		for(unsigned int i = 0; i < w.length() - input.length(); i++)
		{
			temp_input+= ' '; // needs to be temp!
		}

		for(unsigned int i = 0; i < temp_input.length(); i++)
		{
			if(temp_input[i] != w[i])
				difference++;
			if(i>=input.length())
				if(w[i] == ' ')
					difference++;
		}

		/*for(unsigned int i = 0; i < w.length(); i++)
		{
			if(w[i] == ' ')
				amt_spaces_w++;
			if(input[i] == ' ')
				amt_spaces_input++;

			difference += (abs(amt_spaces_w - amt_spaces_input));
		}*/
		return difference;
	}

	else if(input.length() > w.length())
	{
		string temp_w = w;
		/*int amt_spaces_w = 0;
    int amt_spaces_input = 0;*/
		for(unsigned int i = 0; i < input.length() - w.length(); i++)
		{
			temp_w+= ' ';
		}

		for(unsigned int i = 0; i < temp_w.length(); i++)
		{
			if(input[i] != temp_w[i])
				difference++;
			if(i>=w.length())
				if(input[i] == ' ')
					difference++;
		}

		/*for(unsigned int i = 0; i < input.length(); i++)
		{
			if(w[i] == ' ')
				amt_spaces_w++;
			if(input[i] == ' ')
				amt_spaces_input++;

			difference += (abs(amt_spaces_input - amt_spaces_w));
		}*/
		return difference;
	}

	else
		return -1;
}//correction_hammer

bool Phrase::has_same_start(string s1, string s2)
{
	/*if(s1.length() <= s2.length())
	{*/
		for(unsigned int i = 0; i < s1.length(); i++)
		{
			if(s1[i] != s2[i])
				return false;
		}

		return true;
	//}

	/*if(s2.length() < s1.length())
	{
		for(unsigned int i = 0; i < s2.length(); i++)
		{
			if(s1[i] != s2[i])
				return false;
		}

		return true;
	}*/
	cout<<"if it gets to here, ya done messed up";
	int poop;
	cin >> poop;
	return false;
}//