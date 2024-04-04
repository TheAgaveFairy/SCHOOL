#include "route-records.h"
#include <stdlib.h>
#include <string.h>

RouteRecord* createRecords(FILE* fileIn) {
  
  /*count number of records in data*/
  char line[100];
  int num_records = -1; /* starting at -1 handles 1 header line */
  while (fgets(line, sizeof(line), fileIn) != NULL) {
    num_records += 1;
  }
  rewind(fileIn);

  /*Initialize Integer data to zeroes*/
  RouteRecord *records = (RouteRecord*) malloc(num_records * sizeof(RouteRecord));
  int i = 0;
  int j = 0;
  for (i = 0; i < num_records; i++){
    for (j = 0; j < 6; j++){
      records[i].passengers[j] = 0;
    }
  }
  return records;
}

int fillRecords(RouteRecord* r, FILE* fileIn) {

    char line[100];
    int record_num = -1;

    while (fgets(line, sizeof(line), fileIn) != NULL) {
      if (record_num == -1) {
        record_num += 1;
        continue;
      }
      int month;
      char origin[4];
      char destination[4];
      char airline[3];
      char category[20]; /*UNUSED*/
      int passengers;
      
      int s = sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%d", &month, origin, destination, airline, category, &passengers);
      if (s != 6) {break;}

      int index = findAirlineRoute(r, record_num, origin, destination, airline, 0);
      if (index != -1){
        r[index].passengers[month-1] = passengers;
        continue;
      }

      
      
      strcpy(r[record_num].origin, origin);
      strcpy(r[record_num].destination, destination);
      strcpy(r[record_num].airline, airline);
      r[record_num].passengers[month-1] = passengers;

      record_num += 1;
    }
    return record_num;
}

int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx) {
    
    if (curIdx == length){
      return -1;
    }
    if (strcmp(r[curIdx].origin, origin) == 0 && strcmp(r[curIdx].destination, destination) == 0 && strcmp(r[curIdx].airline, airline) == 0){
      return curIdx;
    } else {
      return findAirlineRoute(r, length, origin, destination, airline, curIdx+1);
    }  
}

void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st) {
    int i = 0;
    int month;
    int sum_passengers[6] = {0,0,0,0,0,0};
    int total_passengers = 0;
    int matches = 0;
  
    if (st == ORIGIN) {
      for (i = 0; i < length; i++){
           if (strcmp(r[i].origin, key1) == 0 ){
             matches += 1;
             printf("Match! Airline: %s Route: (%s-%s)\n", r[i].airline, r[i].origin, r[i].destination);
             for (month = 0; month < 6; month++){
               sum_passengers[month] += r[i].passengers[month];
               total_passengers += r[i].passengers[month];
             }
             
           }
      }
      if (matches == 0){
        puts("No match found!");
        return;
      }
      printf("Total passengers for %s: %d\n", key1, total_passengers);
      for (month = 0; month < 6; month++){
        printf("%d in Month %d\n", sum_passengers[month], month+1);
      }
      printf("Average per month: %lf", (double)total_passengers/6.0);
      
    } else if (st == DESTINATION) {
      for (i = 0; i < length; i++){
         if (strcmp(r[i].destination, key1) == 0 ){
           matches += 1;
           printf("Match! Airline: %s Route: (%s-%s)\n", r[i].airline, r[i].origin, r[i].destination);
           for (month = 0; month < 6; month++){
             sum_passengers[month] += r[i].passengers[month];
             total_passengers += r[i].passengers[month];
           }

         }
      }
      if (matches == 0){
        puts("No match found!");
        return;
      }
      printf("Total passengers for %s: %d\n", key1, total_passengers);
      for (month = 0; month < 6; month++){
      printf("%d in Month %d\n", sum_passengers[month], month+1);
      }
      printf("Average per month: %lf", (double)total_passengers/6.0);
      
    } else if (st == AIRLINE) {
      for (i = 0; i < length; i++){
         if (strcmp(r[i].airline, key1) == 0 ){
           matches += 1;
           printf("Match! Airline: %s Route: (%s-%s)\n", r[i].airline, r[i].origin, r[i].destination);
           for (month = 0; month < 6; month++){
             sum_passengers[month] += r[i].passengers[month];
             total_passengers += r[i].passengers[month];
           }

         }
      }
      if (matches == 0){
        puts("No match found!");
        return;
      }
      printf("Total passengers for %s: %d\n", key1, total_passengers);
      for (month = 0; month < 6; month++){
      printf("%d in Month %d\n", sum_passengers[month], month+1);
      }
      printf("Average per month: %lf", (double)total_passengers/6.0);
      
    } else if (st == ROUTE) {
      for (i = 0; i < length; i++) {
          if (strcmp(r[i].origin, key1) == 0 && strcmp(r[i].destination, key2) == 0){
            matches += 1;
      printf("Match! Airline: %s Route: (%s-%s)\n", r[i].airline, r[i].origin, r[i].destination);
           for (month = 0; month < 6; month++){
             sum_passengers[month] += r[i].passengers[month];
             total_passengers += r[i].passengers[month];
           }

         }
      }
      if (matches == 0){
        puts("No match found!");
        return;
      }
      printf("Total passengers for %s: %d\n", key1, total_passengers);
      for (month = 0; month < 6; month++){
      printf("%d in Month %d\n", sum_passengers[month], month+1);
      }
      printf("Average per month: %lf", (double)total_passengers/6.0);
    } else {
      puts("Some kind of error here!");
    }

  
}

void printMenu() {
    puts("\n\n######### Airline Route Records Database MENU #########");
    puts("1. Search by Route");
    puts("2. Search by Origin Airport");
    puts("3. Search by Destination Airport");
    puts("4. Search by Airline");
    puts("5. Quit");
    printf("Enter your selection: ");
}

/* Month	origin	destin	carrier	[type]	Total */