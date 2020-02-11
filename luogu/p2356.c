/*
 * @Description  : P2356 µØ÷È”Œœ∑
 * @Author       : ApassEr
 * @Date         : 2020-02-07 22:53:33
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-07 23:04:35
 */
#include<stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a[n][n];
    // 0µƒŒª÷√
    int pos[10000][2];
    int t = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0){
                pos[t][0] = i;
                pos[t++][1] = j;
            }
        }
    }
    int max = 0, ans = 0;
    for(int i = 0; i < t; ++i){
        for(int j = 0; j < n; ++j){
            ans += (a[pos[i][0]][j] + a[j][pos[i][1]]);
        }
        if(ans > max){
            max = ans;
        }
        ans = 0;
    }
    printf("%d", max);
    return 0;
}