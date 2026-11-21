#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j:
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    srand(time(NULL));
    int n;
    printf("Размер массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректный размер массива!\n");
        return 1;
    }
    int* arr = malloc(n * sizeof(int));
    int* copy = malloc(n * sizeof(int));

    if (arr == NULL || copy == NULL) {
        printf("Ошибка выделения памяти!\n");
        free(arr);
        free(copy);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
        copy[i] = arr[i];
    }
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Сортировка пузырьком заняла: %.6f секунд\n", seconds);
    for (int i = 0; i < n; i++) {
        arr[i] = copy[i];
    }

    start = clock();
    insertionSort(arr, n);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Сортировка вставками заняла: %.6f секунд\n", seconds);
    for (int i = 0; i < n; i++) {
        arr[i] = copy[i];
    }

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Сортировка слиянием заняла: %.6f секунд\n", seconds);

    free(arr);
    free(copy);

    return 0;
}