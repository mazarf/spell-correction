//Mazar Farran & Corbin Gomez
#include "dict.h"

Dict::Dict(string f) : INIT_SIZE(50)
{

  //ifstream reference; // create if stream object
  reference.open(&f[0]); // makes the file stream point to the file

  cout << "Dict object successfully instantiated" << endl;

  // scan for and store all unique words

  store_words();


}//constructor

void Dict::store_words()
{
  int current_size = INIT_SIZE;
  int current_count = 0;

  words = new string[current_size];

  for(int i = 0; i < current_size && !reference.eof(); i++)
  {

    reference >> words[i];
    if(reference.eof()) break;

    if(!isalpha(words[i][words[i].length() - 1]))
        words[i][words[i].length() - 1] = '\0'; // get rid of punctuation

    current_count++;

    cout << i << ": " << words[i] << endl;
    
    if(current_count == current_size)
      resize(words, current_size);

  } // for i

  cout << "Current count: " << current_count << endl;
  cout << "done" << endl;

} // store_words()

void Dict::resize(string *&old_array, int &current_size)
{

  current_size *= 2; // double the size

  string *new_array = new string[current_size];

  for(int i = 0; i < current_size / 2; i++)
  {

    new_array[i] = old_array[i];

  } // for i; copies string pointers to new array

  delete[] old_array;

  old_array = new_array;

  cout << "Resize instantiated successfully" << endl;

} // resize()

Dict::~Dict()
{

}//destructor
