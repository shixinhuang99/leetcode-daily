/*
 * @Description  : P1036 Ñ¡Êý
 * @Author       : ApassEr
 * @Date         : 2020-02-13 22:55:16
 * @LastEditTime : 2020-02-13 23:03:25
 */
#include<bits/stdc++.h>

using namespace std;

int arr[20];
int isprime(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}
int dfs(int left_k, int sum, int s, int e){
    if(left_k == 0) return isprime(sum);
    int cnt = 0;
    for(int i = s; i < e; ++i){
        cnt += dfs(left_k - 1, sum + arr[i], ++s, e);
    }
    return cnt;
}
int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    printf("%d", dfs(k, 0, 0, n));
    return 0;
}