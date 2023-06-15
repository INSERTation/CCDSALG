#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char path[500];
    printf("Enter the path of the file to be sorted: ");
    scanf("%s", path);

    // Dynamically allocate memory for records based on the maximum number of records
    int maxRecords = 100000; // Increased maximum number of records
    Record *records = malloc(maxRecords * sizeof(Record));
    if (records == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    readFile(records, path);

    // Calculate the number of records based on the file content
    int n, InTime, SelTime, MergeTime;
    FILE *fp = fopen(path, "r");
    fscanf(fp, "%d", &n);
    fclose(fp);

    // Perform insertion sort
    long startTime = currentTimeMillis();
    insertionSort(records, n);
    long endTime = currentTimeMillis();

    printf("Sorted records using Insertion Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s\n", records[i].idNumber, records[i].name);
    }
	
	InTime = endTime - startTime;
    printf("Insertion Sort Time: %ld milliseconds\n", InTime);

    // Perform selection sort
    startTime = currentTimeMillis();
    selectionSort(records, n);
    endTime = currentTimeMillis();

    printf("\nSorted records using Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s\n", records[i].idNumber, records[i].name);
    }
	SelTime = endTime - startTime;
    printf("Selection Sort Time: %ld milliseconds\n", SelTime);

    // Perform merge sort
    startTime = currentTimeMillis();
    mergeSort(records, 0, n - 1);
    endTime = currentTimeMillis();

    printf("\nSorted records using Merge Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s\n", records[i].idNumber, records[i].name);
    }
	
	MergeTime = endTime - startTime;
    printf("Merge Sort Time: %ld milliseconds\n\n", MergeTime);
    
    // Perform heap sort
	startTime = currentTimeMillis();
	heapSort(records, n);
	endTime = currentTimeMillis();

	printf("\nSorted records using Heap Sort:\n");
	for (int i = 0; i < n; i++) {
    	printf("ID: %d, Name: %s\n", records[i].idNumber, records[i].name);
	}

	int HeapTime = endTime - startTime;
	printf("Heap Sort Time: %ld milliseconds\n\n", HeapTime);

	printf("Final algorithm run times: \n\n");
	printf("Insertion Sort Time: %ld milliseconds\n", InTime);
	printf("Selection Sort Time: %ld milliseconds\n", SelTime);
	printf("Merge Sort Time: %ld milliseconds\n", MergeTime);
	printf("Heap Sort Time: %ld milliseconds\n\n", HeapTime);

    
    // Free the dynamically allocated memory
    free(records);

    return 0;
}