#include "hangman.h"

Hangman::Hangman(vector<string> dict) {
    this->dictionary = dict;
    this->win = false;
    choose_word();
    for(int i = 0; i < random_word.length(); ++i) {
        this->curr_word += '_';
    }
    
}

bool Hangman::make_guess(char c) {
    c = tolower(c);
    bool is_char = false;
    bool win_check = true;
    for(int i = 0; i < random_word.length(); ++i) {
        if(curr_word[i] == '_') {
            win_check = false;
        }
        if(c == random_word[i] || toupper(c) == random_word[i]) {
            is_char = true;
            curr_word[i] = random_word[i];
        }
    }
    win = win_check;
    return is_char;
}

void Hangman::choose_word() {
    srand(time(NULL));
    string rand_str = "a";
    
    while(rand_str.length() < 5 || rand_str.length() > 12) {
        rand_str = dictionary[rand() % dictionary.size()];
        cout << rand_str << endl;
    }
    
    this->random_word = rand_str;
}

// get method for the current word
string Hangman::get_str() {
    return curr_word;
}

// get method for win status
bool Hangman::get_win() {
    return win;
}

// searches for word in dictionary using binary search
bool Hangman::binary_search(string word) {
    int min = 0;
    int max = dictionary.size() - 1;
    
    while(max >= min) {
        
        int middle = (max + min) / 2;
        
        string temp_dict = dictionary[middle];
        
        // make the dictionary word lowercase
        for(int i = 0; i < temp_dict.length(); ++i) {
            temp_dict[i] = tolower(temp_dict[i]);
        }
        
        int compare_str = word.compare(temp_dict);
        
        if(compare_str == 0) {
            return true;
        }
        if(compare_str < 0) {
            max = middle - 1;
        }
        else {
            min = middle + 1;
        }
    }
    
    
    // if while loop exited, return false
    return false;
    
}
