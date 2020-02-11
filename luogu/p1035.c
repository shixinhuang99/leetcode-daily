#include<stdio.h>
int main(void){
    double sn = 0;
    int k, n;

    scanf("%d", &k);
    for(double i = 1; sn <= k; i++){
        sn += (1 / i);
        n = i;
    }
    printf("%d\n", n);

    return 0;
}