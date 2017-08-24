#include <stdio.h>
#include <stdlib.h>
#include <vector>

int
main(int argc, char *argv[]) {

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
    printf("Line length %zu : \n", read);
    printf("%s\n", line);
    break;
      } 

  return 0;
}
