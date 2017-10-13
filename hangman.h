#ifndef hangman_h
#define hangman_h


#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

const int MAX_WRONG = 8;
const int MIN_WORD_LENGTH = 5;
const int MAX_WORD_LENGTH = 12;
const string GAME_DIRECTORY = "saved-games/";

struct Game {
    int num_wrong;
    string guess;
    string answer;
};

class Hangman {
    
public:
    Hangman(vector<string> dict);
    Hangman(string filename);
    void play();
    bool get_win();
    string get_str();
    bool make_guess(char c);
    string get_answer();
    
private:
    bool win;
    string answer_word;
    string curr_word;
    vector<string> dictionary;
    int guess_count;
    
    void print_game();
    int num_wrong;
    Game unserialize(string filename);
    void serialize(string filename, Game game);
    vector<string> get_game();
    string choose_word();
};

#endif
