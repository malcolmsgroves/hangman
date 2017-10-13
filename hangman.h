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
    
private:
    bool correct_guess;
    string random_word;
    string curr_word;
    vector<string> dictionary;
    int guess_count;
    
    void make_guess(char c);
    void choose_word();
    void print_game();
};

#endif
