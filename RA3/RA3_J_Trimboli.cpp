#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>

using namespace std;

int main(){
    fstream inputFile;
    string filename;
    string currentWord="";
    string currentInteger="";
    char currentChar;
    int lines = 1;
    int chars = 0;
    int digits = 0;
    int letters = 0;
    int punct = 0;
    int words = 0;
    int integers = 0;

    cin >> filename;
    inputFile.open(filename.c_str());

    //if no file is entered
    if(filename == ""){ 
        cout << "No file is found" << endl;
        return 0;
    }
    //if file is not open
    if(!inputFile.is_open()){
        cout << "File cannot be opened: " << filename << endl;
        return 0;
    }
    //Parse inputfile char by char
    while(inputFile){
        inputFile.get(currentChar);
        //once we have char, handle the data
        chars++;
        //in this if clause, we've reached the end of file and need to handle that.
        if(!inputFile){
            lines++;
            if(currentInteger != "")
                integers++;
            if(currentInteger != "")
                words++;
        }
        if(currentChar == '\n')
            lines++;

        if(isspace(currentChar) && currentWord != ""){
            words++;
            currentWord = "";
        }else{
            currentWord += currentChar;
        }

        if(isdigit(currentChar) && inputFile){
            digits++;
            currentInteger += currentChar;
        }else if(!isdigit(currentChar) && currentInteger != ""){
            integers++;
            currentInteger = "";
        }
        if (isalpha(currentChar))
            letters++;
        if(ispunct(currentChar))
            punct++;
    }

    cout << "LINES: " << lines << endl;
    cout << "CHARS: " << chars << endl;
    cout << "DIGITS: " << digits << endl;
    cout << "LETTERS: " << letters << endl;
    cout << "PUNCTUATIONS: " << punct << endl;
    cout << "WORDS: " << words << endl;
    cout << "INTEGERS: " << integers << endl;
    return 0;
}