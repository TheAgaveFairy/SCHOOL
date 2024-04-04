#ifndef DICEGAME_H
#define DICEGAME_H

enum ROUNDTYPE {BONUS, REGULAR, DOUBLE};
int getRandomNumber(int min, int max);
enum ROUNDTYPE getRoundType();
int getRoundPoints(enum ROUNDTYPE roundType);
void printPlayerPoints(int p1, int p2);
void printRoundInfo(enum ROUNDTYPE t, int dice, int points);





#endif