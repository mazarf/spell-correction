//Mazar Farran & Corbin Gomez
#include "dict.h"

Dict::Dict(string f)
{

  ifstream reference; // create if stream object
  reference.open(&f[0]); // makes it point to the file

  cout << "Dict object successfully instantiated" << endl;

  // scan for and store all unique words


}//constructor

Dict::~Dict()
{

}//destructor
