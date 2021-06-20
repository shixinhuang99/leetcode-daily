/*
 * @Description  : P1149 火柴棒等式
 * @Author       : ApassEr
 * @Date         : 2020-02-13 20:38:28
 * @LastEditTime : 2020-02-13 21:44:56
 *
 * 很慢(940ms),因为 n <= 24,所以可以用这个打表
 */
#include<bits/stdc++.h>

using namespace std;

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int func(int n){
    char str[10];
    sprintf(str, "%d", n);
    int len = strlen(str);
    int ans = 0;
    for(int i = 0; i < len; ++i){
        ans += arr[str[i] - '0'];
    }
    return ans;
}
int main(void){
    int n;
    scanf("%d", &n);
    n -= 4;
    int cnt = 0;
    for(int i = 0; i < 800; ++i){
        for(int j = 0; j < 800; ++j){
            int k = i + j;
            int a = func(i);
            int b = func(j);
            int c = func(k);
            if(a + b + c == n){
                // printf("%d+%d=%d\n", i, j, k);
                ++cnt;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}