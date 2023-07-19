// 1. read line
// 2. find length
// 3. create 1 array of length 52 (each alphabethic letters a-Z)
// 4. add the items of the first rucksack to the array at the right position
// 5. check if the item of the second rucksack is in the array. If item is
// present, we found the duplicate.

#include <stdio.h>
#include <string.h>

int BUFFER_LENGTH = 100;
int calculateRucksack(char line[BUFFER_LENGTH]);

int main() {
  FILE *file = fopen("rucksacks.txt", "r");

  char line[BUFFER_LENGTH];
  int total = 0;
  while (fgets(line, BUFFER_LENGTH, file)) {
    int current = calculateRucksack(line);
    printf("Current: %d\n", current);
    total += current;
  }

  printf("%d\n", total);

  fclose(file);
  return 0;
}

int charIndex(char c) {
  if (c <= 'Z') {
    return c - 'A' + 26;
  } else {
    return c - 'a';
  }
}

int calculateRucksack(char line[BUFFER_LENGTH]) {
  int length = strlen(line) - 1;

  char rucksack[52];
  for (int i = 0; i < 52; i++) {
    rucksack[i] = '_';
  }
  // Add first compartment to the rucksack
  for (int i = 0; i < length / 2; i++) {
    // printf("index: %d\n", charIndex(line[i]));
    rucksack[charIndex(line[i])] = line[i];
  }

  // Check if an item in the second compartment is present in the first one
  for (int i = (length / 2); i < length; i++) {
    if (rucksack[charIndex(line[i])] == line[i]) {
      return charIndex(line[i]) + 1;
    }
  }

  return 0;
}
