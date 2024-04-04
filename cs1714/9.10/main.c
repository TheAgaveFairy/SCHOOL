#include "point.h"
#include <stdio.h>
#define doSomething(x,y) x + y * 2

int main(/*int argc, char *argv[]*/){
  int result = 2 * doSomething(5,7);
  printf("%d\n", result);
  
  Point p1, p2, mid;
  double dist;
  scanf("%lf %lf %lf", &p1.x, &p1.y, &p1.z);
  scanf("%lf %lf %lf", &p2.x, &p2.y, &p2.z);
  midpoint(p1, p2, &mid);
  distance(p1, p2, &dist);
  printf("midpoint: %.2lf, %.2lf, %.2lf\n", mid.x, mid.y, mid.z);
  printf("distance: %.2lf\n", dist);
  return 0;
}