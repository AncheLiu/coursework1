#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
    FITNESS_DATA fitness[1000];  // assuming max 1000 records
    int n = 0;
    char str1[100];
    FILE* file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    
    char date[11], time[6], steps[10];
    while (fgets(str1, 1000, file)!=NULL) {
        tokeniseRecord(str1, ",", date, time, steps);
        strcpy(fitness[n].date, date);
        strcpy(fitness[n].time, time);
        fitness[n].steps = atoi(steps);
        n++;
        
    }

    printf("Number of records in file: %d\n", n);

    for (n = 0; n < 3; n++) {
        printf("%s/%s/%d\n", fitness[n].date, fitness[n].time, fitness[n].steps);
    }
    fclose(file);
    return 0;
}
