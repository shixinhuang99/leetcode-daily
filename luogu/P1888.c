/* P1888 Èý½Çº¯Êý */
#include<stdio.h>
int main(void){
    int a, b, c;
    int max, min, r, gcd;
    int max_2, min_2;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b && a > c){
        max = a;
        if(b > c){
            min = c;
        }else{
            min = b;
        }
    }else{
        min = a;
        if(b > c){
            max = b;
        }else{
            max = c;
        }
    }
    max_2 = max;
    min_2 = min;
    do{
        r = max % min;
        max = min;
        min = r;
    }while(r != 0);
    gcd = max;
    min = min_2/gcd;
    max = max_2/gcd;
    printf("%d/%d", min, max);
    return 0;
}