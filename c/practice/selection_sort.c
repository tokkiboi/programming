#include <stdio.h>
#include <math.h>

void selectionSort(int arr[], int arr_size);

int main(void)
{
    int i;
    int arr[] = {37, 5, 9, 3, 12};
    selectionSort(arr, 5);
    for (i = 0; i<5; i++) {
        printf("%d: %d\n", i, arr[i]);
    }
    return 0;
}

void selectionSort(int arr[], int arr_size)
{
    int current;
    int smallestIndex;
    int temp;
    int walker;

    for(current = 0; current < arr_size-1; current++)
    {
      smallestIndex = current;
      for(walker = current; walker<arr_size; walker++ )
      {
          if (arr[walker] < arr[smallestIndex])
            smallestIndex = walker;
      }
      temp = arr[current];
      arr[current] = arr[smallestIndex];
      arr[smallestIndex] = temp;
    }
    return;
}
