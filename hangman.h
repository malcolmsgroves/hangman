#ifndef hangman_h
#define hangman_h


#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <random>

using namespace std;

class Hangman {
    
public:
    Hangman(vector<string> dict);
    void play();
    bool binary_search(string word);
    bool get_win();
    string get_str();
    bool make_guess(char c);
    string get_answer();
    
private:
    bool win;
    string random_word;
    string curr_word;
    vector<string> dictionary;
    int guess_count;
    
    
    void choose_word();
    void print_game();
    
};

#endif
