#include "hangman.h"

Hangman::Hangman(vector<string> dict) {
    this->dictionary = dict;
    choose_word();
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
