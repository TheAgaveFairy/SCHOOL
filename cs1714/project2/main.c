#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route-records.h"

int main( int argc, char *argv[] )
{
/* 1. Declare variables here */
  /*I WANNA DO THIS LATER, CORRECTLY*/
  
/* 2. Check command line arguments here. If a command line argument (for the
file name) is missing, print out the following: ERROR: Missing file name and end
the program */
  if(argc != 2){
    puts("ERROR: Missing file name");
    return 1;
  }
  int len = strlen(argv[1]) +1; /* don't forget null terminator*/
  char* filename = (char*) malloc(len * sizeof(char));
  strcpy(filename, argv[1]);

  FILE *fileIn = NULL;
/* 3. Attempt to open the file. Print out Opening <filename>... before you call
fopen(). */
  printf("Opening %s...\n", filename);
  fileIn = fopen(filename, "r");
  
/* 4. Check to see if the file opens. If it does not open, print out ERROR:
Could not open file and end the program. */
  if (fileIn == NULL) {
    puts("ERROR: Could not open file");
    return 1;
  }
/* 5. Do the following to load the records into an array of RouteRecords
5.1 Call createRecords(), which will read through the file once to find
the total number of lines/records in the file. Use this count, to dynamically
allocate memory for an array of RouteRecords. It returns a pointer to that array.
Don't forget to rewind the file pointer.
5.2 Call fillRecords() to go through the CSV file again to fill in the
values. It will then return the actual number of items the array has. Recall that
not all records in the original CSV file will be entered into the array. Print the
number of unique routes operated by different airlines: Unique routes operated by
airlines: ???
5.3 Close the the file.
*/
  RouteRecord* records = createRecords(fileIn);
  int num_records = fillRecords(records, fileIn);
  printf("Unique routes operated by airlines: %d", num_records);
/* 6. Create an infinite loop that will do the following:
6.1 Call printMenu()
6.2 Ask the user to input a value for the menu
6.3 Handle the case in which a non-integer value is entered
6.4 Create a switch/case statement to handle all the menu options
6.4.1 Each option requires the user to enter a search key
6.4.2 Quit needs to free the array
*/
  int decision = 0;
  int result = -1;
  while(1){
    printMenu();
    result = scanf("%d", &decision);
    if (result != 1){
      puts("ERROR: Incorrect input");
      continue;
    }
    char key1[4];
    char key2[4];
    switch(decision){
      case 1:
          printf("Enter Origin: ");
          scanf("%s", key1);
          printf("Enter Destination: ");
          scanf("%s", key2);
          searchRecords(records, num_records, key1, key2, ROUTE);
          break;
      case 2:
          printf("Enter the Origin Airport Code: ");
          scanf("%s", key1);
          searchRecords(records, num_records, key1, key2, ORIGIN);
          break;
      case 3:
          printf("Enter the Destination Airport Code: ");
          scanf("%s", key1);
          searchRecords(records, num_records, key1, key2, DESTINATION);
          break;
      case 4:
          printf("Enter the Airline Code: ");
          scanf("%s", key1);
          searchRecords(records, num_records, key1, key2, AIRLINE);
          break;
      case 5:
          printf("Thanks for using the program!\n");
          fclose(fileIn);
          free(records);
          return 0;
      default:
          printf("ERROR: Incorrect input");
      
    }
    
  }
  
return 0;
}
