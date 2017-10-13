#include "main.h"

int main(int argc, char** argv) {
    vector<string> dict = read_file("5desk.txt");
    Hangman hangman(dict);
    cout << hangman.binary_search(argv[1]) << endl;
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
