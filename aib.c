#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#define NMAX 100005
#define STR_LEN 20
 
void update_aib(int poz, int val, int n, int aib[]){
  for(;poz <= n;poz += (poz & -poz))
    aib[poz] += val;
}
 
int query_aib(int poz, int n, int aib[]){
  int sum = 0;
  for(;poz > 0;poz -= (poz & -poz))
    sum += aib[poz];
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
        update_aib(i, x, n, aib);
        end = clock();
        time_aib += (end - begin) / CLOCKS_PER_SEC;
    }
    while(1){
        scanf("%s", com);
        if(!strcmp(com, "update")){
            scanf("%d%d\n", &a, &b);
            begin = clock();
            update_aib(a, b, n, aib);
            end = clock();
            time_aib += (end - begin) / CLOCKS_PER_SEC;
        }
        else
        if(!strcmp(com, "query")){
            scanf("%d%ds\n", &a, &b);
            begin = clock();
            printf("Aib result: %d\n", query_aib(b, n, aib) - query_aib(a - 1, n, aib));
            end = clock();
            time_aib += (end - begin) / CLOCKS_PER_SEC;
        }
        else
        if(!strcmp(com, "exit"))
            break;
    }
    free(com);
    return 0;
}