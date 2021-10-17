#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    ifstream infile;
    string currentLine;
    string currentWord;
    string filename;
    string maxWord = "";
    string maxLine = "";
    int totalLines = 0;
    int numNonCommented = 0;
    int numWords = 0;
    cout << "Enter the name of a file to read from: " << endl;
    cin >> filename;
    infile.open(filename.c_str());

    if(!infile.is_open()){
        cout << "File cannot be opened " << filename;
        return 0;
    }

    while(infile){
        if(infile.peek() == std::ifstream::traits_type::eof()){
            break;
        }
        getline(infile, currentLine);
        totalLines++;
        if(currentLine[0] == '#' ||currentLine.substr(0,2) == "//"){
            continue;
        }
        numNonCommented++;
        if(currentLine.length() > maxLine.length())
            maxLine = currentLine;
        for(int i = 0; i < currentLine.length(); i++){ //parse each line char by char
            if(currentLine[i] == ' '){ //if we reach a new word, set current word empty
                if(currentWord == "")
                    continue;
                if(currentWord.length() > maxWord.length())
                    maxWord = currentWord;
                numWords++;
                currentWord = "";
                continue;
            }
            currentWord += currentLine[i];
        }
        if(currentWord != ""){
            if(currentWord.length() > maxWord.length())
                maxWord = currentWord;
            numWords++;
        }
        currentWord = "";
    }
    infile.close();
    cout << "\nTotal Number of Lines: " << totalLines << endl;
    cout << "Number of non-commented lines: " << numNonCommented << endl;
    cout << "Line of Maximum Length: " << "\"" <<  maxLine << "\"" << endl;
    cout << "Number of Words: " << numWords << endl;
    cout << "Word of Maximum Length: " << "\"" <<  maxWord << "\"" << endl;
    return 0; 
}