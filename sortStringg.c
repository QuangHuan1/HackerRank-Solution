#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CountUniqueCharacters(const char* str){
    int count = 0;
    for (int i = 0; i < strlen(str); i++){
        int appears = 0;
        for (int j = 0; j < i; j++){
            if (str[j] == str[i]){
                appears = 1;
                break;
            }
        }
        if (!appears){
            count++;
        }
    }
    return count;
}

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a, b) <= 0 ? 1 : 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    if( CountUniqueCharacters(a) > CountUniqueCharacters(b)){
        return 1;
    }
    else if(CountUniqueCharacters(a) == CountUniqueCharacters(b)){
        return strcmp(a, b);
    }
    else return 0;

}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) > strlen(b)){
        return 1;
    }
    else if ( strlen(a) == strlen(b)){
        return strcmp(a, b);
    }
    else return 0;
}
//cmp_func là hàm so sánh 2 character!!!!!
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-1;j++){
            if(cmp_func(arr[j], arr[j+1]) > 0)
            {
                char *temp;
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}