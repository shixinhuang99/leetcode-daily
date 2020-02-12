/*
 * @Description  : P5710 【深基3.例2】数的性质
 * @Author       : ApassEr
 * @Date         : 2020-02-12 21:06:06
 * @LastEditTime : 2020-02-12 21:15:56
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    bool a = (n % 2 == 0);
    bool b = (n > 4 && n <= 12);
    printf("%d %d %d %d", a && b, a || b, (a && !b) || (!a && b), !a && !b);
    return 0;
}