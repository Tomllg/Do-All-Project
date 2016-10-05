/*     / - - ) /-----/          /-- \     /--/      /--/
**    /  /  / /  /  /  ____    / /\ \    /  /      /  /
**   /  /  / /  /  /  |____|  / __  \   /  /____  /  /____
**  /_____) /____ /          /_/  \_\  /_______/ /_______/
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "./include/doall.h"

int   isnb(char *);

void          date() {

  time_t      rawtime;
  const char  *listMonth[] = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};
  struct tm   *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("Nous sommes le %02u %s %04u.\n", timeinfo->tm_mday, listMonth[timeinfo->tm_mon], 1900 + timeinfo->tm_year);
  printf("Il est %02uh %02umin %02usec.\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

}

void        game() {

  int       num;
  char      number[10] = {0};

  srand(time(NULL));
  num = rand()%1000;
  printf("Are you going to find my secret number ? (Hint: number is between 0 - 1000)\n");
  while (atoi(number) != num) {
    scanf("%s", number);
    if (isnb(number) == 1) {
      if (atoi(number) > num) {
        printf("It's less!\n");
      } else if (atoi(number) < num) {
        printf("It's more!\n");
      }
    }
  }
  printf("You fin the magic number, congrats !\nThis number is: %d\n", num);
}

void        calcul(double x, double y, char c) {

  double    i;

  i = 0;
  if ((c != '*' && c != '/' && c != '+' && c != '-') || x <= 0 || y <= 0) {
    printf("Wrong arguments, your possibilities are :\n Calculator ./a.out c [x] '[operator]' [y]\n");
    return ;
  }
  if (c == '*') {
    i = x * y;
    printf("%.2f\n", i);
  } else if (c == '+') {
    i = x + y;
    printf("%.2f\n", i);
  } else if (c == '-') {
    i = x - y;
    printf("%.2f\n", i);
  } else if (c == '/') {
    i = x / y;
    printf("%.2f\n", i);
  }
}

void        construct(int x, int y, char **av) {

  int       i;
  int       j;

  i = j = 0;
  if (atoi(av[2]) <= 0 || atoi(av[3]) <= 0) {
    printf("Wrong arguments, your possibilities are :\n Draw Square ./a.out d x[width] y[height]\n");
  }
  while (i < x) {
    printf("*");
    i++;
  }
  printf("\n");
  i = 0;
  while (i < y - 2) {
    printf("*");
    while (j < x - 2) {
      printf(" ");
      j++;
    }
    printf("*\n");
    j = 0;
    i++;
  }
  i = 0;
  while (i < x) {
    printf("*");
    i++;
  }
  printf("\n");
}
