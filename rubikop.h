#ifndef     RUBIK_OP_INCLUDED
#define     RUBIK_OP_INCLUDED

const char CUBE_LOESUNG [12] [9] = { //              left midc right
                       {' ', ' ', ' ', 'y', 'y', 'y', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'y', 'y', 'y', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'y', 'y', 'y', ' ', ' ', ' '},
            /*top*/    {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b'},
            /*midr*/   {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b'},
            /*bottom*/ {'g', 'g', 'g', 'w', 'w', 'w', 'b', 'b', 'b'},
                       {' ', ' ', ' ', 'r', 'r', 'r', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'r', 'r', 'r', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'r', 'r', 'r', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'o', 'o', 'o', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'o', 'o', 'o', ' ', ' ', ' '},
                       {' ', ' ', ' ', 'o', 'o', 'o', ' ', ' ', ' '}};


//EASY//EASY//EASY//EASY//EASY//EASY//EASY//EASY//EASY//EASY//EASY//EASY
//t 'r', t 'b' x3, t 'l' x3
//from start to get this array

const char EASY[12] [9] = {{' ', ' ', ' ', 'g', 'o', 'w', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'o', 'w', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'o', 'w', ' ', ' ', ' '},
            /*top*/       {'w', 'g', 'g', 'o', 'w', 'r', 'b', 'b', 'b'},
            /*midr*/      {'w', 'g', 'g', 'o', 'w', 'r', 'b', 'b', 'b'},
            /*bottom*/    {'r', 'g', 'g', 'o', 'b', 'b', 'o', 'y', 'y'},
                          {' ', ' ', ' ', 'w', 'y', 'y', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'w', 'r', 'r', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'b', 'r', 'r', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'g', 'g', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'r', 'y', 'o', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'r', 'y', 'o', ' ', ' ', ' '}};

// to solve: twist 'l', twist 'b', twist 'r' x3
// testcase?


//HARD//HARD//HARD//HARD//HARD//HARD//HARD//HARD//HARD//HARD//HARD//HARD
//t 'l', t 'u' x3, t 'b', t 'r' x3, t 'u' x3, t 'l', r 'r', t 'r' x3
//from start to get this array

const char HARD[12] [9] = {{' ', ' ', ' ', 'g', 'r', 'b', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'o', 'b', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'b', 'w', 'w', ' ', ' ', ' '},
            /*top*/       {'y', 'b', 'w', 'r', 'g', 'o', 'g', 'o', 'o'},
            /*midr*/      {'r', 'w', 'o', 'y', 'b', 'o', 'w', 'y', 'b'},
            /*bottom*/    {'r', 'g', 'o', 'y', 'b', 'w', 'r', 'r', 'y'},
                          {' ', ' ', ' ', 'b', 'w', 'g', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'r', 'w', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'b', 'o', 'r', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'g', 'g', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'y', 'g', 'r', ' ', ' ', ' '},
                          {' ', ' ', ' ', 'o', 'g', 'w', ' ', ' ', ' '}};

// to solve: twist 'r', rotate 'l', twist 'l' x3, twist 'u', twist 'r', twist 'b' x3,
// twist 'u', twist 'r' x3
// testcase


void printcube(char Cube[12][9]);
//Würfel ausgeben

void rotate(char Cube[12][9]);
/*würfel rotieren*/

void twist(char Cube[12] [9], char lane);
/*top, bottom, left, right (eine lane) drehen
(links nach rechts, von unten nach oben)
*/
void xlanetwister(char Cube[12][9], int x);
//reihe drehen
void ylanetwister(char Cube[12][9], int y);
//spalte drehen

void spin(char array[12][9],int x, int y, int dir);
/*wichtig wenn turn an einer nicht-mittigen angewendet wird
die seite muss dann um 90° gedreht werden in richtung dir
*/

void copycube(char Cube[12][9],char prob[12][9]);
/*Würfel kopieren
*/

void solvecube(char Cube[12][9]);
/*würfel lösen
algorithmus oder einfach zurücksetzen?*/

#endif
