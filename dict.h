//Mazar Farran & Corbin Gomez
#ifndef DICT_H
#define DICT_H

#include <string>
#include <iostream>
#include <fstream> // for the file input stream (reference)
#include <cctype>  // for isalpha()
#include <cstring> // for strlen()
#include <cstdlib> // for qsort

using namespace std;

class Dict
{

public:
	Dict(string f);
	~Dict();

  void store_words();
  void store_phrases();
  void store_sentences();
          // ref to string ptr  // ref to int
  void resize(string *&old_array, int &current_size);
  inline bool is_duplicate(string *&array, int &current_index); // idk why, but need to be
                                                                // refs
  inline void remove_char(string s, char c);
  //void alphabetize(string *array, int size); // obsolete with qsort
  static int compare(const void* a, const void* b); // compares two strings, necessary for qsort

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
  
  int word_count;
  int phrase_count;
  int sentence_count;

  const int INIT_SIZE;

};

#endif
