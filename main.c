#include <stdio.h>
#include <stdlib.h>
#include "rubikop.h"

static char CUBE [12] [9];

int main() {
  printf("Willkommen zu Rubik's Cube\n");
  printf("Waehle einen Schwierigkeitsgrad\n");
  printf("1 = einfach, 2 = schwer\n");
  int sg = 0;
  sg = getint();
  do {
    if(sg == 1) {
      copycube(CUBE, EASY);
    }
    else if(sg == 2) {
      copycube(CUBE, HARD);
    }
    else {
      printf("bitte gueltige Option waehlen.\n");
    }
  } while(sg != 1 && sg != 2);

  printf(" y = gelb \n g = gruen \n w = weiß \n b = blau \n r = rot \n o = orange \n");
  printcube(CUBE);

  do {
    printf("Steuerung:\n");
    printf("r = Wuerfel rotieren, t = Zeile/Spalte nach rechts/oben drehen\n");
    printf("s = Wuerfel loesen, q = beenden\n\n");
    printf("Deine Auswahl: ");
    char w = getchar();
    switch (w)
    {
    case 't':
      printf("Welche Zeile/Spalte?\n");
      printf("'u'/'b'/'l'/'r'\n");
      char lane = getchar();
      twist(CUBE, lane);
      printcube(CUBE);
      break;

    case 'r':
      rotate(CUBE);
      printcube(CUBE);
      break;

    case 's':
      printf("Wuerfel wird geloest. \n");
      solvecube(CUBE);
      printcube(CUBE);
      break;

    case 'q':
      printf("ciao\n");
      return 1;
      break;
    
    default:
      printf("bitte waehle eine gueltige option.\n");
      break;
    }

  } while(1);

  return 1;
}
