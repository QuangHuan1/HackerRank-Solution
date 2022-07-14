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


char* timeConversion(char* s) {
    char *subtext = malloc(2*sizeof(char));
    char *subtext1 = malloc(2*sizeof(char));
    strncpy(subtext,&s[0],2);
    subtext[2] = '\0';
    if(strstr(s, "PM") > 0){
        if(strcmp(subtext, "01") == 0){
            s[0] = '1';
            s[1] = '3';
        }
    }
    if(strcmp(subtext, "07") == 0){printf("Oke");}
}

int main()
{

    char* s = "01:05:45PM";
    char* result = timeConversion(s);

    //printf("%s\n", s);

    return 0;
}