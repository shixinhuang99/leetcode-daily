#include<stdio.h>
int main(void){
    int x;
    unsigned long n;
    unsigned long ct = 0;
    scanf("%d%lu", &x, &n);
    for(unsigned long i = 0; i < n; ++i, ++x){
        if(x == 6 || x == 7){
            continue;
        }else if(x > 7){
            x = 1;
        }
        ct += 250;
    }
    printf("%lu", ct);
    return 0;
}