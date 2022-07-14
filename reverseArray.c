#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frequencyOfEachDigit(char *s){
    int i = 0;
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(s[i] != '\0'){
        if(s[i] >= '0' && s[i] <= '9'){
            arr[s[i] - 48]++;
        }
        i++;
    }
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
}
int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.

    frequencyOfEachDigit(s);
    return 0;
}