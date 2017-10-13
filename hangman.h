#ifndef hangman_h
#define hangman_h


#include <string>
#include <time.h>
#include <vector>

using namespace std;

class Hangman {
    
public:
    Hangman();
    void play();
    
private:
    bool correct_guess;
    string curr_word;
    vector<string> dictionary;
    int guess_count;
    
    void make_guess(char c);
    void read_dict(string filename);
    void print_game();
};

#endif
