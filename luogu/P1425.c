#include<stdio.h>
int main(void){
    int a, b, c, d, e, f;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d %d\n",((c * 60 + d) - (a * 60 + b)) / 60, ((c * 60 + d) - (a * 60 + b)) % 60);
    return 0;
}