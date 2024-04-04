#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

void read_csv(Flight * flights, FILE *fp, int *num_flights) {
  char line[100];

  while (fgets(line, sizeof(line), fp) != NULL) {
    /*printf("%s", line);*/
    char origin[4];
    char destination[4];
    char airline[3];
    int passengers;
    int s = sscanf(line, "%[^,],%[^,],%[^,],%d", origin, destination, airline, &passengers);
    if (s != 4) {break;}

    strcpy(flights[*num_flights].origin, origin);
    strcpy(flights[*num_flights].destination, destination);
    strcpy(flights[*num_flights].airline, airline);
    flights[*num_flights].passengers = passengers;

    *num_flights += 1;
  }
}

int main(int argc, char* argv[]) {

  if(argc != 2) {
    printf("ERROR NO ARGS");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf( "ERROR FILE NOT OPEN");
    return 1;
  }

  Flight* flights = (Flight*) malloc(NUM_FLIGHTS * sizeof(Flight));
  int num_flights = 0;
  read_csv(flights, fp, &num_flights);

  char airCode[3];
  printf("Please enter a two letter airline code: ");
  scanf("%s", airCode);

  int i = 0;
  int total_passengers = 0;
  int total_flights = 0;
  for (i = 0; i < num_flights; i++) {
    if (strcmp(flights[i].airline, airCode) == 0) {
      total_passengers += flights[i].passengers;
      total_flights += 1;
    }
  }

  printf("airline: %s\nflights: %d\npassengers: %d", airCode, total_flights, total_passengers);

  fclose(fp);
  free(flights);
  return 0;
}