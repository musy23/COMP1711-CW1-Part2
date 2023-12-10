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
        // Validate and copy the date
        if (sscanf(ptr, "%10[^,]", date) != 1) {
            *date = '\0'; // Set to empty if invalid
        }

        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            // Validate and copy the time
            if (sscanf(ptr, "%5[^,]", time) != 1) {
                *time = '\0'; // Set to empty if invalid
            }

            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int main() {
    int buffer_size = 150;
    FILE *input = NULL;

    FitnessData fitness[200];
    char line[buffer_size];
    char filename[buffer_size];

    printf("Please enter the name of the data file: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, "%s", filename);
    input = fopen(filename, "r");

    if (input == NULL) {
        printf("Error: invalid file\n");
        return 1;
    }

    int index = 0;
    while (fgets(line, buffer_size, input) != NULL && index < 200) {
        char date[11];
        char time[6];
        int steps;

        // Tokenize the record and validate
        tokeniseRecord(line, ',', date, time, &steps);

        // Validate the format of date and time
        if (*date == '\0' || *time == '\0' || steps == 0) {
            printf("Error: Invalid file\n");
            fclose(input);
            return 1;
        }

        // Copy data to the fitness array
        strcpy(fitness[index].date, date);
        strcpy(fitness[index].time, time);
        fitness[index].steps = steps;

        index++;
    }

    fclose(input);
    return 0;
}
