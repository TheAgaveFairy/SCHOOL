#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee* readData(char *fileName, int *size){
  Employee *employees = NULL;
  FILE *fp = fopen(fileName, "r");
  /*int numLines = 0;*/
  if (fp == NULL){
    printf("Error opening file %s\n", fileName);
  }else{
    int ch=0;
    while(!feof(fp))
    {
      ch = fgetc(fp);
      if(ch == '\n' || ch == EOF)
      {  
        (*size)++;
      }
    }
    rewind(fp);
    int i;
    employees = (Employee*) malloc(sizeof(Employee) * (*size));

    char tempLine[100];
    for (i = 0; i < *size; i++){
      fgets(tempLine, sizeof(tempLine), fp);
      sscanf(tempLine, "%s %d %lf", employees[i].name, &employees[i].id, &employees[i].salary);
    }
  }
  return employees;
}

Employee getBestEmployee(Employee *arr, int size){
  Employee bestEmployee = arr[0];
  double max = 0.0;
  int i = 0;
  for (i = 0; i < size; i++){
    if (arr[i].salary > max){
      max = arr[i].salary;
      bestEmployee = arr[i];
    }
  }
  return bestEmployee;
  
}


void writeData(char *fileName, Employee bestEmployee){
  FILE *fileOut = NULL;
  fileOut = fopen(fileName, "w");
  if (fileOut == NULL){
    printf("Error opening file %s\n", fileName);
    return;
  }else{
    fprintf(fileOut, "%s %d %.0lf", bestEmployee.name, bestEmployee.id, bestEmployee.salary);
  }
  fclose(fileOut);
}