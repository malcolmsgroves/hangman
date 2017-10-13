#include "main.h"

int main(int argc, char** argv) {
    vector<string> dict = read_file("5desk.txt");
    for(int i = 0; i < 10; ++i) {
        cout << dict[i] << endl;
    }
}

vector<string> read_file(string dict_file_name) {
    
    vector<string> dict;
    
    ifstream dict_stream;
    
    // should include .c_str()
    dict_stream.open(dict_file_name.c_str(), ios::in);
    
    if(!dict_stream.good()) {
        cout << "Error: not able to open dict file" << endl;
    }
    
    string curr_word = "";
    char curr_char;
    
    while(dict_stream.peek() != EOF) {
        dict_stream.get(curr_char);
        if(curr_char != '\n') {
            curr_word += curr_char;
        } else {
            dict.push_back(curr_word);
            curr_word = "";
        }
    }
    
    return dict;
}
