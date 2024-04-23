#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("ERROR NO ARGS\n");
    return 1;
  }
  FILE *file = fopen(argv[1], "r");
  if (!file) {
      fprintf(stdout, "ERROR FILE NOT OPEN\n");
      return 1;
  }
  
  char buffer[128];
  memset(buffer, 0, sizeof(buffer));
  
  LLNode *head = NULL;
  int id;
  char name[50];
  double gpa;
  
  while (fgets(buffer, sizeof(buffer), file)) {
      if (sscanf(buffer, "%d,%49[^,],%lf", &id, name, &gpa) == 3) {
          LLNode *newNode = createNode(id, name, gpa);
          head = insertNode(head, newNode);
      }
  }
  fclose(file);
  printf("Average = %.2lf\n",averageGPA(head));
  printLL(head);
  destroyLL(head);
  return 0;
}