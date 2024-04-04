#include "point.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void midpoint(Point p1, Point p2, Point *mid){
  mid->x = (p1.x + p2.x) / 2;
  mid->y = (p1.y + p2.y) / 2;
  mid->z = (p1.z + p2.z) / 2;  
}



void distance(Point p1, Point p2, double *dist){
  *dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}
