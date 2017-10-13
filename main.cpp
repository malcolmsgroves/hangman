#include "main.h"

int main(int argc, char** argv) {
    play_hangman("5desk.txt");
}

void play_hangman(string filename) {
    vector<string> dict = read_file(filename);
    Hangman game(dict);
    int num_guesses = 0;
    int max_guesses = 8;
    
    cout << "Welcome to Hangman" << endl << endl;
    
    while(!game.get_win() && num_guesses < max_guesses) {
        
        cout << "Guess number " << to_string(num_guesses);
        cout << " of " << to_string(max_guesses) << endl;
        cout << "Enter a letter: ";
        char c;
        cin >> c;
        cout << endl;
        game.make_guess(c);
        cout << game.get_str() << endl;
        ++num_guesses;
    }
    
    if(game.get_win()) {
        cout << "Congratulations, you win" << endl;
    }
    else {
        cout << "You lose" << endl;
    }
}

vector<string> read_file(string dict_file_name) {
    
    vector<string> dict;
    
    ifstream dict_stream;
    
    dict_stream.open(dict_file_name.c_str(), ios::in);
    
    if(!dict_stream.good()) {
        cout << "Error: not able to open dict file" << endl;
    }
    
    string curr_word = "";
    char curr_char;
    
    while(dict_stream.peek() != EOF) {
        dict_stream.get(curr_char);
        
        // stop at newline or whitespace
        if(curr_char != '\n') {
            curr_word += curr_char;
        } else {
            // remove whitespace at end and add to dict
            dict.push_back(curr_word.substr(0, curr_word.length() - 1));
            curr_word = "";
        }
    }
    
    return dict;
}
