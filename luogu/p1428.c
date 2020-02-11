#include<stdio.h>
int main(void){
    int a;
    scanf("%d", &a);
    unsigned int n[a];
    for(int i = 0; i < a; ++i){
        scanf("%u", &n[i]);
    }
    for(int i = 0, ct = 0; i < a; ++i, ct = 0){
        for(int j = 0; j < i; ++j){
            if(n[j] < n[i]){
                ct++;
            }
        }
        printf("%d ", ct);
    }
    return 0;
}