#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main(int argc, char * argv[]){
  int rounds, diceVal, roundPoints, currentPlayer;
  int p1 = 0, p2 = 0;
  int i = 0;
  
  srand(time(NULL));
  
  printf("Enter the number of rounds: ");
  /*while(!getChar());*//*probably not needed, untested*/
  scanf("%d", &rounds);

  printPlayerPoints(p1, p2);

  /* main program loop*/
  for(i = 0; i < rounds; i++){
    /*get conditions for the round*/
    enum ROUNDTYPE roundType = getRoundType();
    roundPoints = getRoundPoints(roundType);
    diceVal = getRandomNumber(1,6);
    currentPlayer = getRandomNumber(1,2);
    
    printf("ROUND %d\n--------\n", i + 1);
    printf("Player : %d\n", currentPlayer);
    printRoundInfo(roundType, diceVal, roundPoints);

    
    if(currentPlayer == 1){
      if(diceVal % 2 == 1){/*SUCCESS*/
        p1 += roundPoints;
      }else{/*FAILURE*/
        p1 -= roundPoints;
        currentPlayer = 2;/*now we go to the other player*/
      }
    }else{
      if(diceVal % 2 == 0){/*SUCCESS*/
        p2 += roundPoints;
      }else{/*FAILURE*/
        p2 -= roundPoints;
        currentPlayer = 1;/*now we go to the other player*/
      }
    }
    
    printPlayerPoints(p1, p2);

  }


  printf("GAME OVER!!\n");
  (p1 > p2) ? printf("P1 Won\n") : printf("P2 Won\n");

  return 0;
}
