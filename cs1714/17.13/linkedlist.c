#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

LLNode * createNode(int id, char name[], double gpa){
  LLNode *newNode = (LLNode *) malloc(sizeof(LLNode));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->gpa = gpa;
  newNode->next = NULL;
  return newNode;  
}
LLNode * insertNode(LLNode *head, LLNode *newNode){
  if (newNode == NULL) return head;

  /* If the list is empty, or the new node should be inserted before the head */
  if (head == NULL || strcmp(newNode->name, head->name) < 0) {
      newNode->next = head;
      return newNode;
  }

  LLNode *current = head;
  while (current->next != NULL && strcmp(current->next->name, newNode->name) < 0) {
      current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;

  return head;
  
}
double averageGPA(LLNode *head){
  double total = 0;
  double count = 1.0;
  while(head != NULL){
    total += head->gpa;
    if(head->next == NULL){
      break;
    }
    head = head->next;
    count += 1.0;
  }
  return total/count;
}
void printLL(LLNode *head){
  while(head != NULL){
    printf("(%d,%s,%.2lf) -> ",head->id,head->name,head->gpa);
    head = head->next;
  }
}
LLNode * destroyLL(LLNode *head){
  LLNode *temp = head;
  while(head->next != NULL){
    head = head->next;
    free(temp);
    temp = head;
  }
  return NULL;
}