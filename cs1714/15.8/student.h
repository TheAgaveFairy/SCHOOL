#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int id;
    char name[10];
} Student;

void sortStudents(Student *students, int numStudents);
void print(Student *students, int numStudents);
Student searchStudent(Student *students, int numStudents, int id);

#endif