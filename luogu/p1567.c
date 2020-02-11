#include<stdio.h>
int main(void){
    unsigned long a;
    unsigned long ct = 0, temp = 0;
    scanf("%lu", &a);
    unsigned long long n[a];
    for(int i = 0; i < a; ++i){
        scanf("%llu", &n[i]);
    }
    for(int i = 0; i < a - 1; ++i){
        if(n[i] < n[i + 1]){
            ct++;
        }else if(n[i] == n[i + 1]){
            continue;
        }else{
            ct > temp ? temp = ct : temp == temp;
            ct = 0;
        }
    }
    ct = temp;
    printf("%lu", ct + 1);
    return 0;
}