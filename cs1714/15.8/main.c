#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int numRecords(FILE *);

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("ERROR NO ARGS");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("ERROR FILE NOT OPEN");
    return 1;
  }

  int numStudents = 0;
  numStudents = numRecords(fp);
  /*printf("Number of records: %d\n", numStudents);*/

  Student *students = (Student*) malloc(sizeof(Student) * numStudents);
  rewind(fp);
  
  char buffer[100];
  int i = 0;
  
  int id;
  char name[10];
  
  while(fgets(buffer, sizeof(buffer), fp) != NULL){
    /*printf("%s\n", buffer);*/
    int check;
    check = sscanf(buffer, "%d,%s", &id, name);
    if (check == 2){
      students[i].id = id;
      strcpy(students[i].name, name);
    } else {
      printf("ERROR");
    }
    i = i+1;
  }

  print(students, numStudents);
  sortStudents(students, numStudents);
  print(students, numStudents);

  fseek(stdin,0,SEEK_END);
  
  int wanted = 0;
  scanf("%d", &wanted);
  
  Student s = searchStudent(students, numStudents, wanted);
  printf("(%d,%s)\n", s.id, s.name);

  free(students);
  fclose(fp);
  
  return 0;
}

int numRecords(FILE *fp){
  int count = 0;
  char buffer[100];
  while(fgets(buffer, 100, fp) != NULL){
    count++;
  }
  return count;
}