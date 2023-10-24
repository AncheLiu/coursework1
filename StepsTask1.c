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
    FITNESS_DATA fitness[10000];
    int i = 0;
    char str[100];
    FILE *file = fopen("FitnessData_2023.csv","r");
    if (file == NULL) {
		perror("");
		return 1;
	}
    while(fgets(str,10000,file)!=NULL){
        char date[11],time[6],steps[4];
        tokeniseRecord(str,",",date,time,steps);
        fitness[i].steps = atoi(steps);
        strcpy(fitness[i].date, date);
        strcpy(fitness[i].time, time);
        i++;
    }
    
    printf("Number of records in file: %d \n", i);
    for(i=0;i<3;i++){
        printf("%s/%s/%d",fitness[i].date,fitness[i].time,fitness[i].steps);
    }
    fclose(file);
    return 0;

}
