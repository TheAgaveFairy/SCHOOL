#include <stdio.h>

int main(){
  float testVal = 25.2358;
  printf("testing whitespace padding\nnum for testing: %lf\n",testVal);
  printf("5-%5lf\n", testVal);
  printf("2-%2lf\n", testVal);
  printf("10-%10lf\n", testVal);
  printf("2.3-%2.3lf\n", testVal);
  printf("10.2-%10.2lf\n", testVal);


  volatile int x, y = 69;
  printf("x = %d\n", x);
  printf("y = %d\n", y);

  printf("%p\n", &x);
  printf("%p\n", &y);

  int z = 1;
  switch(z){
    case 0:
      printf("0\n");
      break;
    case 1: 
      printf("1\n");
    case 2:
      printf("2\n");
      break;
    case 3:
    case 4:
      printf("3 or 4\n");
      break;
    default:
      printf("default\n");
  }

  if(z=-1){
    printf("if reached\n");
  }else{
    printf("else reached");
  }
  /*
  char a;
   char b;
   char c;

   scanf(" %c ", &a);
   scanf(" %c ", &b);
   scanf(" %c ", &c);

   
   printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n",a,b,c,a,c,b,b,a,c,b,c,a,c,a,b,c,b,a);
  */

  return 0;
}
