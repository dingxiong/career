#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using StringVec = std::vector<std::string>;

/**
 * Drawback:
 * 1. Only works for space sperated string
 */
StringVec split(const std::string &input) {
  std::istringstream iss(input);
  std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());
  return results;
}

/*
 * Drawbacks:
 * 1. The delimitor can only be character.
 */
StringVec split_char(const std::string &input, char del = ' ') {
  std::stringstream ss(input);
  std::string token;
  StringVec tokens;
  while (std::getline(ss, token, del)) {
    tokens.push_back(token);
  }
  return tokens;
}

/**
 * Drawbacks:
 * 1. Only allow one string as delimeter.
 */
StringVec split_str(const std::string &input, const std::string &del = " ") {
  StringVec tokens;
  int start = 0, end;
  while ((end = input.find(del, start)) != std::string::npos) {
    tokens.push_back(input.substr(start, end - start));
    start = end + del.size();
  }
  tokens.push_back(input.substr(start));
  return tokens;
}

/**
 * Use multiple different chars as delimeter
 */
StringVec split_chars(const std::string &input, const std::string &dels = " ") {
  StringVec tokens;
  int start = 0, end;
  while ((end = input.find_first_of(dels, start)) != std::string::npos) {
    tokens.push_back(input.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(input.substr(start));
  return tokens;
}

// TODO: implement the regex version of split

void printVec(const StringVec &result) {
  std::copy(result.begin(), result.end(),
            std::ostream_iterator<std::string>(std::cout, ","));
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  {
    // test printVec
    StringVec result = {"a", "b", "c"};
    printVec(result);
  }
  {
    std::string input = "Let  me  split  this  into     words";
    StringVec result;
    result = split(input);
    result = split_char(input);
    printVec(result);
  }
  {
    std::string input = "Let  me  split  this  into     words";
    printVec(split_str(input));
  }

  {
    std::string input = "Let|me~ shabi +dfd- dd";
    printVec(split_chars(input, " +|~-"));
  }

  return 0;
}