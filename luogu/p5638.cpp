/*
 * @Description  : P5638 【CSGRound2】光骓者的荣耀
 * @Author       : ApassEr
 * @Date         : 2020-02-12 19:36:15
 * @LastEditTime : 2020-02-12 19:46:36
 */
#include<bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    ull a[n - 1], b[n - 1];
    for(int i = 0; i < n - 1; ++i){
        scanf("%llu", &a[i]);
    }
    // 前缀和
    b[0] = a[0];
    for(int i = 1; i < n - 1; ++i){
        b[i] = b[i - 1] + a[i];
    }
    if(k == 0){
        printf("%llu", b[n - 2]);
        return 0;
    }
    // 求出每相邻k个点的和的最大值
    ull max = b[k - 1];
    for(int i = k; i < n - 1; ++i){
        ull next = b[i] - b[i - k];
        if(next > max) max = next;
    }
    printf("%llu", b[n - 2] - max);
    return 0;
}