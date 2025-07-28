#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void bubbleSort(int A[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
}

void insertionSort(int A[], int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    j = i - 1;
    temp = A[i];

    while (j >= 0 && A[j] > temp) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = temp;
  }
}

void mergeSort(int A[], int n) {

  int aux[n], i, j, k, l1, u1, l2, u2, size;
  size = 1;

  while (size < n) {
    l1 = 0;
    k = 0;

    while (l1 + size < n) {
      l2 = l1 + size;
      u1 = l2 - 1;
      u2 = (l2 + size - 1 < n) ? l2 + size - 1 : n - 1;
      for (i = l1, j = l2; i <= u1 && i <= u2; k++) {
        if (A[i] <= A[j]) {
          aux[k] = A[i++];

        } else {
          aux[k] = A[j++];
        }
      }
      for (; i <= u1; k++) {
        aux[k] = A[i++];
      }
      for (; j <= u2; k++) {
        aux[k] = A[j++];
      }
      l1 = u2 + 1;
    }
    for (i = l1; k < n; k++) {
      aux[k++] = A[i];
    }
    for (i = 0; i < n; i++) {
      A[i] = aux[i];
    }
    size *= 2;
  }
}

void selectionSort(int A[], int n) {
  int i, j, pos, least, temp;
  for (i = 0; i < n; i++) {
    least = A[i];
    pos = i;
    for (j = i + 1; j < n; j++) {
      if (A[j] < least) {
        least = A[j];
        pos = j;
      }
    }

    if (i != pos) {
      temp = A[j];
      A[j] = A[j + 1];
      A[j + 1] = temp;
    }
  }
}

void display(int A[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d  ", A[i]);
  }
  printf("\n");
}

int main() {

  int i, A[MAX], n;

  printf("Enter n : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    A[i] = rand() % 100;
  }
  display(A, n);
  time_t start, end;
  double seconds;
  start = time(NULL);

  mergeSort(A, n);

  end = time(NULL);
  seconds = difftime(end, start);

  display(A, n);
  printf("Time is %lf/n", seconds);

  return 0;
}