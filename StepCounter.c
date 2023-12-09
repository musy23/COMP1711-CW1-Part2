#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int main() {

    char line[buffer_size];
    char filename[buffer_size];
    int recordcounter=0;
    
    char user_selection;
    

    printf("A: Specify filename to be imported\n");
    printf("B: Display the total number of records in the file.\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");
    
    scanf("%c", &user_selection);
    
    switch(user_selection)
    {
        case 'A': 
        printf("Please enter the name of the data file: ");
        
        fgets(line, buffer_size, stdin);
        scanf(line, "%s", filename);
        FILE *input = fopen("FitnessData_2023.csv", "r");
        
        break;

        case 'B':
        return 0;
        break;

        case 'C':
        return 0;
        break;
        
        case 'D':
        return 0;
        break;
        
        case 'E':
        return 0;
        break;
        
        case 'F':
        return 0;
        break;
        
        case 'Q': 
        return 0;
        break;

        default:
        
        printf("Invalid choice, please choose one of the displayed options.\n");
        return 0;
        break;
    
        return 0;
    }

    
    

}