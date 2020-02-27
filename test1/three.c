#include <stdio.h>
#include <string.h>

int main(void) {
  char move1[20], move2[20];

  printf("Player 1 move: ");
  scanf("%s", move1);
  printf("Player 2 move: ");
  scanf("%s", move2);
  if (strcmp(move1, "rock")==0) {
    if (strcmp(move2, "rock") == 0) printf("Tie\n");
    else if (strcmp(move2, "scissors") == 0) printf("Player 1 wins\n");
    else if (strcmp(move2, "paper") == 0) printf("Player 2 wins\n");
  }
  else if (strcmp(move1, "paper")==0) {
        if (strcmp(move2, "rock") == 0) printf("Player 1 wins\n");
        else if (strcmp(move2, "scissors") == 0) printf("Player 2 wins\n");
        else if (strcmp(move2, "paper") == 0) printf("Tie\n");
  }
  else if (strcmp(move1, "scissors")==0) {
    if (strcmp(move2, "rock") == 0) printf("Player 2 wins\n");
    else if (strcmp(move2, "scissors") == 0) printf("Tie\n");
    else if (strcmp(move2, "paper") == 0) printf("Player 1 wins\n");
  }
return 0;
}
