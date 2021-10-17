
#include <iostream>
#include <string>
#include "./lex.h"
#include <map>

using namespace std;

map<string, Token> dict = {
    { "PROGRAM", PROGRAM },
    { "WRITE", WRITE},
    { "INT", INT },
    { "END", END },
    { "IF", IF },
    { "FLOAT", FLOAT },
    { "STRING", STRING},
    { "REPEAT", REPEAT },
    { "BEGIN", BEGIN },
    { "IDENT", IDENT },
    { "ICONST", ICONST },
    { "RCONST", RCONST },
    { "SCONST", SCONST },
    { "PLUS", PLUS },
    { "MINUS", MINUS },
    { "MULT", MULT },
    { "DIV", DIV},
    { "REM", REM },
    { "ASSOP", ASSOP },
    { "LPAREN", LPAREN },
    { "RPAREN", RPAREN },
    { "COMMA", COMMA },
    { "EQUAL",  EQUAL},
    { "GTHAN", GTHAN },
    { "SEMICOL", SEMICOL },
    { "ERR", ERR },
    { "DONE", DONE },
};

map<int, string> keys = {
    
    {0, "PROGRAM"},
    {1, "WRITE"},
    {2, "INT"},
    {3, "END"},
    {4, "IF"},
    {5, "FLOAT"},
    {6, "STRING"},
    {7, "REPEAT"},
    {8, "BEGIN"},
    {9, "IDENT"},
    {10,"ICONST"},
    {11,"RCONST"},
    {12,"SCONST"},
    {13, "PLUS"},
    {14,"MINUS"},
    {15,"MULT"},
    {16,"DIV"},
    {17, "REM"},
    {18,"ASSOP"},
    {19,"LPAREN"},
    {20,"RPAREN"},
    {21, "COMMA"},
    {22,"EQUAL"},
    {23,"GTHAN"},
    {24,"SEMICOL"},
    {25, "ERR"},
    {26,"DONE"},
};
   
/*
Id_or_kw function accepts a reference to a string of a lexeme and a line number and returns a LexItem object. 
It searches for the lexeme in a directory that maps a string value of a keyword to its corresponding Token value, 
and it returns a LexItem object containing either the keyword Token if it is found, or the identifier token IDENT if not.
*/


//Accepts a ref to a string of a lexeme and a line num and returns lexitem obj
LexItem id_or_kw(const string& lexeme, int linenum){
    Token tok;
    if(dict.find(lexeme) != dict.end()){
        tok = dict[lexeme];
    }else{
        tok = IDENT;
    }
    return LexItem(tok, lexeme, linenum);
   
}

/*
The operator<< function accepts a reference to an ostream object and a reference to a LexItem object, 
and returns a reference to the ostream object. The operator<< function should print out the string value of the Token in the tok object, 
followed by its line number. If the Token is either an IDENT, ICONST, RCONST, or SCONST, it will print out its token followed by its lexeme between parentheses, 
and its line number.
*/
ostream& operator<<(ostream& out, const LexItem& tok){
    Token token = tok.GetToken();
    int num = tok.GetLinenum();
    string lex = tok.GetLexeme();
    if(token == 9 || token == 10 || token == 11 || token == 12 || token == 25)
        out << keys[token] << " (" << lex << ") Line #: " << num << endl; 
    else
         out << keys[token] << " Line #: " << num << endl;
    return out;
    
}


