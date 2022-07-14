#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void quickSort(int* Data, int l , int r)
{
	// If the first index less or equal than the last index
	if (l <= r)
	{
		// Create a Key/Pivot Element
		int key = Data[(l+r)/2];

		// Create temp Variables to loop through array
		int i = l;
		int j = r;

		while (i <= j)
		{
			while (Data[i] < key)
				i++;
			while (Data[j] > key)
				j--;

			if (i <= j)
			{
				swap(&Data[i], &Data[j]);
				i++;
				j--;
			}
		}

		// Recursion to the smaller partition in the array after sorted above

		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}

int filledOrders(int order_count, int* order, int k) {
    long volume = 0;
    int num_order = 0;
    int i, j, min_idx; 
    quickSort(order, 0, order_count-1);
    for (i = 0; i < order_count; i++) 
    { 
        volume += order[i];
        if (volume <= k) {
        num_order++;
        }
    } 
    return num_order;
}

int main()
{
    
    int order_count = 6;
    int order[] = {1, 1, 3, 5, 1, 1};
    int k = 4;
    int result = filledOrders(order_count, order, k);
    printf("%d\n", result);

    return 0;
}

