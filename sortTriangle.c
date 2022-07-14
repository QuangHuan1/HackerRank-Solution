#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    float p;
    int min_idx;
    float *s = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++){
        p = (float)((tr[i].a + tr[i].b + tr[i].c) / (float)2);
        s[i] = (float)(sqrtf(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c)));
    }

    for(int i = 0; i < n - 1; i++){
        min_idx = i;
        for(int j = i + 1 ; j < n; j++){
            if(s[j] < s[min_idx]){
                min_idx = j;
            }
        }
        
        triangle temp = tr[min_idx];
        tr[min_idx] = tr[i];
        tr[i] = temp;

        float temp1 = s[min_idx];
        s[min_idx] = s[i];
        s[i] = temp1;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
    printf("heheee\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

