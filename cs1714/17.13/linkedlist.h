#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LLNode_struct{
  int id;
  char name[10];
  double gpa;
  struct LLNode_struct *next;
} LLNode;

LLNode * createNode(int id, char name[], double gpa);
LLNode * insertNode(LLNode *head, LLNode *newNode);
double averageGPA(LLNode *head);
void printLL(LLNode *head);
LLNode * destroyLL(LLNode *head);


#endif