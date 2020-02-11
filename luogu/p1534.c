/* P1534 不高兴的津津（升级版） */
#include<stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a, b;
    int r = 0, f = 0;
    if(n > 0){
        scanf("%d %d", &a, &b);
        r += (b + a - 8);
        for(int i = 1; i < n; ++i){
            f += (b + a - 8);
            scanf("%d %d", &a, &b);
            r += (f + b + a - 8);
        }
        printf("%d", r);
    }else{
        printf("0");
    }
    return 0;
}