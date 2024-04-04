#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee_struct {
  int id;
  char name[10];
  double salary;
} Employee;

Employee* readData(char *fileName, int *size);
Employee getBestEmployee(Employee *arr, int size);
void writeData(char *fileName, Employee bestEmployee);
#endif