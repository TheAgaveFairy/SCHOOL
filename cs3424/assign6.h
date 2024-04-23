#ifndef ASSIGN6_H
#define ASSIGN6_H

#define myReader(buffer)  memset(buffer,0,sizeof(buffer));\
                          fgets(buffer,sizeof(buffer),stdin);\
                          buffer[strcspn(buffer, "\n")] = '\0'

#define myFlusher();    int c = 0;\
                      while ((c = getchar()) != '\n' && c != EOF) { }


typedef struct Item_struct {
  char itemName[64];
  char simpleName[16];
  int currentQuantity;
  int maxQuantity;
  char body[128];
} Item;

void printMenu();
Item * createItem();
void printItem(Item *,long);
void readFile(FILE *);
void delete(FILE *);
void update(FILE *);
void create(FILE *);
void getString(const char *, char [], int);
long byteOffset();
int itemExists(long, FILE *);

#endif