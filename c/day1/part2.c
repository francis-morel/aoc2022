#include <stdio.h>

void moveMax(int max[3]);
int sumMax(int max[3]);

int main() {
  FILE *fptr;
  fptr = fopen("problem_input.txt", "r");
  if (fptr == NULL) {
    printf("File not found");
    return 0;
  }

  char line[10];
  int max[] = {0, 0, 0};
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
    if (total >= max[0]) {
      max[0] = total;
      maxElf = elf;
      printf("avant %d %d %d\n", max[0], max[1], max[2]);
      moveMax(max);
      printf("apres %d %d %d\n", max[0], max[1], max[2]);
    }
  }

  printf("Total %d calories\n", sumMax(max));

  return 0;
}

void moveMax(int max[3]) {
  for (int i = 0; i < 2; i++) {
    if (max[i] > max[i + 1]) {
      int temp = max[i + 1];
      max[i + 1] = max[i];
      max[i] = temp;
    }
  }
}

int sumMax(int max[3]) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += max[i];
  }
  return sum;
}
