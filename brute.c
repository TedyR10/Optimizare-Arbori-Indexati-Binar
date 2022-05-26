#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#define NMAX 100005
#define STR_LEN 20

void update(int poz, int val, int v[]){
  v[poz] += val;
}

int query(int beg, int end, int v[]){
  int sum = 0;
  for(;beg <= end ;beg++)
    sum += v[beg];
  return sum;
}

int main()
{
    int aib[NMAX], v[NMAX];
    char *com = malloc(STR_LEN);
    double time_aib = 0.0, time_norm = 0.0;
    clock_t begin, end;
    int n, m, x, a, b, i;
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &x);
        begin = clock();
        v[i] = x;
        end = clock();
        time_norm += (end - begin) / CLOCKS_PER_SEC;
    }
    while(1){
        scanf("%s", com);
        if(!strcmp(com, "update")){
            scanf("%d%d\n", &a, &b);
            begin = clock();
            update(a, b, v);
            end = clock();
            time_norm += (end - begin) / CLOCKS_PER_SEC;
        }
        else
        if(!strcmp(com, "query")){
            scanf("%d%ds\n", &a, &b);
            begin = clock();
            printf("Normal result: %d\n", query(a, b, v));
            end = clock();
            time_norm += (end - begin) / CLOCKS_PER_SEC; 
        }
        else
        if(!strcmp(com, "exit"))
            break;

    }
    free(com);
    return 0;
}
