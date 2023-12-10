#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {

    int validate = 0

    int buffer_size = 150;
    FILE *input = NULL;

    FitnessData fitness[200];
    char line[buffer_size];
    char filename[buffer_size];

    printf("Please enter the name of the data file: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, "%s", filename);
    input = fopen(filename, "r");

    if (input == NULL){
        printf("Error: invalid file\n");
        return 1;
    }

    while(fgets(line, buffer_size, input) != NULL && index < 200){
        
    }


    strcpy(fitness[validate].date, date);
    strcpy(fitness[validate].time, time);
    fitness[validate].steps, steps;
    validate++;




    fclose(input);
    return 0;
}