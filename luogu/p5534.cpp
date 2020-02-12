/*
 * @Description  : P5534 ¡¾XR-3¡¿µÈ²îÊýÁÐ
 * @Author       : ApassEr
 * @Date         : 2020-02-12 15:32:50
 * @LastEditTime : 2020-02-12 15:43:46
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ll a1, a2, n;
    scanf("%lld %lld %lld", &a1, &a2, &n);
    printf("%lld", n * a1 + (n * (n - 1) * (a2 - a1)) / 2);
    return 0;
}