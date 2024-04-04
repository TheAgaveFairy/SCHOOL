#include <stdio.h>
#include <string.h>

int f (int n){
  static mem = 0;
  if (n > mem) mem = n;
  return mem;
}

int main(void) {
 int value = f(3) + f(2)*(f(2));
  printf("value = %d\n", value);
  
  
   return 0;
}
