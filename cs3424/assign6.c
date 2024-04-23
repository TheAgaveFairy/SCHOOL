#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int itemNum;
  char itemName[64];
  char simpleName[16];
  int currentQuantity;
  int maxQuantity;
  char body[128];
} Item;

void printMenu();
Item * createItem();
void printItem(Item * item);

char *inventoryFile = "inventory.dat";

int main(void) {
  char input[7];
  memset(input,0,sizeof(input));
  printMenu();

  FILE *fp;
  if(!(fp = fopen(inventoryFile, "r"))){
    ip = fopen(inventoryFile, "w");
    if(!fp){
      printf("Error creating file\n");
      return 1;
    }
  }
  
  while(fgets(input,strlen(input),stdin) != NULL){
    
    switch(input[0]) {
      case 'c':
      case 'C':
        printf("Create new item\n");
        Item *item = createItem();
        printItem(item);
        break;
      case 'r':
      case 'R':
        printf("Read item\n");
        read(fp);
        break;
      case 'u':
      case 'U'
        printf("Update item\n");
        break;
      case 'd':
      case 'D':
        printf("Delete item\n");
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

  
  close(fp);
  return 0;
}

void printMenu() {
  puts("Enter one of the following actions or press CTRL-D to exit.\nC - create a new item\nR - read an existing item\nU - update an existing item\nD - delete an existing item");
}

void printItem(Item *item) {
  printf("\nPRINTING ITEM\n");
  printf("Item Number: %d\n", item->itemNum);
  printf("Simple name: %s\n", item->simpleName);
  printf("Item name: %s\n", item->itemName);
  printf("Current/Max quantity: %d/%d\n", item->currentQuantity, item->maxQuantity);
  printf("Body: %s\n", item->body);
}

void read(FILE *fp) {
  int byte = byteOffset();
  if (byte == -1) {
    return;
  }
  
  fp = fopen("inventory.dat", "r");
  Item temp;
  fseek(fp, byte, SEEK_SET);
  fread(&temp, size(Item), 1, fp);
  if(temp.maxQuantity == 0){
    printf("Item not valid / found.\n");
    return;
  }
  printItem(&temp);
}

void delete(File *fp) {
  int byte = byteOffset();
  if(byte == -1) {
    return;
  }
  fp = fopen(inventoryFile, "r+b");

  itemExists(byte, fp);
  for(int i = 0; i < size(Item); i++)) {
    //fseek(fp, byte + i, SEEK_SET);
    //fwrite(&temp, size(Item), 1, fp);
  }
}

void update(File *fp) {
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
  }
  Item temp;
  //enter things with getstring
  fseek(fp, byte, SEEK_SET);
  fwrite(temp, size(Item), 1, fp);
  fflush(fp);
}

void getString(const char *message, char variable[], int something) {
  char buffer[128];
  memset(buffer, 0, sizeof(buffer));
}

int itemExists(int byte, File *fp) {
  Item validate;
  fseek(fp, byte, SEEK_SET);

  if(fread(&validate, size(Item), 1, fp) != 1 || validate.maxQuantity == 0){
    return 0;
  }  

  
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
  if(retNum < 1 || retNum > 9999)) {
    printf("Invalid item number\n");
    return -1;
  }
  return size(Item) * retNum;
}

Item * createItem() {
  /*
  printf("CREATING ITEM\n");
  //char buffer[128];
  //memset(buffer, 0, sizeof(buffer));
  Item *item = malloc(sizeof(Item));
  //fflush(stdin);
  
  //TODO: THIS SHOULDNT BE A STRUCT FEATURE
  //printf("Enter item number:");
  //fgets(buffer, 100 , stdin);
  int temp;
  //sscanf(buffer, "%d", &temp);
  scanf("%d", &temp);
  item->itemNum = temp;
  //printf("%d",temp);

  //printf("Enter simple name:");
  //fgets(buffer, 16, stdin);
  //strncpy(item->simpleName, buffer, 16);
  //sscanf(buffer, "%s", item->simpleName);
  //scanf("%s", item->simpleName);
  fgets(item->simpleName, strlen(item->simpleName), stdin);
  item->simpleName[strlen(item->simpleName) - 1] = '\0';
  
  
  //printf("Enter item name:");
  //fgets(buffer, 64, stdin);
  //sscanf(buffer, "%s", item->itemName);
  //scanf("%s", item->itemName);
  fgets(item->itemName, strlen(item->itemName), stdin);
  item->itemName[strlen(item->itemName) - 1] = '\0';
  
  //printf("Enter current quantity:");
  //fgets(buffer, 10 , stdin);
  //sscanf(buffer, "%d", &item->currentQuantity);
  scanf("%d", &item->currentQuantity);
  
  //printf("Enter max quantity:");
  //fgets(buffer, 10 , stdin);
  //sscanf(buffer, "%d", &item->maxQuantity);
  scanf("%d", &item->maxQuantity);
  
  //printf("Enter body:");
  //fgets(buffer, 128 , stdin);
  //sscanf(buffer, "%s", item->body);
  //scanf("%s", item->body);
  fgets(item->body, strlen(item->body), stdin);
  
  return item;
  */
  printf("CREATING ITEM\n");
  Item *item = malloc(sizeof(Item));

  // Read item number
  printf("Enter item number: ");
  scanf("%d", &item->itemNum);

  // Read item name (using fgets for safety)
  printf("Enter item name: ");
  fgets(item->itemName, sizeof(item->itemName), stdin);
  // Remove trailing newline if present
  item->itemName[strcspn(item->itemName, "\n")] = '\0';

  // Read simple name (using scanset specifier)
  printf("Enter simple name: ");
  scanf("%15[^ \n]%*c", item->simpleName); // Read max 15 chars excluding space/newline, discard newline

  // Read quantities
  printf("Enter current quantity: ");
  scanf("%d", &item->currentQuantity);
  printf("Enter max quantity: ");
  scanf("%d", &item->maxQuantity);

  // Read body (using fgets for safety)
  printf("Enter item body:\n"); // Separate prompt for multi-line input
  fgets(item->body, sizeof(item->body), stdin);
  // Remove trailing newline if present
  item->body[strcspn(item->body, "\n")] = '\0';

  return item;
}

/*Item createItem2() {
  printf("CREATING ITEM 2\n");
  Item item;
  printf("Enter item number: ");
  scanf("%d", &item.itemNum);
  printf("Enter simple name: ");
  scanf("%s", item.simpleName);
  printf("Enter item name: ");
  scanf("%s", item.itemName);
  printf("Enter current quantity: ");
  scanf("%d", &item.currentQuantity);
  printf("Enter max quantity: ");
  scanf("%d", &item.maxQuantity);
  printf("Enter body: ");
  scanf("%s", item.body);
  return item;
}*/