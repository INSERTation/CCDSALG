#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

//Insertion Sort
void insertionSort(Record *records, int n) {
    int i, j;
    Record key;
    for (i = 1; i < n; i++) {
        key = records[i];
        j = i - 1;

        while (j >= 0 && records[j].idNumber > key.idNumber) {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = key;
    }
}

// Selection sort algorithm
void selectionSort(Record *records, int n) {
    int i, j, min_idx;
    Record temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (records[j].idNumber < records[min_idx].idNumber)
                min_idx = j;
        }
        temp = records[min_idx];
        records[min_idx] = records[i];
        records[i] = temp;
    }
}


// Merge function for Merge Sort
void merge(Record *records, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Record *L = (Record *)malloc(n1 * sizeof(Record));
    Record *R = (Record *)malloc(n2 * sizeof(Record));

    for (i = 0; i < n1; i++)
        L[i] = records[left + i];
    for (j = 0; j < n2; j++)
        R[j] = records[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].idNumber <= R[j].idNumber) {
            records[k] = L[i];
            i++;
        } else {
            records[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        records[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        records[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort algorithm
void mergeSort(Record *records, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
 
        mergeSort(records, left, mid);
        mergeSort(records, mid + 1, right);

        merge(records, left, mid, right);
    }
}


//Heap Sort algorithm

void heapify(Record *records, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && records[left].idNumber > records[largest].idNumber)
        largest = left;

    if (right < n && records[right].idNumber > records[largest].idNumber)
        largest = right;

    if (largest != i) {
        Record temp = records[i];
        records[i] = records[largest];
        records[largest] = temp;

        heapify(records, n, largest);
    }
}

void heapSort(Record *records, int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(records, n, i);

    for (int i = n - 1; i > 0; i--) {
        Record temp = records[0];
        records[0] = records[i];
        records[i] = temp;

        heapify(records, i, 0);
    }
}





#endif