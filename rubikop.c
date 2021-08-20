#include <stdio.h>
#include "rubikop.h"



void printcube(char Cube[12][9]){
  printf("                          l c r\n");
  printf("                        ---------\n");
  for (int i = 0; i < 12; i++) {
    if (i == 3){
        printf("                -------------------------\n      top       |");}
    else if (i == 4) printf("      mid       |");
    else if (i == 5) printf("     bottom     |");
    else if (i == 6) printf("                -------------------------\n                 ");
    else if (i == 9) printf("                        ---------\n                 ");
    else printf("                 ");
    for (int j = 0; j < 9; j++) {
      printf(" %c", Cube[i][j]);
      if(j == 2|| j==5|| (j ==8 && (i<6 && i > 2))) printf (" |");
    }
    printf("\n");
  }
  printf("                        ---------\n\n");
}
/*
es soll dann etwa so aussehen:
                          l c r
                        ---------
                        | o o o |
                        | o o o |
                        | o o o |
                -------------------------
      top       | g g g | w w w | b b b |
      mid       | g g g | w w w | b b b |
     bottom     | g g g | w w w | b b b |
                -------------------------
                        | r r r |
                        | r r r |
                        | r r r |
                        ---------
                        | y y y |
                        | y y y |
                        | y y y |
                        ---------

         ___
        | 1 |
    -------------
    | 5 | 2 | 6 |
    -------------
        | 3 |
        -----
        | 4 |
        -----






*/
void spin(char array[12][9],int x, int y, int dir){
    char temp[3][3];




    if (dir == 1){
            for (int i =0; i < 3; i++ ){
                for (int j = 0; j < 3; j++){
                    temp[i][j] = array[x+2-j][y+i];
                }
            }

    } else if (dir == -1){
        for (int i =0; i < 3; i++ ){
                for (int j = 0; j < 3; j++){
                    temp[i][j] = array[x+j][y+2-i];
                }
            }

    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            array[x+i][y+j] = temp[i][j];
        }
    }

}



void xlanetwister(char Cube[12][9], int x) {
  char temp[3];
  temp[0] = Cube[11-(x-3)][5]; //backside
  temp[1] = Cube[11-(x-3)][4];
  temp[2] = Cube[11-(x-3)][3];

  for (int i = 0; i < 3; i++){
    Cube[11-(x-3)][5-i] = Cube[x][6+i]; 
    Cube[x][6+i] = Cube[x][3+i];
    Cube[x][3+i] = Cube[x][i];
    Cube[x][i] = temp[i];
  }
}

void ylanetwister(char Cube[12][9], int y) {
  char temp[3];
  temp[0] = Cube[0][y]; //topside
  temp[1] = Cube[1][y];
  temp[2] = Cube[2][y];

  for (int i = 0; i < 3; i++) {
    Cube[0+i][y] = Cube[3+i][y];
    Cube[3+i][y] = Cube[6+i][y];
    Cube[6+i][y] = Cube[9+i][y];
    Cube[9+i][y] = temp[i];
  }
}

void rotate(char Cube[12][9]){
    printf("Direction of rotation: (1 - down, 2- right) : ");
    unsigned int i;
    scanf("%d",&i);
    do{
        if (i == 1){
            ylanetwister(Cube,3);
            ylanetwister(Cube,4);
            ylanetwister(Cube,5);
            spin(Cube,3,0,1);
            spin(Cube,3,6,-1);
        }else if (i == 2){
            xlanetwister(Cube,3);
            xlanetwister(Cube,4);
            xlanetwister(Cube,5);
            spin(Cube,0,3,-1);
            spin(Cube,3,6,1);
        }else{
          printf("\n**********INVALID DIRECTION************\n");
        }while((i!=1)||(i!=2));
}

void twist(char Cube[12][9], char lane) {
  int side, x, y, dir;
  switch (lane)
  {
  case ('l'):
    //side = 5;
    x = 3;
    y = 0;
    ylanetwister(Cube, 3);
    spin(Cube, x, y, -1);
    break;

  case ('c'):
    ylanetwister(Cube, 4);
    break;

  case ('r'):
    //side = 6;
    x = 0;
    y = 6;
    ylanetwister(Cube, 5);
    spin(Cube, x, y, 1);
    break;

  case ('t'):
    //side = 1;
    x = 0;
    y = 3;
    xlanetwister(Cube, 3);
    spin(Cube, x, y, -1);
    break;

  case ('m'):
    xlanetwister(Cube, 4);
    break;
  
  case ('b'):
    //side = 3:
    x = 6;
    y = 3;
    xlanetwister(Cube, 5);
    spin(Cube, x, y, 1);
    break;

  default:
    printf("bitte gueltige lane angeben.\n");
    return;
    break;
  }
}


  
void copycube(char Cube[12][9],char prob[12][9]){
/*würfel lösen
algorithmus oder einfach zurücksetzen?*/

    for (int i = 0; i < 12; i++){
            for (int ii = 0; ii < 9; ii++){
                Cube[i][ii] = prob[i][ii];
            }
    }
}

void solvecube(char Cube[12][9]){
/*würfel lösen
algorithmus oder einfach zurücksetzen?*/

   copycube(char Cube[12][9], char CUBE_LOESUNG [12] [9]);
}
