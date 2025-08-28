#include<bits/stdc++.h>

using namespace std;

void lexemeSeparator(ifstream &source, ofstream &target);
void lexemeTokenization(ifstream &source, ofstream &target);
bool isKeyword(const string &lex);
bool isIdentifier(const string &lex);
bool isSeparator(const string &lex);
bool isNumerical(const string &lex);
bool isOperator(const string &lex);
bool isParenthesis(const string &lex);

int main() {
    string inputFile = "datafile1.c";
    string tempFile = "LexemeSeparatedTemp.txt";
    string targetFile = "Output_Asm2.txt";

    ifstream source;
    ofstream temp, target;

    // Lexeme separator
    source.open(inputFile);
    temp.open(tempFile);
    lexemeSeparator(source, temp);
    source.close();
    temp.close();

    // Lexeme categorizer
    ifstream tempInput(tempFile);
    target.open(targetFile);
    lexemeTokenization(tempInput, target);
    tempInput.close();
    target.close();

    // Display output file
    ifstream output(targetFile);
    char c;
    while (output.get(c)) {
        cout << c;
    }
    output.close();

    remove(tempFile.c_str());
    return 0;
}

void lexemeSeparator(ifstream &source, ofstream &target) {
    char c;
    int lexemeStart = 0;

    if (!source || !target) {
        cerr << "\nFile cannot be opened" << endl;
        return;
    }

    while (source.get(c)) {
        if (c == ' ') {
            target.put(' ');
            lexemeStart = 0;
            continue;
        }
        if (c != ' ' && lexemeStart == 0) {
            lexemeStart = 1;
        }
        if (lexemeStart == 1) {
            if (strchr(";,\'+-*/%()", c)) {
                target.put(' ');
                target.put(c);
                lexemeStart = 0;

                char cc = source.peek();
                if (cc == '+' || cc == '-' || cc == ';') {
                    target.put(cc);
                    target.put(' ');
                    source.get();
                } else {
                    target.put(' ');
                }
                continue;
            } else if (strchr("><!=|&", c)) {
                target.put(' ');
                target.put(c);
                lexemeStart = 0;

                char cc = source.peek();
                if (cc == '=' || cc == '|' || cc == '&') {
                    target.put(cc);
                    target.put(' ');
                    source.get();
                } else {
                    target.put(' ');
                }
                continue;
            }
            target.put(c);
        }
    }
    target.put(' ');
}

void lexemeTokenization(ifstream &source, ofstream &target) {
    char c;
    string lex;

    if (!source || !target) {
        cerr << "\nFile cannot be opened" << endl;
        return;
    }

    while (source.get(c)) {
        if (c == ' ') {
            if (!lex.empty()) {
                if (isSeparator(lex)) {
                    target << "[sep " << lex << "] ";
                } else if (isParenthesis(lex)) {
                    target << "[par " << lex << "] ";
                } else if (isOperator(lex)) {
                    target << "[op " << lex << "] ";
                } else if (isNumerical(lex)) {
                    target << "[num " << lex << "] ";
                } else if (isKeyword(lex)) {
                    target << "[kw " << lex << "] ";
                } else if (isIdentifier(lex)) {
                    target << "[id " << lex << "] ";
                } else {
                    target << "[unkn " << lex << "] ";
                }
            }
            lex.clear();
        } else {
            lex.push_back(c);
        }
    }
}

bool isNumerical(const string &lex) {
    bool hasDecimal = false;

    for (size_t i = 0; i < lex.size(); ++i) {
        if (isdigit(lex[i])) {
            continue;
        } else if (lex[i] == '.' && !hasDecimal) {
            hasDecimal = true;
        } else {
            return false;
        }
    }
    return true;
}

bool isSeparator(const string &lex) {
    return lex == ";" || lex == "," || lex == "\'";
}

bool isParenthesis(const string &lex) {
    return lex == "(" || lex == ")" || lex == "{" || lex == "}";
}

bool isOperator(const string &lex) {
    static const string operators[] = {"+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|", "~", "^",
                                       "++", "--", "==", "!=", "&&", "||", ">=", "<="};
    for (const auto &op : operators) {
        if (lex == op) return true;
    }
    return false;
}

bool isIdentifier(const string &lex) {
    if (isalpha(lex[0]) || lex[0] == '_') {
        for (char ch : lex) {
            if (!isalnum(ch) && ch != '_') return false;
        }
        return true;
    }
    return false;
}

bool isKeyword(const string &lex) {
    static const string keywords[] = {
        "int", "char", "float", "double", "long", "short", "while", "for", "do", "if", "else", "void",
        "static", "break", "continue", "default", "const", "switch", "case", "sizeof", "struct",
        "signed", "unsigned", "return", "auto", "enum", "extern", "goto", "register", "union",
        "typedef", "volatile"
    };
    for (const auto &kw : keywords) {
        if (lex == kw) return true;
    }
    return false;
}
