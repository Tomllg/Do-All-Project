/*     / - - ) /-----/          /-- \     /--/      /--/
**    /  /  / /  /  /  ____    / /\ \    /  /      /  /
**   /  /  / /  /  /  |____|  / __  \   /  /____  /  /____
**  /_____) /____ /          /_/  \_\  /_______/ /_______/
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/doall.h"

int      isupper(char *str) {

  int     i;

  i = 0;
  while (str && str[i] != '\0') {
    if (str[i] < 65 || str[i] > 90) {
      printf("You are trying to do something impossible, please enter UPPER letters.\n");
      return (1);
    }
    i++;
  }
  return (0);

}

void      eldecrypt(char *todecrypt, int decrypt) {

  int     i;
  char    *replace;

  i = 0;
  if ((replace = malloc(sizeof(decrypt) + 1)) == NULL) {
    return ;
  }
  while (todecrypt && todecrypt[i] != '\0') {
    replace[i] = todecrypt[i] - decrypt;
    i++;
  }
  replace[i] = '\0';
  printf("%s\n", replace);
}
