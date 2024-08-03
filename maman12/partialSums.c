#include <stdio.h>
#include <stdlib.h>

/* This program takes an input Integer array and the size of the array, and returns a similar array where every
   cell of the new array is the sum of all the cells in the original array until the current cell's index */

int getInput();
int* partialSums(int*, int);

int *inputArr;
int j;

int main() {
    inputArr = (int*)malloc(sizeof(int));
    
    int arrLength = getInput();
    int *sumArr = partialSums(inputArr, arrLength);

    printf("Partial Sums array:\n");
    for (j = 0; j < arrLength; j++) { /* Printing Partial Sums array */
        printf("%d ", sumArr[j]);
    }
    printf("\n");
	
    free(inputArr);
    free(sumArr);

    return 0;
}

int getInput() {
   int temp, length = 0;
	
   printf("Please enter your input array here: \n");
   
   while((scanf("%d", &temp)) != EOF) {  /* Allocating enough memory for input */
       if (length!=0){
            inputArr = (int*)realloc(inputArr, (length+1)*sizeof(int)); 
       }
      
      if (!inputArr) {  /* Checking if there is enough memory to allocate */
            printf("Unable to allocate enough memory. \n Program terminated.\n");
            exit(0);
      } 
      
      else {
           *(inputArr+length) = temp;
           length++;
      }
   }
   
   inputArr[length] = '\0';
   
   return length;
}

int* partialSums(int *arr, int length) { /* Calculating the partial sums */
    int *sumArr = (int*) malloc(length*sizeof(int));
    if (sumArr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    sumArr[0] = arr[0];
    for (j = 1; j < length; j++) {
        sumArr[j] = sumArr[j-1] + arr[j];
    }

    return sumArr;
}



