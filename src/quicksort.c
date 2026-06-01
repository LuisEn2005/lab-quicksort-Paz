#include "sort.h"
#include <assert.h>
#include <stdbool.h>

static void swapInt(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static int checkPartition(int* arr, int left, int right, int j, int pivot){
  for(int i = left; i < j; i++) if(arr[i] > pivot) return false;
  for(int i = j + 1; i < right; i++) if(arr[i] <= pivot) return false;
  return true;
}
static int partition(int arr[], int left, int right){
  /*
   * TODO: complete la partición de quicksort.
   * Sugerencia mínima:
   * 1. Use arr[right] como pivote.
   * 2. Mantenga a la izquierda los elementos <= pivote.
   * 3. Devuelva la posición final del pivote.
   */
  int pivot = arr[right];
  int i = right;
  int j = right;

  while(left < i){
    assert(checkPartition(arr, i + 1, right - 1, j, pivot));
    if(arr[i - 1] > pivot)
      swapInt(&arr[i], &arr[right]);
    assert(checkPartition(arr, i, right - 1, j, pivot));
    i--;
  }
  swapInt(&arr[j], &arr[right]);
  return right;
}

static void quickSortRange(int arr[], int left, int right){
  if(left >= right)
    return;

  int pivotIndex = partition(arr, left, right);
  quickSortRange(arr, left, pivotIndex - 1);
  quickSortRange(arr, pivotIndex + 1, right);
}

void quickSort(int arr[], int n){
  if(n <= 1)
    return;
  quickSortRange(arr, 0, n - 1);
}
