/*My name is Nguyen Hung Nguyen and this is my project 2*/
#include <stdio.h>
#include <string.h>

int main(void) {
  char foodType[50], meatType[50], ground[50], smashed[50], buttered[50], butterSideUp[50], junkType[50], sprinkles[50], nuggets[50], floorTime[50], floorClean[50], steak[50], fresh[50], brush[50];
  printf("What fell on the floor? ");
  scanf("%s", foodType);
  if (strcmp(foodType,"meat") == 0) {
    printf("What kind of meat? ");
    scanf("%s", meatType);
    if (strcmp(meatType,"chicken") == 0) {
      printf("Nuggets? ");
      scanf("%s", nuggets);
      if (strcmp(nuggets,"yes") == 0) {
        printf("On the floor for more than 3 seconds? ");
        scanf("%s", floorTime);
        if (strcmp(floorTime,"yes") == 0)
          printf("Do NOT Eat What Dropped\n");
        else printf("You Can Eat What Dropped\n");
      }
      else {
        printf("Is the floor clean? ");
        scanf("%s", floorClean);
        if (strcmp(floorClean,"yes") == 0) {
          printf("On the floor for more than 3 seconds? ");
          scanf("%s", floorTime);
          if (strcmp(floorTime,"yes") == 0)
            printf("Do NOT Eat What Dropped\n");
          else printf("You Can Eat What Dropped\n");
        }
        else printf("Do NOT Eat What Dropped\n");
      }
    }
    else if (strcmp(meatType,"beef") == 0) {
      printf("Steak? ");
      scanf("%s",steak);
      if (strcmp(steak,"yes") == 0) {
        printf("You Can Eat What Dropped\n");
      }
      else {
        printf("Is the floor clean? ");
        scanf("%s", floorClean);
        if (strcmp(floorClean,"yes") == 0) {
          printf("On the floor for more than 3 seconds? ");
          scanf("%s", floorTime);
          if (strcmp(floorTime,"yes") == 0)
            printf("Do NOT Eat What Dropped\n");
          else printf("You Can Eat What Dropped\n");
        }
        else printf("Do NOT Eat What Dropped\n");
      }
    }
    else if (strcmp(meatType, "other") == 0) {
      printf("Leftovers or fresh? ");
      scanf("%s", fresh);
      if (strcmp(fresh,"fresh") == 0) {
        printf("Can you brush it off? ");
        scanf("%s", brush);
        if (strcmp(brush, "yes") == 0)
          printf("You Can Eat What Dropped\n");
        else printf("Do NOT Eat What Dropped\n");
      }
      else {
        printf("On the floor for more than 3 seconds? ");
        scanf("%s", floorTime);
        if (strcmp(floorTime,"yes") == 0)
          printf("Do NOT Eat What Dropped\n");
        else printf("You Can Eat What Dropped\n");
      }
    }
  }
  else if (strcmp(foodType, "produce") == 0) {
    printf("Does it grow in the ground? ");
    scanf("%s", ground);
    if (strcmp(ground, "yes") == 0) {
      printf("On the floor for more than 3 seconds? ");
      scanf("%s", floorTime);
      if (strcmp(floorTime,"yes") == 0)
        printf("Do NOT Eat What Dropped\n");
      else printf("You Can Eat What Dropped\n");
    }
    else {
      printf("Smashed or bruised? ");
      scanf("%s", smashed);
      if (strcmp(smashed, "yes") == 0)
        printf("Do NOT Eat What Dropped\n");
      else {
        printf("Is the floor clean? ");
        scanf("%s", floorClean);
        if (strcmp(floorClean,"yes") == 0)
          printf("You Can Eat What Dropped\n");
        else {
          printf("On the floor for more than 3 seconds? ");
          scanf("%s", floorTime);
          if (strcmp(floorTime,"yes") == 0)
            printf("Do NOT Eat What Dropped\n");
          else printf("You Can Eat What Dropped\n");
        }
      }
    }
  }
  else if (strcmp(foodType,"bread") == 0) {
    printf("Buttered? ");
    scanf("%s", buttered);
    if (strcmp(buttered,"yes") == 0) {
      printf("Butter side up? ");
      scanf("%s", butterSideUp);
      if (strcmp(butterSideUp, "yes") == 0) {
        printf("Is the floor clean? ");
        scanf("%s", floorClean);
        if (strcmp(floorClean,"yes") == 0)
          printf("You Can Eat What Dropped\n");
        else printf("Do NOT Eat What Dropped\n");
      }
      else printf("Do NOT Eat What Dropped\n");
    }
    else {
      printf("Is the floor clean? ");
      scanf("%s", floorClean);
      if (strcmp(floorClean,"yes") == 0)
        printf("You Can Eat What Dropped\n");
      else printf("Do NOT Eat What Dropped\n");
    }
  }
  else if (strcmp(foodType,"junk-food") == 0) {
    printf("What kind? ");
    scanf("%s", junkType);
    if (strcmp(junkType,"candy") == 0) {
      printf("Is the floor clean? ");
      scanf("%s", floorClean);
      if (strcmp(floorClean,"yes") == 0)
        printf("You Can Eat What Dropped\n");
      else printf("Do NOT Eat What Dropped\n");
    }
    else if (strcmp(junkType, "donuts") == 0) {
      printf("Sprinkles? ");
      scanf("%s", sprinkles);
      if (strcmp(sprinkles, "yes") == 0) {
        printf("Is the floor clean? ");
        scanf("%s", floorClean);
        if (strcmp(floorClean,"yes") == 0)
          printf("You Can Eat What Dropped\n");
        else {
          printf("Can you brush it off? ");
          scanf("%s", brush);
          if (strcmp(brush,"yes") == 0) {
            printf("On the floor for more than 3 seconds? ");
            scanf("%s", floorTime);
            if (strcmp(floorTime,"yes") == 0)
              printf("Do NOT Eat What Dropped\n");
            else printf("You Can Eat What Dropped\n");
          }
          else printf("Do NOT Eat What Dropped\n");
        }
      }
      else {
        printf("On the floor for more than 3 seconds? ");
        scanf("%s", floorTime);
        if (strcmp(floorTime,"yes") == 0)
          printf("Do NOT Eat What Dropped\n");
        else printf("You Can Eat What Dropped\n");
      }
    }
    else if (strcmp(junkType, "chips") == 0) {
      printf("Can you brush it off? ");
      scanf("%s", brush);
      if (strcmp(brush,"yes") == 0) {
        printf("On the floor for more than 3 seconds? ");
        scanf("%s", floorTime);
        if (strcmp(floorTime,"yes") == 0)
          printf("Do NOT Eat What Dropped\n");
        else printf("You Can Eat What Dropped\n");
      }
      else printf("Do NOT Eat What Dropped\n");
    }
  }
return 0;
}
