/*
 * @Description  : P5594 ¡¾XR-4¡¿Ä£ÄâÈü
 * @Author       : ApassEr
 * @Date         : 2020-02-12 16:13:07
 * @LastEditTime : 2020-02-12 16:22:22
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[n][m];
    int ans[k];
    bool lock[k];
    for(int i = 0; i < k; ++i){
        ans[i] = 0;
        lock[i] = false;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0, t; j < n; ++j){
            t = a[j][i];
            if(!lock[t - 1]){
                ans[t - 1]++;
                lock[t - 1] = true;
            }
        }
        for(int j = 0; j < k; ++j){
            lock[j] = false;
        }
    }
    for(int i = 0; i < k; ++i){
        printf("%d ", ans[i]);
    }
    return 0;
}