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
    
    float mean = 0;
    float roundfloat(float num)
    {
    // Add 0.5 and cast to int to round
    return (float)((num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5));
    }
    
    int lowestvalue = 0;
    int currentvalue = 0;
    int highestvalue = 0;
    
    int currentstart = 0;
    int currentlength = 0;
    int longeststart = 0;
    int longestlength = 0;


    char date[11];
    char time[6];
    char steps[10];
    

//user menu for options, used switch    
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
            //case A takes input of filename, opens and tokenizes array. 
            //outputs error if the file cannot be opened.
            case 'A':
            case 'a':
            printf("Please enter the name of the data file: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, "%s", filename);
            input = fopen(filename, "r");
            if (input == NULL){
                printf("Error, could not open file.\n");
                return 1;
            }
            printf("File successfully loaded.\n");
            while (fgets(line, buffer_size, input) != NULL){
                tokeniseRecord(line,",",date, time, steps);

                strcpy(fitness[recordcounter].date, date);
                strcpy(fitness[recordcounter].time, time);
                fitness[recordcounter].steps = atoi(steps);
                
                recordcounter++;
               

           
            }
        
            break;
            //Case B prints total number of records, taken from task 1.
            case 'B':
            case 'b':
            recordcounter = 0;
            input = fopen(filename, "r");
            while (fgets(line, sizeof(line), input) != NULL){
                    recordcounter++;
                }
                printf("Total records: %d\n", recordcounter);
            break;

            //case C finds lowest value, had to ask for help as time wasnt printing properly.
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

            //case D finds lowest value, same problem, asked for help in lab session, fixed by increasing size of steps array.
            case 'D':
            case 'd':
            highestvalue = 0;
            for (int i = 1; i < recordcounter; i++) {
                if (fitness[i].steps > highestvalue) {
                    highestvalue = fitness[i].steps;
                    currentvalue = i;
                }
            }
            printf("Largest steps: %s %s\n", fitness[currentvalue].date, fitness[currentvalue].time);
            break;

            //Case E prints mean, asked TA for help in lab to write the code.
            case 'E':
            case 'e':
            for(int i = 0; i < recordcounter; i++){
                mean += fitness[i].steps;
            }

            if (recordcounter > 0){
                mean /= recordcounter;
                
                mean = roundfloat(mean);
                printf("Mean step count: %.0f.\n", mean);
            }
            break;

            case 'F':
            case 'f':
            for (int i = 0; i < recordcounter; i++) {
                if (fitness[i].steps > 500){

                    currentlength++;
                } else {
                    if (currentlength > longestlength) {
                        longestlength = currentlength;
                        longeststart = currentstart;
                    }
                    currentstart = i + 1;
                    currentlength = 0;
                }
            }
            if (currentlength > longestlength){
                longestlength = currentlength;
                longeststart = currentstart;
            }
            printf("Longest period start: %s %s\n", fitness[longeststart].date, fitness[longeststart].time );
            
            printf("Longest period end: %s %s\n", fitness[longeststart + longestlength - 1].date, fitness[longeststart + longestlength - 1].time );

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