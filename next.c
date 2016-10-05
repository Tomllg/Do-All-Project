/*     / - - ) /-----/          /-- \     /--/      /--/
**    /  /  / /  /  /  ____    / /\ \    /  /      /  /
**   /  /  / /  /  /  |____|  / __  \   /  /____  /  /____
**  /_____) /____ /          /_/  \_\  /_______/ /_______/
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/doall.h"

#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[010;31m"
#define NORMAL "\033[00m"
#define SOULIGNE "\033[04m"

void          elcrypt(char *tocrypt, int crypt) {

  int         i;
  char        *replace;

  i = 0;

  if (crypt <= 0) {
    return ;
  }
  if ((replace = malloc(sizeof(tocrypt) + 1)) == NULL || isupper(tocrypt) == 1) {
    return ;
  }
  while (tocrypt && tocrypt[i] != '\0') {
    replace[i] = tocrypt[i] + crypt;
    i++;
  }
  replace[i] = '\0';
  printf("%s\n", replace);
}


int           my_strlen(char *str) {

  int         i;

  i = 0;
  while (str && str[i] != '\0') {
    i++;
  }
  return (i);
}

void          dousage() {

  printf(BLEUCLAIR "Your possibilities are :\n" NORMAL);
  printf(ROUGE "• Draw Square :        ");
  printf(NORMAL "./doall b x[width] y[height]\n");
  printf(ROUGE "• Calculator :         ");
  printf(NORMAL "./doall c [x] [operator] [y]\n");
  printf(ROUGE "• Number Game :        ");
  printf(NORMAL "./doall g\n");
  printf(ROUGE "• Calendar :           ");
  printf(NORMAL "./doall t\n");
  printf(ROUGE "• Beginner Shortcuts : ");
  printf(NORMAL "./doall i\n");
  printf(ROUGE "• Identificator :     ");
  printf(NORMAL " ./doall w\n");
  printf(ROUGE "• ElCrypt :           ");
  printf(NORMAL " ./doall k [wordtocrypt] [numberkeycrypt]\n");
  printf(ROUGE "• ElDecrypt :         ");
  printf(NORMAL " ./doall d [wordtodecrypt] [numberkeydecrypt]\n");
  printf("  ");
  printf(SOULIGNE "(Pay attention to use only UPPER letters for ElCrypt.)\n");
}

void          doinfo() {

  printf(BLEUCLAIR "Here are beginner shortcuts, if you wanna have fun and create a file, or a directory.\n" NORMAL);
  printf(ROUGE "• cd                    :" NORMAL " open your home directory.\n");
  printf(ROUGE "• cd [directory]        :" NORMAL " open directory choosen.\n");
  printf(ROUGE "• ls                    :" NORMAL " list all files and directories in your currend directory.\n");
  printf(ROUGE "• emacs [filename]      :" NORMAL " create a file named 'filename'.\n   - To save the file type -> ctrl+s.\n   - To quit the file type -> ctrl+q.\n");
  printf(ROUGE "• pwd                   :" NORMAL " show path of were you are.\n");
  printf(ROUGE "• mkdir [directoryname] :" NORMAL " create a directory named 'directoryname'.\n");
  printf(ROUGE "• rm [-rf]              :" NORMAL " delete a file '-f' or a directory '-rf'.\n");
  printf(ROUGE "• cc [filename]         :" NORMAL " compile a file named 'filename' into ./a.out.\n");
  printf(ROUGE "• ./a.out               :" NORMAL " execute executable ./a.out.\n");

}

int      isnb(char *str) {

  int     i;

  i = 0;
  while (str && str[i] != '\0') {
    if (str[i] > 57 || str[i] < 48) {
      printf("That's not a valid number, sorry!\n");
      return (0);
    }
    i++;
  }
  return (1);
}
