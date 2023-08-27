#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(NULL));

    int n = 10000; // Tamanho da lista
    int listaBubble[n];
    int listaQuick[n];
    int listaMerge[n];

    for (int i = 0; i < n; i++) {
        int numeroAleatorio = rand() % 100000; // Números aleatórios entre 0 e 99999
        listaBubble[i] = numeroAleatorio;
        listaQuick[i] = numeroAleatorio;
        listaMerge[i] = numeroAleatorio;
    }

    // Bubble Sort
    clock_t inicioBubble = clock();
    bubbleSort(listaBubble, n);
    clock_t fimBubble = clock();
    printf("Tempo de execucao do Bubble Sort: %f segundos\n", (double)(fimBubble - inicioBubble) / CLOCKS_PER_SEC);

    // Quick Sort
    clock_t inicioQuick = clock();
    quickSort(listaQuick, 0, n - 1);
    clock_t fimQuick = clock();
    printf("Tempo de execucao do Quick Sort: %f segundos\n", (double)(fimQuick - inicioQuick) / CLOCKS_PER_SEC);

    // Merge Sort
    clock_t inicioMerge = clock();
    mergeSort(listaMerge, 0, n - 1);
    clock_t fimMerge = clock();
    printf("Tempo de execucao do Merge Sort: %f segundos\n", (double)(fimMerge - inicioMerge) / CLOCKS_PER_SEC);

    return 0;
}
