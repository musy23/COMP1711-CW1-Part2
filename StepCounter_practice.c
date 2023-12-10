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

    FITNESS_DATA fitness[200];
    char line[buffer_size];
    char filename[buffer_size];
    
    int recordcounter = 0;
    
    char user_selection;
    FILE *input = NULL;
    
    int mean = 0;
    int lowestvalue = 0;
    int currentvalue = 0;
    int highestvalue = 0;

    char date[11];
    char time[7];
    char steps[4];
    

    
    while (true)
    {
        printf("A: Specify filename to be imported\n");
        printf("B: Display the total number of records in the file.\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the most steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        
        user_selection = getchar();
        while (getchar() != '\n');

        switch (user_selection)
        {
            case 'A':
            case 'a':
            printf("Please enter the name of the data file: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, "%s", filename);
            input = fopen(filename, "r");
             printf("File successfully loaded.\n");
            while (fgets(line, buffer_size, input) != NULL){
                tokeniseRecord(line,",",date, time, steps);
                printf("Debug: Date: %s, Time: %s, Steps: %s\n", date, time, steps);
                
                strcpy(fitness[recordcounter].date, date);
                strcpy(fitness[recordcounter].time, time);
                fitness[recordcounter].steps = atoi(steps);
                recordcounter++;

            if (input == NULL){
                printf("Error, could not open file.\n");
                return 1;
            }
            }
        
            break;

            case 'B':
            case 'b':
            recordcounter = 0;
            input = fopen(filename, "r");
            while (fgets(line, sizeof(line), input) != NULL){
                    recordcounter++;
                }
                printf("Total records: %d\n", recordcounter);
            break;

            case 'C':
            case 'c':
            lowestvalue = fitness[0].steps;
            for (int i = 1; i< recordcounter; i++){
                if (fitness[i].steps < lowestvalue){
                    lowestvalue = fitness[i].steps;
                    currentvalue = i;
                }
            }
            printf("Fewest steps: %s %s\n",fitness[currentvalue].date, fitness[currentvalue].time);
            break;

            case 'D':
            case 'd':
            highestvalue = fitness[0].steps;
            for (int i = 1; i < recordcounter; i++) {
                if (fitness[i].steps > highestvalue) {
                    highestvalue = fitness[i].steps;
                    currentvalue = i;
                }
            }
            printf("Most steps: %s %s\n", fitness[currentvalue].date, fitness[currentvalue].time);
            break;

            case 'E':
            case 'e':
            for(int i = 0; i < recordcounter; i++){
                mean += fitness[i].steps;
            }
            mean /= recordcounter;
            
            
            printf("Mean step count: %d.\n", mean);
            break;

            case 'F':
            case 'f':

            break;

            case 'Q':
            case 'q':
            fclose(input);
            exit(0);

            default:
            printf("Invalid choice, please choose one of the displayed options.\n");
            break;
        }
        
    }

    return 0;

}