#include "dicegame.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandomNumber(int min, int max){
  return (rand() % (max - min + 1) + min);
}
enum ROUNDTYPE getRoundType(){
  int roundDecider = getRandomNumber(1,10);
  if(roundDecider < 5){/*50% CHANCE FOR REGULAR*/
    return REGULAR;
  }else if(roundDecider < 8){
    return DOUBLE;
  }else{
    return BONUS;
  }
  
}
int getRoundPoints(enum ROUNDTYPE roundType){
  switch(roundType){
    case BONUS:
      return 200;
    case REGULAR:
      return getRandomNumber(10,100);
    case DOUBLE:
      return getRandomNumber(10,100) * 2;
  }
  return -1;/*something has gone HORRIBLY wrong*/
}
void printPlayerPoints(int p1, int p2){
  printf("P1     : %d\n", p1);
  printf("P2     : %d\n\n", p2);
}
void printRoundInfo(enum ROUNDTYPE t, int dice, int points){
  printf("Type   : ");
  if(t == BONUS){
    printf("BONUS");
  }else if(t == REGULAR){
    printf("REGULAR");
  }else{
    printf("DOUBLE");
  }
  printf("\n");

  printf("Dice   : %d\n", dice);
  printf("Points : %d\n", points);
}