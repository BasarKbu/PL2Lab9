/*
Write a function in c language that takes your student number
as a value and adds the numbers in each digit of your student
number to different dynamic arrays according to whether they
are odd or even,and displays the odd and even values in the dynamic 
arrays separately
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separateNumbers(const char* studentNumber, int** oddNumbers, int* oddCount, char** evenNumbers, int* evenCount) {
    *oddNumbers = NULL;  
    *evenNumbers = NULL; 
    *oddCount = 0;      
    *evenCount = 0;      

    int len = strlen(studentNumber);

    for (int i = 0; i < len; i++) {
        char digitChar = studentNumber[i];
        int digit = digitChar - '0';  

        if (digit % 2 == 0) {
            
            (*evenCount)++;
            *evenNumbers = (char*)realloc(*evenNumbers, (*evenCount) * sizeof(char));
            (*evenNumbers)[(*evenCount) - 1] = digitChar;
        } else {
           
            (*oddCount)++;
            *oddNumbers = (int*)realloc(*oddNumbers, (*oddCount) * sizeof(int));
            (*oddNumbers)[(*oddCount) - 1] = digit;
        }
    }
}

int main() {
    char studentNumber[20];

    printf("Enter your student number: ");
    scanf("%s", studentNumber);

    int* oddNumbers = NULL;
    char* evenNumbers = NULL;
    int oddCount = 0;
    int evenCount = 0;

    separateNumbers(studentNumber, &oddNumbers, &oddCount, &evenNumbers, &evenCount);

    printf("Odd numbers: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddNumbers[i]);
    }
    printf("\n");

    printf("Even numbers: ");
    for (int i = 0; i < evenCount; i++) {
        printf("%c ", evenNumbers[i]);
    }
    printf("\n");

    
    free(oddNumbers);
    free(evenNumbers);

    return 0;
}

