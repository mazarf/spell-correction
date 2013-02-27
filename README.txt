Mazar Farran & Corbin Gomez
///////////////////////////

dict.h
------
-Declared constructor and destructor.

dict.cpp
--------
-Created functions store_words, store_phrases, store_sentences, as well as many helper functions
-store_words() reads the entire file and stores every single word in a dynamically allocatedarray of C++ strings. Punctuation is removed. Filters out duplicates using is_duplicate().
-resize() takes the current array size, doubles it, and creates a bigger array with the old data.  Initial size is 50 but could be easily changed. Also, the function is very general and could be applied to phrases and sentences as well.
-function is_duplicate() compares the current string to every previous one, it returns true if there's a match and false if it's unique.
-store_sentences() gets an unformatted string up to the first period from the text.  Then it modifies it to remove newlines and tabs. It then appends a period to the end.
-remove_char() is a helper function for store_sentences() that is used to remove the '\t's from each sentence.
-store_phrases parses every possible phrase (33,508!) of 2-5 words, and puts them in an array.  Naturally, this is the most resource intensive and complex function.
-alphabetize() takes a specified array of a specified size, and arranges its contents in alphabetical order. Note: VERY slow on phrases
-created compare() to be used with qsort(), which replaces alphabetize() since it's much faster

-now we need member functions that allow access to the dictionary contents.  should be trivial and we could work it out as needed.

element.h
---------
-declared 3 pure virtual functions: complete(), check(), show()

phrase.h
--------
-Declared constructor, destructor, and member functions complete(), check(), and show();

phrase.cpp
----------

sentence.h
----------
-Declared constructor, destructor, and member functions complete(), check(), and show();

sentence.cpp
------------

word.h
------
-Declared constructor, destructor, and member functions complete(), check(), and show();

word.cpp
--------
