/*
 * @Description  : P2141 珠心算测验
 * @Author       : ApassEr
 * @Date         : 2020-02-13 10:58:05
 * @LastEditTime : 2020-02-13 11:33:43
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    // 标记去重
    bool mark[10000] = {false};
    for(int i = 0; i < n; ++i){
        // < n - 1防越界
        for(int j = 0; j < n - 1; ++j){
            if(j == i) continue;
            for(int k = j + 1; k < n; ++k){
                if(k == i) continue;
                if(a[j] + a[k] == a[i] && !mark[i]){
                    ++cnt;
                    mark[i] = true;
                    // printf("%d+%d=%d\n", a[j], a[k], a[i]);
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}