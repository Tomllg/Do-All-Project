/*     / - - ) /-----/          /-- \     /--/      /--/
**    /  /  / /  /  /  ____    / /\ \    /  /      /  /
**   /  /  / /  /  /  |____|  / __  \   /  /____  /  /____
**  /____ ) /____ /          /_/  \_\  /_______/ /_______/
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/doall.h"

void  doinfo();

int     check(int ac, char **av) {

  int   size;

  size = my_strlen(av[1]);
  if (size > 1 || ac > 5) {
    dousage();
    return (1);
  }
  return (0);

}

int     main(int ac, char **av) {

  char  *login;

  if (check(ac, av) == 1) {
    return (1);
  }
  if (ac == 2 && av[1][0] == 'g') {
    game();
  } else if (ac == 2 && av[1][0] == 't') {
    date();
  } else if (ac == 2 && av[1][0] == 'w') {
    login = getlogin();
    printf("%s\n(Hint: enter 'whoami' in terminal to obtain same result!)\n", login);
  } else if (ac == 2 && av[1][0] == 'i') {
    doinfo();
  } else if (ac == 4 && av[1][0] == 'k') {
    elcrypt(av[2], atoi(av[3]));
  } else if (ac == 4 && av[1][0] == 'd') {
    eldecrypt(av[2], atoi(av[3]));
  } else if (ac == 4 && av[1][0] == 'b') {
    construct(atoi(av[2]), atoi(av[3]), av);
  } else if (ac == 5 && av[1][0] == 'c') {
    calcul(atof(av[2]), atof(av[4]), av[3][0]);
  } else {
    dousage();
  }

}
