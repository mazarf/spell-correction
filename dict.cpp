//Mazar Farran & Corbin Gomez
#include "dict.h"
#include <algorithm>

/* Goal: 
 * 1643 unique words (1643)
 * 766 unique sentences (766)
 * 33508 unique phrases (33515)
 */

Dict::Dict(string f) : INIT_SIZE(50)
{

  //ifstream reference; // decided to make this a member 
  reference.open(f.c_str()); // makes the file stream point to the file

  cout << "Dict object successfully instantiated" << endl;

  store_words(); // scan for and store all unique words

  store_phrases();

  store_sentences(); // same, but for sentences that end with a period


}//constructor



void Dict::store_words()
{
  cout << "Store words called successfully" << endl;

  int current_size = INIT_SIZE;
  int current_count = 0;

  words = new string[current_size];

  for(int i = 0; i < current_size && !reference.eof(); i++)
  {

    reference >> words[i];
    if(reference.eof()) break; // may need to move this further down

    if(!isalpha(words[i][words[i].length() - 1]))
        words[i].resize(words[i].length() - 1); // get rid of punctuation

    if(is_duplicate(words, i))
    {

      // pretend it never happened...

      i--;
      continue;

    } // if

    current_count++;

    //cout << i << ": " << words[i] << endl;
    
    if(current_count == current_size)
      resize(words, current_size);

  } // for i

  // clear ifstream object and set it back to the start
  
  reference.clear(); // reset eof value and stuff
  reference.seekg(0, std::ios::beg); // move back to start of file

  cout << "Current count (words): " << current_count << endl;
  cout << "done" << endl;

} // store_words()



void Dict::store_phrases()
{

  cout << "Store phrases called successfully" << endl;

  int current_size = INIT_SIZE;
  bool has_period = false;
  char temp[80];
  int current_count = 0;
  int combinations = 0; // used to determine how many shifts
                        // are needed to get every phrase combo

  phrases = new string[current_size];

  for(int i = 2; i <= 5; i++) // for every phrase length
  {

    combinations = 1;
    has_period = false;

    for(int j = current_count; j < current_size && !reference.eof(); j++)
    {

      has_period = false;

      int k;
      for(k = 1; k <= i; k++)
      {

        reference >> temp;
        if(reference.eof()) break; // done, break out of k loop

        if(temp[strlen(temp) - 1] == '.')
        {

          if(k < i) // period in the middle. not a phrase
            has_period = true;
          else
            temp[strlen(temp) - 1] = '\0';  // get rid of period

        } // if

        phrases[j] = phrases[j] + temp + ' ';

      } // for k

      
      // go through every possible combination of i words, or break
      
      if(reference.eof())
      {
        phrases[j].clear();

        if(combinations < i)
        {

          reference.clear(); // reset eof value and stuff
          reference.seekg(0, std::ios::beg); // move back to start of file

          for(int m = 0; m < combinations; m++)
            reference >> temp; // skip a word

          combinations++;
          if(current_count >= current_size)
            resize(phrases, current_size); // necessary because the
                                           // resize below will be skipped
          j--;
          continue; // restart the loop

        } // if
        else // did every possible combination, break out of j
          break;
      } // if

      if(has_period)
      {
        phrases[j].clear();
        j--;
        has_period = false;
        continue;
      } // if

      phrases[j].resize(phrases[j].length() - 1); // remove extra space

      if(is_duplicate(phrases, j))
      {
        phrases[j].clear(); // need to do this because i'm adding to the string
        j--;
        continue;
      } // if


      current_count++;

      if(current_count == current_size)
        resize(phrases, current_size);

      //cout << j << ": " << phrases[j] << endl;

    }

    // finished with i-word phrases
    
    reference.clear();
    reference.seekg(0, std::ios::beg);

  }

  cout << "Current count (phrases): " << current_count << endl;
  cout << "done" << endl;

} // store_phrases()



void Dict::store_sentences()
{

  cout << "Store sentences called successfully" << endl;

  int current_size = INIT_SIZE;
  int current_count = 0;
  char temp[9999]; // ifstreams can't take 'string' arguments for some reason

  sentences = new string[current_size];

  for(int i = 0; i < current_size && !reference.eof(); i++)
  {

    reference.getline(temp, 9999,'.');

    sentences[i] = temp;

    for(int j = 0; j < static_cast<int>(sentences[i].length()); j++) // replace all newlines
      if(sentences[i][j] == '\n')                                    // with spaces
        sentences[i][j] = ' ';

    // not too happy about this function which i got from
    // the internet. needs #include <algorithm>. it removes
    // all of the '\t's by shifting the array to cover them
    // every time it finds one

    sentences[i].erase(remove(sentences[i].begin(), sentences[i].end(), '\t'),
        sentences[i].end());
    
    //cout << i << ": " << sentences[i] << endl;

    if(is_duplicate(sentences, i))
    {

      i--;
      continue;

    } // if
    
    current_count++;

    if(current_count == current_size)
      resize(sentences, current_size);

  } // for i

  current_count--; // empty string at the end for some reason

  cout << "Current count (sentences): " << current_count << endl;
  cout << "done" << endl;

} // store_sentences()



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

  cout << "Resize called successfully" << endl;

} // resize()



bool Dict::is_duplicate(string *&array, int &current_index)
{

  for(int i = 0; i < current_index; i++)
  {

    if(array[current_index] == array[i])
      return true;

  } // for i

  // if we get to this point, the string is unique
  // NOTE: I noticed that some duplicate strings are getting in.
  //       They have a '^@' character in vi. I think it's because
  //       I didn't get rid of the periods correctly.
  // 2/20/13: Fixed it! Apparently C++ strings don't terminate with '\0'

  return false;

} // is_duplicate()



Dict::~Dict()
{

  delete[] words;
  delete[] phrases;
  delete[] sentences;

}//destructor
