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

/*
 * Complete the 'possibleChanges' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY usernames as parameter.
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */
char** possibleChanges(int usernames_count, char** usernames, int* result_count) {

    char** result = malloc(usernames_count * sizeof(char**));
    *result_count = usernames_count;
    for(int i = 0; i < usernames_count; i++){
        int j = 1;
        result[i] = "NO";
        int max = 0, min = 0;
        while (usernames[i][j] != '\0')
        {   //printf("%c - %c\n", usernames[i][j] , usernames[i][0]);
            if(usernames[i][j] - usernames[i][0] > 0){
                max = j;
            }
            if(usernames[i][j] - usernames[i][0] < 0){
                min = j;
            }
            if (max < min) {
                result[i] = "YES";
                break;
            };
            //printf("%d - %d\n", max, min);
            j++;
        }
        
    }
    return result;
}

int main()
{
    

    int usernames_count = 3;
    char **usernames = malloc(usernames_count * sizeof(char**));
    usernames[0] = "ghik";
    usernames[1] = "bbtsda";
    usernames[2] = "baz";
    int result_count;
    char** result = possibleChanges(usernames_count, usernames, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%s", *(result + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    printf("\n");



    return 0;
}
