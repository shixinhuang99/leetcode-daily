/* Ğ¡Óã»áÓĞÎ£ÏÕÂğ */
#include<stdio.h>
int main(void){
    double s, x;
    double r = 7, m = 0;
    scanf("%lf%lf", &s, &x);
    for(int i = 0; m < s - x; ++i){
        m += r;
        r *= 0.98;
    }
    if(m + r > s + x){
        printf("n");
    }else{
        printf("y");
    }
    return 0;
}