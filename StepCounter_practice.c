#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here

// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


// Complete the main function
int main() 
{

    FITNESS_DATA fitness[100];
    char line[buffer_size];
    char filename[buffer_size];
    
    int recordcounter = 0;
    
    char user_selection;
    FILE *input = NULL;
    
    int numberofrecords = 0;
    float mean = 0;

    char date[11];
    char time[7];
    char steps[4];

    while (true)
    {
        printf("A: Specify filename to be imported\n");
        printf("B: Display the total number of records in the file.\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        
        user_selection = getchar();

        switch (user_selection)
        {
            case 'A': 
            printf("Please enter the name of the data file: ");
            fgets(line, buffer_size, stdin);
            scanf(line, "%s", filename);
            input = fopen("FitnessData_2023.csv", "r");
            if (input == NULL){
                printf("Error: Could not open file.\n");
                return 1;
            }

            tokeniseRecord(line,",",date, time, steps);
                strcpy(fitness[recordcounter].date, date);
                strcpy(fitness[recordcounter].time, time);
                fitness[recordcounter].steps = atoi(steps);
            return 1;
            break;

            case 'B':
            recordcounter = 0;
            if (input != NULL){
                while (fgets(line, sizeof(line), input) != NULL){
                recordcounter++;
                }
                printf("Total records: %d\n", recordcounter);

            }
            break;

            case 'C':
            
            for(int i = 0; i < numberofrecords, i++;)
        
            break;

            case 'D':
            break;

            case 'E':
            for(int i = 0; i < numberofrecords, i++;){
                mean += fitness[i].steps;
            }
            mean/= numberofrecords;
            printf("The mean step count of all the records in the file is %.2f\n", mean);
            break;

            case 'F':
            break;

            case 'Q':
            fclose(input);
            exit(0);

            default:
            printf("Invalid choice, please choose one of the displayed options.\n");
            break;
        }
        
    }

    return 0;

}