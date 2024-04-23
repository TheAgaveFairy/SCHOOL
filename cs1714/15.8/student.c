#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void sortStudents(Student *students, int numStudents){
  int i, j;
  Student temp;
  for (i = 0; i < numStudents - 1; i++) {
    for (j = 0; j < numStudents - i - 1; j++) {
      if (students[j].id > students[j + 1].id) {
        temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

void print(Student *students, int numStudents){
  int i;
  for(i = 0; i < numStudents; i++){
    printf("(%d, %s) -> ", students[i].id, students[i].name);
  }
  puts("");
}


Student searchStudent(Student *students, int numStudents, int id){
  int i;
  for(i = 0; i < numStudents; i++){
    if(students[i].id == id){
      return students[i];
    }
  }
  return students[0];
}
