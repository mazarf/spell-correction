Mazar Farran & Corbin Gomez
///////////////////////////

dict.h
------
-Declared constructor and destructor.

dict.cpp
--------
-Created functions store_words, store_phrases, store_sentences, and resize
-store_words() reads the entire file and stores every single word in a dynamically allocatedarray of C++ strings. Punctuation is removed. Filters out duplicates using is_duplicate().
-resize() takes the current array size, doubles it, and creates a bigger array with the old data.  Initial size is 50 but could be easily changed. Also, the function is very general and could be applied to phrases and sentences as well.
-function is_duplicate() compares the current string to every previous one, it returns true if there's a match and false if it's unique.
-store_sentences() gets an unformatted string up to the first period from the text.  Then it modifies it to remove newlines and tabs. Currently does not include periods, but could easily do so.
-other functions not defined yet

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
