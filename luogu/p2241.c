/*
 * @Description  : P2241 统计方形（数据加强版）
 * @Author       : ApassEr
 * @Date         : 2020-02-07 21:57:47
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-07 22:23:48
 */
#include<stdio.h>
int main(void){
    unsigned long long n, m;
    scanf("%llu %llu", &n, &m);
    unsigned long long a = 0, b = 0;
    a = (n * m * (n + 1) * (m + 1)) / 4;
    unsigned long long _short = n < m ? n : m;
    unsigned long long _long = n > m ? n : m;
    for(unsigned long long i = _short, j = _long; i >= 1; --i, --j){
        b += (i * j);
    }
    printf("%llu %llu", b, a - b);
    return 0;
}