#ifndef main_h
#define main_h

#include "hangman.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;






vector<string> read_file(string dict_file_name);
void play_hangman(string dict_file_name);
string choose_word(vector<string> dictionary);
bool binary_search(string word);


#endif
