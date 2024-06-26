#include <stdio.h>
#include <string.h>

void FindNumber(int number, int lowVal, int highVal) {
   int midVal;

   midVal = (highVal + lowVal) / 2;
   printf("%d %d", number, midVal);

   if (number == midVal) {
      printf(" k\n");
   }
   else {
      if (number < midVal) {
         printf(" l\n");
         FindNumber(number, lowVal, midVal);
      }
      else {
         printf(" m\n");
         FindNumber(number, midVal + 1, highVal);
      }
   }
}

int main() {
   int number;

   scanf("%d", &number);
   FindNumber(number, 0, 8);

   return 0;
}