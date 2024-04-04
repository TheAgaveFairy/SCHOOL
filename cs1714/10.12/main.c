#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
  int size = 0;
  Employee *employees = readData("a6-input.txt", &size);
  Employee best = getBestEmployee(employees, size);
  writeData("a6-output.txt", best);
  free(employees);
  

  return 0;
}