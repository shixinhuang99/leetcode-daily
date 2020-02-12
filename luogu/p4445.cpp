/*
 * @Description  : P4445 [AHOI2018初中组]报名签到
 * @Author       : ApassEr
 * @Date         : 2020-02-12 12:31:39
 * @LastEditTime : 2020-02-12 12:33:34
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    long long ans = 0;
    int f, s;
    scanf("%d", &f);
    for(int i = 1; i < n; ++i){
        scanf("%d", &s);
        ans += s <= f ? f : s;
        f = s;
    }
    printf("%lld", ans);
    return 0;
}