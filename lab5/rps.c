#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumGames(void);
int findWinner(int, int);
void printResults(int, int, int);

int main(void) {
  srand(0);
  int games, p1move, p2move, ans;
  int ties = 0, p1wins = 0, p2wins = 0;
  games = getNumGames();
  for (int a = 0; a<games; a++) {
    p1move = rand() % 3;
    p2move = rand() % 3;
    ans = findWinner(p1move, p2move);
    if (ans == 0) ties++;
    if (ans == 1) p1wins++;
    if (ans == 2) p2wins++;
  }
  printResults(ties, p1wins, p2wins);
  return 0;
}

int getNumGames(void) {
  int numGames;
  printf("Enter the number of games: ");
  scanf("%d", &numGames);
  return numGames;
}

int findWinner(int x, int y) {
  if ((x == 0) && (y == 0)) return 0;
  else if ((x == 0) && (y == 1)) return 2;
  else if ((x == 0) && (y == 2)) return 1;
  else if ((x == 1) && (y == 1)) return 0;
  else if ((x == 1) && (y == 2)) return 2;
  else if ((x == 1) && (y == 0)) return 1;
  else if ((x == 2) && (y == 0)) return 2;
  else if ((x == 2) && (y == 1)) return 1;
  else if ((x == 2) && (y == 2)) return 0;
  return -1;
}

void printResults(int x, int y, int z) {
printf("There were %d ties, %d player one wins, %d player two wins\n", x, y, z);
return;
}
