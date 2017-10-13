#include "main.h"


/*
    Main method for the hangman program
 */
int main(int argc, char** argv) {
    if(argc == 2) {
        if(argv[1][0] == '?') {
            cout << "-options-" << endl;
            cout << "To start new game, enter ./HM" << endl;
            cout << "To resume old game, enter ./HM <filename>.txt" << endl;
        }
        Hangman old_game(argv[1]);
        old_game.play();
    }
    else {
        
        Hangman new_game(read_file("5desk.txt"));
        
        new_game.play();
    }
}


/*
 Purpose:   Read each word of an alphabetized dictionary file into
            a vector of strings.
 Parameters: string filename for the dictionary
 Return: A vector<string> of the dictionary words
 */
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
        
        // stop at newline
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




/*
 Purpose:    Check if a word is contained in the dictionary
 vector using binary search.
 Parameters: The string word to search for in the dictionary.
 Return:     True if string is found, false otherwise.
 */
bool binary_search(vector<string> dictionary, string word) {
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
