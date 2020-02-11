/*
 * @Description  : P3717 [AHOI2017³õÖÐ×é]cover
 * @Author       : ApassEr
 * @Date         : 2020-02-11 22:07:08
 * @LastEditTime : 2020-02-11 22:53:58
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int b[++n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            b[i][j] = 0;
        }
    }
    int x, y;
    double dis;
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &x, &y);
        b[x][y] = 1;
        for(int j = 1; j < n; ++j){
            for(int k = 1; k < n; ++k){
                dis = sqrt(pow(x - j, 2) + pow(y - k, 2));
                if(dis <= r) b[j][k] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(b[i][j]) ++cnt;
        }
    }
    printf("%d", cnt);
    return 0;
}