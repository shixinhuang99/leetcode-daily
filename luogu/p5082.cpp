/*
 * @Description  : P5082 ³É¼¨
 * @Author       : ApassEr
 * @Date         : 2020-02-12 14:43:47
 * @LastEditTime : 2020-02-12 15:11:55
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    ll a = 0, b = 0;
    for(ll i = 0, t; i < n; ++i){
        scanf("%lld", &t);
        a += t;
    }
    for(ll i = 0, t; i < n; ++i){
        scanf("%lld", &t);
        b += t;
    }
    double ans = a * 3 - b * 2;
    ans /= (a - b);
    printf("%.6lf", ans);
    return 0;
}