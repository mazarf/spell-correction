//Mazar Farran & Corbin Gomez
#ifndef DICT_H
#define DICT_H

#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

class Dict
{
public:
	Dict(string f);
	~Dict();

  void store_words();
  //void store_phrases();
  //void store_sentences();
          // ref to string ptr  // ref to int
  void resize(string *&old_array, int &current_size);
  bool is_duplicate(string *&array, int &current_index); // i have no idea why these
                                                        // need to be refs

private:
	/*
	char **words;
	char **phrases;		//Will these be necessary once we learn strings?
	char **sentences;
	*/

  ifstream reference; // file stream object that will point the text file

  string *words;
  string *phrases;
  string *sentences;

  const int INIT_SIZE;

};

#endif
