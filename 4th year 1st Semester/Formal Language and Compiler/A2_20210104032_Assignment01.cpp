#include<bits/stdc++.h>

using namespace std;

void removeCommentsAndWhitespace(const string &inputFile, const string &outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    bool inWhitespace = false;

    while (input.get(c)) {
        if (inSingleLineComment) {
            if (c == '\n') {
                inSingleLineComment = false;
            }
        } else if (inMultiLineComment) {
            if (c == '*' && input.peek() == '/') {
                input.get(c); // Consume '/'
                inMultiLineComment = false;
            }
        } else {
            if (c == '/' && input.peek() == '/') {
                input.get(c); // Consume second '/'
                inSingleLineComment = true;
            } else if (c == '/' && input.peek() == '*') {
                input.get(c); // Consume '*'
                inMultiLineComment = true;
            } else {
                if (isspace(c)) {
                    if (!inWhitespace) {
                        output.put(' ');
                        inWhitespace = true;
                    }
                } else {
                    output.put(c);
                    inWhitespace = false;
                }
            }
        }
    }

    input.close();
    output.close();
}

void displayFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    while (file.get(c)) {
        cout.put(c);
    }

    file.close();
}

int main() {
    string inputFile = "source.c";
    string outputFile = "filtered.c";

    removeCommentsAndWhitespace(inputFile, outputFile);

    displayFile(outputFile);

    return 0;
}
