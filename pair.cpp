#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

bool checkDoubleU(std::string word);
bool checkNoU(std::string word);
bool checkPal(std::string word);

int
main(int argc, char *argv[]) {

  int counter = 0;

  const char *filename = "sowpods.txt";
  FILE *file = fopen(filename, "r");

  ssize_t read;
  char *line = NULL;
  size_t linecap = 0;

  std::vector<std::string> words;

  if (file == NULL) {
    printf("Exit here\n");
    exit(1);
  }

  while ((read = getline(&line, &linecap, file) > 0)) {
    words.push_back(line);
  };

  for (std::string word : words) {
    //if(checkDoubleU(word)) {
    //  std::cout << word;
    //  counter++;
    //}
    
    if (checkNoU(word)) {
      std::cout << word;
      counter++;
    }
  }

  printf("Number of words found: %d\n", counter);
  return 0;
}

bool checkDoubleU(std::string word) {

  for (unsigned int i = 0; i < word.length(); i++) {
    char c = word[i];

    if (c == 'U' && c == word[i + 1]) {
      return true;
    }
  }

  return false;
}

bool checkNoU(std::string word) {

  bool hasQ = false;
  bool hasU = false;

  for (unsigned int i = 0; i < word.length(); i++) {
    char c = word[i];

    if (c == 'Q') {
      hasQ = true;
    }

    if (c == 'U') {
      hasU = true;
    }
  }

  return (hasQ && !hasU);
}

bool checkPal(std::string word) {

  for (unsigned int i = 0; i < (word.length() / 2); i++) {

    if (word[i] == (word[word.length() - i])) {
      return false;
    }
  }
}
