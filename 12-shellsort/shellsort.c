#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void generateRandomNumbers(int array[]) {
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;  
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("...\n");
}

void doShellSort(int array[], int gapType, int* comparisonCount, int* moveCount) {
    int i, j, temp;
    int gap = ARRAY_SIZE / gapType;

    *comparisonCount = 0;
    *moveCount = 0;

    while (gap > 0) {
        printf("Sorting with gap = %d:\n", gap);

        for (i = gap; i < ARRAY_SIZE; i++) {
            temp = array[i];
            (*moveCount)++;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
                (*comparisonCount)++;
                (*moveCount)++;
            }
            array[j] = temp;
            (*moveCount)++;
        }

        printArray(array, 20);
        printf("\n");

        gap = (gapType == 2) ? (gap / 2) : (gap / 3);
    }

    printf("Sorted shellArray (gap = %d):\n", gapType);
    printArray(array, 20);
}

void doInsertionSort(int array[], int* comparisonCount, int* moveCount) {
    int i, j, temp;

    *comparisonCount = 0;
    *moveCount = 0;

    for (i = 1; i < ARRAY_SIZE; i++) {
        temp = array[i];
        (*moveCount)++; 

        for (j = i - 1; j >= 0 && array[j] > temp; j--) {
            array[j + 1] = array[j];
            (*comparisonCount)++;
            (*moveCount)++;  
        }
        array[j + 1] = temp;
        (*moveCount)++;
    }

    printf("Sorted insertionArray:\n");
    printArray(array, ARRAY_SIZE); 
}

int main() {
    int array[ARRAY_SIZE];
    int comparisonCount, moveCount;

    generateRandomNumbers(array);

    printf("Shell Sort (n/2):\n");
    doShellSort(array, 2, &comparisonCount, &moveCount);
    printf("Shell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    generateRandomNumbers(array);

    printf("Shell Sort (n/3):\n");
    doShellSort(array, 3, &comparisonCount, &moveCount);
    printf("Shell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    generateRandomNumbers(array);

    printf("Insertion Sort:\n");
    doInsertionSort(array, &comparisonCount, &moveCount);
    printf("Insertion Sort - Comparisons: %d, Moves: %d\n", comparisonCount, moveCount);

    return 0;
}
