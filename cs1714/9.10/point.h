#ifndef POINT_H
#define POINT_H

typedef struct Point{
  double x, y, z;
}Point;

void midpoint(Point p1, Point p2, Point *mid);
void distance(Point p1, Point p2, double *dist);

#endif