#include<stdio.h>
// a > b
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b , a % b);
}
int main(void){
    int a, b, c, d;
    scanf("%d/%d", &a, &b);
    scanf("%d/%d", &c, &d);
    int r1 = a * c;
    int r2 = b * d;
    if(r1 != r2){
        int _gcd = gcd(r1 > r2 ? r1 : r2, r1 < r2 ? r1 : r2);
        r1 /= _gcd;
        r2 /= _gcd;
    }else{
        r1 = r2 = 1;
    }
    printf("%d %d", r2, r1);
    return 0;
}