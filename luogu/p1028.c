/* P1028 ÊýµÄ¼ÆËã */
#include<stdio.h>
int n;
int ar[1001];
int main(void){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i / 2; ++j){
            ar[i] += ar[j];
        }
        ar[i]++;
    }
    printf("%d", ar[n]);
    return 0;
}