Mazar Farran & Corbin Gomez
///////////////////////////

dict.h
------
-Declared constructor and destructor.

dict.cpp
--------
-Created functions store_words, store_phrases, store_sentences, and resize
-store_words() reads the entire file and stores every single word in a dynamically allocatedarray of C++ strings. Punctuation is removed. Doesn't filter out duplicates yet.
-resize() takes the current array size, doubles it, and creates a bigger array with the old data.  Initial size is 50 but could be easily changed. Also, the function is very general and could be applied to phrases and sentences as well.
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
