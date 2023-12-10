#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

int buffer_size = 150;

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[8];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H