#include <fstream>
#include <iostream>
#include <vector>
#include <string>

enum TokenType
{
    Number,
    Identifier,
    Equals,
    OpenParen,
    CloseParen,
    BinaryOperator,
    Let,
};

std::map<TokenType, std::pair<bool, std::string> > tokenToPatternMap()
{
	std::map<TokenType, std::pair<bool, std::string> > token_to_pattern_map;

	token_to_pattern_map[TokenType::Number] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::Identifier] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::Equals] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::OpenParen] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::CloseParen] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::BinaryOperator] = std::pair(true, "[0-9]+");
	token_to_pattern_map[TokenType::Let] = std::pair(true, "[0-9]+");

	return token_to_pattern_map;
}

std::vector<TokenType> tokenTypePrecedence()
{
	std::vector<TokenType> token_type_precedence;

	token_type_precedence << TokenType::Number;
	token_type_precedence << TokenType::Identifier;
	token_type_precedence << TokenType::Equals;
	token_type_precedence << TokenType::OpenParen;
	token_type_precedence << TokenType::CloseParen;
	token_type_precedence << TokenType::BinaryOperator;
	token_type_precedence << TokenType::Let;

	return token_type_precedence;
}

std::vector<TokenType> token_type_precedence__ = tokenTypePrecedence()
std::map<TokenType, std::pair<bool, std::string> > token_to_pattern_map__ = tokenToPatternMap();

struct Token
{
    std::string value;
    TokenType type;
};

std::vector<std::string> splitString(const std::string &sourceCode) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : sourceCode) {
        if (ch != ' ') {
            word += ch;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    while (!src.empty()) {
        if (src.front() == "(") {
            tokens.push_back(token(shift(src), TokenType::OpenParen));
        }
        else if (src.front() == ")") {
            tokens.push_back(token(shift(src), TokenType::CloseParen));
        }
        // Handle other token types
        // ...
	
	if (isNumber(src.front())) {
            std::string number;
            while (!src.empty() && isNumber(src.front())) {
                number += shift(src);
            }
            tokens.push_back(token(number, TokenType::Number));
        }
	else if (isAlpha(src.front())) {
            std::string ident = shift(src);
            // Check for reserved keywords like 'let'
            // Push token to vector
        }
        else if (isSkippable(src.front()[0])) {
            shift(src);
        }
    }

    return tokens;
}

int main()
{
    // Create an input file stream object named 'file' and
    // open the file "GFG.txt".
    ifstream file("GFG.txt");

    // String to store each line of the file.
    string line;
    std::vector<std::string> tokens;

    if (file.is_open()) {
        // Read each line from the file and store it in the
        // 'line' variable.
        while (getline(file, line)) {
	    std::cout << line << std::endl;
	    tokens << tokenize(line)
        }

        // Close the file stream once all lines have been
        // read.
        file.close();
    }
    else {
        // Print an error message to the standard error
        // stream if the file cannot be opened.
	    std::cerr << "Unable to open file!" << std::endl;
    }

    std::cout << "test" << std::endl;
    return 0;
}
