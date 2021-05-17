#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argument, char *args[]){
    bool optionc = false;
    bool optionl = false;
    bool optionw = false;

    int total_lines = 0;
    int total_words = 0;
    int total_chars = 0;

    bool found = false;
    int files = 0;

    for (int i = 1; i < argument; i++) {
        string s = args[i];
        if (s == "-l") {
            optionl = true;
        } else if (s == "-w") {
            optionw = true;
        } else if (s == "-c") {
            optionc = true;
        } else {
            if ( (optionl == false) && (optionw == false) && (optionc == false) ) {
                optionl = true;
                optionw = true;
                optionc = true;
            }
            int lines = 0;
            int words = 0;
            int chars = 0;
            found = true;
            ++files;
            ifstream in_file(s);
            if (in_file.fail()) {
                cerr << s << ": " << s << ": open: No such file or directory" << endl;
            } else {
                string line;
                string line2;
                while (getline(in_file, line)) { //z=line, t=line2
                    line2 += " ";
                    line2 += line;
                    ++lines;
                }
                in_file.close();
                istringstream iss(line2);
                string word;
                while (iss>>word) {
                    words++;
                }
                int i = 0;
                while (line2[i] != 0) {
                    chars++;
                    i++;
                }
                cout << " ";
                if (optionl == true) {
                    cout << lines;
                    cout << " ";
                }
                if (optionw == true) {
                    cout << words;
                    cout << " ";
                }
                if (optionc == true) {
                    cout << chars;
                }
                cout << " " << s << endl;
                total_lines += lines;
                total_words += words;
                total_chars += chars;
            }
        }
    }

    if (files > 1) {
        cout << " ";
        if (optionl == true) {
            cout << total_lines;
            cout << " ";
        }
        if (optionw == true) {
            cout << total_words;
            cout << " ";
        }
        if (optionc == true) {
            cout << total_chars;
        }
        cout << " total" << endl;
    }

    if (found == false) {
        int lines = 0;
        int words = 0;
        int chars = 0;
        if ( (optionl == false) && (optionw == false) && (optionc == false) ) {
            optionl = true;
            optionw = true;
            optionc = true;
        }
        string in_s;
        string t;
        while (getline(cin, in_s)) {
            t += " ";
            t += in_s;
            ++lines;
        }
        istringstream iss(t);
        string word;
        while (iss>>word) {
            words++;
        }
        int i = 0;
        while (t[i] != 0) {
            chars++;
            i++;
        }
        cout << " ";
        if (optionl == true) {
            cout << lines;
            cout << " ";
        }
        if (optionw == true) {
            cout << words;
            cout << " ";
        }
        if (optionc == true) {
            cout << chars;
        }
        cout << endl;
    }
}
