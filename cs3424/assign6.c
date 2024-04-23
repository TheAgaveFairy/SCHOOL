#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assign6.h"

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

    //printf("---%s---\n",input);
    
    switch(input[0]) {
      case 'c':
      case 'C':
        create(fp);
        break;
      case 'r':
      case 'R':
        readFile(fp);
        break;
      case 'u':
      case 'U':
        update(fp);
        break;
      case 'd':
      case 'D':
        delete(fp);
        break;
      case 'q':
      case 'Q':
        printf("Quit\n");
        return 0;
      case EOF:
        printf("Quit\n");
        return 0;
      case 0:
        printf("known bug here\n");
        break;
      default:
        printf("ERROR: Invalid option\n");
    }
    printMenu();
    memset(input,0,sizeof(input));    
  }
  
  fclose(fp);
  return 0;
}

void printMenu() {
  puts("Enter one of the following actions or press CTRL-D to exit\nC - create a new item\nR - read an existing item\nU - update an existing item\nD - delete an existing item");
}

void printItem(Item *item, long index) {
  printf("\nItem name: %s\n", item->itemName);
  printf("Simple name: %s\n", item->simpleName);
  printf("Item Number: %d\n",(int)index);
  printf("Qty: %d/%d\n", item->currentQuantity, item->maxQuantity);
  printf("Description: %s\n", item->body);
}

void readFile(FILE *fp) {
  //printf("READ ITEM\n");
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  
  fp = fopen("inventory.dat", "r");
  Item *temp = malloc(sizeof(Item));
  fseek(fp, byte, SEEK_SET);
  fread(temp, sizeof(Item), 1, fp);
  if(temp->maxQuantity == 0 || !itemExists(byte,fp)){
    printf("ERROR: item not found.\n");
    return;
  }
  printItem(temp,byte/sizeof(Item));
}

void delete(FILE *fp) {
  //printf("DELETE ITEM\n");
  int byte = byteOffset();
  if(byte == -1) {
    return;
  }
  fp = fopen(inventoryFile, "r+b");

  Item *temp = malloc(sizeof(Item));
  fseek(fp, byte, SEEK_SET);
  fread(temp, sizeof(Item), 1, fp);
  if(temp->maxQuantity == 0 || !itemExists(byte,fp)){
    printf("ERROR: item not found.\n");
    return;
  }
  char *tempSimpleName = strncpy(malloc(sizeof(temp->simpleName)), temp->simpleName, sizeof(temp->simpleName));
  
  int itemSize = sizeof(Item);
  for(int i = 0; i < itemSize; i++) {
    fseek(fp, byte + i, SEEK_SET);
    fputc(0, fp);
  }
  fflush(fp);
  printf("%s was successfully deleted.\n",tempSimpleName);
}

void update(FILE *fp) {
  //printf("UPDATE ITEM\n");
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  fp = fopen(inventoryFile, "r+b");

  Item *temp = malloc(sizeof(Item));
  fseek(fp, byte, SEEK_SET);
  fread(temp, sizeof(Item), 1, fp);
  if(temp->maxQuantity == 0 || !itemExists(byte,fp)){
    //myFlusher();
    printf("ERROR: item not found\n");
    return;
  }
  //memset(temp, 0, sizeof(Item));

  char buffer[128];

  printf("Enter simple name: ");
  myReader(buffer);
  strncpy(temp->simpleName, (strlen(buffer) == 0 ? temp->simpleName : buffer), sizeof(temp->simpleName));
  

  printf("Enter item name: ");
  myReader(buffer);
  strncpy(temp->itemName, (strlen(buffer) == 0 ? temp->itemName : buffer), sizeof(temp->itemName));

  printf("Enter current quantity: ");
  myReader(buffer);
  temp->currentQuantity = ((buffer[0]=='0') || strlen(buffer)==0) ? temp->currentQuantity : atoi(buffer);

  printf("Enter max quantity: ");
  myReader(buffer);
  temp->maxQuantity = ((buffer[0]=='0') || strlen(buffer)==0) ? temp->maxQuantity : atoi(buffer);

  printf("Enter description: ");
  myReader(buffer);
  strncpy(temp->body, (strlen(buffer) == 0 ? temp->body : buffer), sizeof(temp->body));

  fseek(fp, byte, SEEK_SET);
  fwrite(temp, sizeof(Item), 1, fp);
  fflush(fp);
}

void create(FILE *fp) {
  //printf("CREATE ITEM\n");
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  
  fp = fopen(inventoryFile, "r+b");
  if (itemExists(byte, fp)){
    
    printf("ERROR: Item already exists.\n");
    //myFlusher();
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

  
  fseek(fp, byte, SEEK_SET);
  fwrite(temp, sizeof(Item), 1, fp);
  fflush(fp);
}

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

  printf("Enter item number (1 to 9999): ");
  fgets(num, sizeof(num), stdin);
  num[strcspn(num, "\n")] = '\0';
  retNum = strtol(num, &numPtr, 10);
  
  if(retNum < 1 || retNum > 9999) {
    printf("Invalid item number\n");
    return -1;
  }
  return sizeof(Item) * retNum;
}