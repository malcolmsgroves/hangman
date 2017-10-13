#include "hangman.h"

// constructor method for new game
Hangman::Hangman(vector<string> dict) {
    
    this->dictionary = dict;
    this->num_wrong = 0;
    this->answer_word = choose_word();
    this->win = false;
    for(int i = 0; i < answer_word.length(); ++i) {
        this->curr_word += '_';
    }
}

// alternative constructor to resurrect old game
Hangman::Hangman(string filename) {
    Game old_game = unserialize(filename);
    this->num_wrong = old_game.num_wrong;
    this->answer_word = old_game.answer;
    this->curr_word = old_game.guess;
    this->win = false;
}


/*
 Purpose:   Play a game of hangman in terminal using the
 Hangman class and associated methods.
*/
void Hangman::play() {
    
    cout << "Welcome to Hangman" << endl << endl;
    print_str();
    
    while(!get_win() && num_wrong < MAX_WRONG) {
        
        cout << to_string(num_wrong) << " of ";
        cout << to_string(MAX_WRONG) << " wrong letters" << endl;
        cout << "Enter a letter or enter ! to save game and exit: ";
        char c;
        cin >> c;
        if(c == '!') {
            Game to_save;
            to_save.num_wrong = num_wrong;
            to_save.answer = answer_word;
            to_save.guess = curr_word;
            cout << "Enter filename with .txt extension: ";
            string filename;
            cin >> filename;
            serialize(filename, to_save);
            return;
        }
        cout << endl;
        if(!make_guess(c)) {
            ++num_wrong;
        }
        
        print_str();
    }
    
    if(get_win()) {
        cout << "Congratulations, you win" << endl;
    }
    else {
        cout << "You lose" << endl;
        cout << "Answer was " << get_answer() << endl;
    }
}



/*
 Purpose: Pick a random word from the dictionary vector
 */
string Hangman::choose_word() {
    srand(time(NULL));
    string rand_str = "a";
    
    while(rand_str.length() < MIN_WORD_LENGTH || rand_str.length() > MAX_WORD_LENGTH) {
        rand_str = dictionary[rand() % dictionary.size()];
        cout << rand_str << endl;
    }
    
    return rand_str;
}


Game Hangman::unserialize(string filename) {
    Game old_game;
    ifstream gamefile;
    gamefile.open(GAME_DIRECTORY + filename, ios::in);
    if(!gamefile.good()) {
        cout << "Error: not able to open file" << endl;
        exit(1);
    }
    gamefile >> old_game.guess >> old_game.answer >> old_game.num_wrong;
    
    gamefile.close();
    return old_game;
}

void Hangman::serialize(string filename, Game save_game) {
    ofstream gamefile(GAME_DIRECTORY + filename);
    if(!gamefile.good()) {
        cout << "Error: not able to open file" << endl;
    }
    gamefile << save_game.guess << endl;
    gamefile << save_game.answer << endl;
    gamefile << to_string(save_game.num_wrong);
    gamefile.close();
}



/*
 Purpose:   Take a char c and fill in all indices of
            curr_word that are equal to c in the answer_word
 Parameters: The char c to check in the answer_word
 Return:    True if char c is found in the answer_word, false
            otherwise.
 */
bool Hangman::make_guess(char c) {
    c = tolower(c);
    bool is_char = false;
    
    for(int i = 0; i < answer_word.length(); ++i) {
        if(c == answer_word[i] || toupper(c) == answer_word[i]) {
            is_char = true;
            curr_word[i] = answer_word[i];
        }
    }
    return is_char;
}


// get method for the current word
void Hangman::print_str() {
    for(int i = 0; i < curr_word.length(); ++i) {
        cout << curr_word[i] << " ";
    }
    cout << endl;
}

// get method for win status
bool Hangman::get_win() {
    bool win_check = true;
    for(int i = 0; i < curr_word.length(); ++i) {
        if(curr_word[i] == '_') {
            win_check = false;
        }
    }
    return win_check;
}

// get method for answer string
string Hangman::get_answer() {
    return answer_word;
}

