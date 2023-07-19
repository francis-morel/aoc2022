#include <stdbool.h>
#include <stdio.h>
struct Round {
  char opponent;
  char me;
};

struct Round *readRound(FILE *file, struct Round *round) {
  round->opponent = fgetc(file);
  fgetc(file);
  round->me = fgetc(file);
  fgetc(file);
  printf("opp: %c, me: %c\n", round->opponent, round->me);
  return round;
}

bool validRound(struct Round *round) {
  return round->opponent != EOF && round->me != EOF;
}

int victoryPoints(struct Round *round) {
  char opp = round->opponent;
  char me = round->me;
  int offset = 'X' - 'A';
  if (opp == me - offset) {
    return 3;
  }

  if ((me == 'X' && opp == 'C') || (me == 'Y' && opp == 'A') ||
      (me == 'Z' && opp == 'B')) {
    return 6;
  }

  return 0;
}

int choicePoints(struct Round *round) {
  char me = round->me;
  if (me == 'X') {
    return 1;
  } else if (me == 'Y') {
    return 2;
  } else {
    return 3;
  }
}

int roundScore(struct Round *round) {
  int v = victoryPoints(round);
  int c = choicePoints(round);

  printf("Round: %d, Choice: %d\n", v, c);
  return victoryPoints(round) + choicePoints(round);
}

void convertRound(struct Round *round) {
  char opp = round->opponent;
  char me = round->me;

  if (me == 'Y') {
    round->me = opp + ('X' - 'A');
    return;
  } else if (me == 'X') {
    // I need to lose
    if (opp == 'A') {
      round->me = 'Z';
    } else if (opp == 'B') {
      round->me = 'X';
    } else {
      round->me = 'Y';
    }
  } else {
    // I need to win
    if (opp == 'A') {
      round->me = 'Y';
    } else if (opp == 'B') {
      round->me = 'Z';
    } else {
      round->me = 'X';
    }
  }
}

int main() {
  FILE *file = fopen("strategy_guide.txt", "r");
  struct Round round;
  struct Round *pround = &round;
  int total = 0;
  while (validRound(readRound(file, pround))) {
    convertRound(pround);
    total += roundScore(pround);
  }

  printf("%d\n", total);
  fclose(file);
}
