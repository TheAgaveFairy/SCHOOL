#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assign6.h"

/*#define itemSize sizeof(Item)*/

typedef struct Item_struct {
  char itemName[64];
  char simpleName[16];
  int currentQuantity;
  int maxQuantity;
  char body[128];
} Item;

void printMenu();
Item * createItem();
void printItem(Item *);
void readFile(FILE *);
void delete(FILE *);
void update(FILE *);
void create(FILE *);
void getString(const char *, char [], int);
long byteOffset();
int itemExists(long, FILE *);

char *inventoryFile = "inventory.dat";

int main(int argc, char *argv[]) {
  char input[7];
  memset(input,0,sizeof(input));
  printMenu();

  FILE *fp;
  if(!(fp = fopen(inventoryFile, "r"))){
    fp = fopen(inventoryFile, "w");
    if(!fp){
      printf("Error creating file\n");
      return 1;
    }
  }
  while(fgets(input,sizeof(input),stdin) != NULL){
    input[strcspn(input, "\n")] = '\0';
    
    switch(input[0]) {
      case 'c':
      case 'C':
        printf("Create new item\n");
        create(fp);
        break;
      case 'r':
      case 'R':
        printf("Read item\n");
        readFile(fp);
        break;
      case 'u':
      case 'U':
        printf("Update item\n");
        update(fp);
        break;
      case 'd':
      case 'D':
        printf("Delete item\n");
        delete(fp);
        break;
      case 'q':
      case 'Q':
        printf("Quit\n");
        return 0;
      case EOF:
        printf("Quit\n");
        return 0;
      default:
        printf("Invalid selection\n");

    }
    printMenu();
  }
  
  fclose(fp);
  return 0;
}

void printMenu() {
  puts("Enter one of the following actions or press CTRL-D to exit.\nC - create a new item\nR - read an existing item\nU - update an existing item\nD - delete an existing item");
}

void printItem(Item *item) {
  printf("\nPRINTING ITEM\n");
  printf("Simple name: %s\n", item->simpleName);
  printf("Item name: %s\n", item->itemName);
  printf("Current/Max quantity: %d/%d\n", item->currentQuantity, item->maxQuantity);
  printf("Body: %s\n", item->body);
}

void readFile(FILE *fp) {
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  
  fp = fopen("inventory.dat", "r");
  Item *temp = malloc(sizeof(Item));
  fseek(fp, byte, SEEK_SET);
  fread(temp, sizeof(Item), 1, fp);
  if(temp->maxQuantity == 0 || !itemExists(byte,fp)){
    printf("Item not valid / found.\n");
    return;
  }
  printItem(temp);
}

void delete(FILE *fp) {
  int byte = byteOffset();
  if(byte == -1) {
    return;
  }
  fp = fopen(inventoryFile, "r+b");

  if(!itemExists(byte, fp)){
      printf("Item not found!\n");
    return;
  }
  int itemSize = sizeof(Item);
  for(int i = 0; i < itemSize; i++) {
    fseek(fp, byte + i, SEEK_SET);
    fputc(0, fp);
  }
  fflush(fp);
}

void update(FILE *fp) {
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  fp = fopen(inventoryFile, "r+b");

  //prompt
  //strcpy(temp.itemName, strlen(buffer)  == 0 ? data.itemName : buffer);


  //fseek
  //fwrite
  //fflush
}

void create(FILE *fp) {
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  
  fp = fopen(inventoryFile, "r+b");
  if (itemExists(byte, fp)){
    printf("Item already exists.\n");
    return;
  }
  
  Item *temp = malloc(sizeof(Item));
  memset(temp, 0, sizeof(Item));

  char buffer[128];

  printf("Enter simple name: ");
  myReader(buffer);
  strncpy(temp->simpleName, buffer, sizeof(temp->simpleName));

  printf("Enter item name: ");
  myReader(buffer);
  strncpy(temp->itemName, buffer, sizeof(temp->itemName));
  
  printf("Enter current quantity: ");
  myReader(buffer);
  temp->currentQuantity = ((buffer[0]=='0')) ? 0 : atoi(buffer);
  
  printf("Enter max quantity: ");
  myReader(buffer);
  temp->maxQuantity = ((buffer[0]=='0'))  ? 0 : atoi(buffer);

  printf("Enter description: ");
  myReader(buffer);
  strncpy(temp->body, buffer, sizeof(temp->body));

  printItem(temp);
  
  fseek(fp, byte, SEEK_SET);
  fwrite(temp, sizeof(Item), 1, fp);
  fflush(fp);
  printf("\n");
}

/*void getString(const char *message, char variable[], int something) {
  char buffer[128];
  memset(buffer, 0, sizeof(buffer));
}*/

int itemExists(long byte, FILE *fp) {
  Item validate;
  fseek(fp, byte, SEEK_SET);

  if(fread(&validate, sizeof(Item), 1, fp) != 1 || validate.maxQuantity == 0){
    return 0;
  }  

  return 1;
}

long byteOffset() {
  char num[5];
  memset(num,0,sizeof(num));
  char *numPtr;
  int retNum;

  printf("Enter item number: ");
  fgets(num, sizeof(num), stdin);
  num[strcspn(num, "\n")] = '\0';
  retNum = strtol(num, &numPtr, 10);
  
  if(retNum < 1 || retNum > 9999) {
    printf("Invalid item number\n");
    return -1;
  }
  return sizeof(Item) * retNum;
}