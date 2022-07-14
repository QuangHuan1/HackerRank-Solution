#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n = 0, i = 0, sum = 0;
    scanf("%d\n", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    while(i < n){
        scanf("%d", &arr[i]);
        sum += arr[i];
        i++;
        
    }
    printf("%d", sum);
    free(arr);
    return 0;
}