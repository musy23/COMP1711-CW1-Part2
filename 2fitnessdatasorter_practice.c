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

// Function to check if the line has a valid format
int is_valid_format(const char *line) {
    char date[11], time[6];
    int steps;
    return sscanf(line, "%10[^,],%5[^,],%d", date, time, &steps) == 3;
}

// Function to read and sort fitness data
void read_and_sort_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read records into an array
    char line[100];  // Adjust the buffer size as needed
    int record_count = 0;
    FitnessData *records = NULL;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (is_valid_format(line)) {
            records = realloc(records, (record_count + 1) * sizeof(FitnessData));
            tokeniseRecord(line, ',', records[record_count].date, records[record_count].time, &records[record_count].steps);
            record_count++;
        } else {
            printf("Error: Invalid file format.\n");
            fclose(file);
            exit(1);
        }
    }

    fclose(file);

    // Sort records by step count in descending order
    for (int i = 0; i < record_count - 1; i++) {
        for (int j = i + 1; j < record_count; j++) {
            if (records[i].steps < records[j].steps) {
                // Swap records
                FitnessData temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    // Write sorted data to a new .tsv file
    char output_filename[100];  // Adjust the buffer size as needed
    snprintf(output_filename, sizeof(output_filename), "%s.tsv", filename);

    FILE *tsvfile = fopen(output_filename, "w");
    if (tsvfile == NULL) {
        printf("Error: Unable to create output file.\n");
        exit(1);
    }

    for (int i = 0; i < record_count; i++) {
        fprintf(tsvfile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose(tsvfile);

    free(records);

    printf("Data sorted and written to %s\n", output_filename);
}

int main() {
    char filename[100];  // Adjust the buffer size as needed
    printf("Enter Filename: ");
    scanf("%s", filename);

    read_and_sort_data(filename);

    return 0;
}
