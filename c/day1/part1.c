#include <stdio.h>
int main() {
  FILE *fptr;
  fptr = fopen("problem_input.txt", "r");
  if (fptr == NULL) {
    printf("File not found");
    return 0;
  }

  char line[10];
  int max = 0;
  int elf = 0;
  int maxElf = 0;

  while (fgets(line, 10, fptr)) {
    elf++;
    // Lecture des calories d'un elf
    int total = 0;
    while (line[0] != '\n') {
      // Lecture de chaques calories d'un elf
      int calories;
      sscanf(line, "%d", &calories);
      total += calories;
      if (!fgets(line, 10, fptr)) {
        break;
      }
    }
    if (total >= max) {
      max = total;
      maxElf = elf;
    }
  }

  printf("Elf #%d a %d calories\n", maxElf, max);

  return 0;
}
