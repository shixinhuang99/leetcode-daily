/*
 * @Description  : P1047 校门外的树
 * @Author       : ApassEr
 * @Date         : 2020-02-13 12:04:14
 * @LastEditTime : 2020-02-13 15:24:09
 * 题解思路
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int l, m;
    scanf("%d %d", &l, &m);
    char a[++l];
    // 树只有被移走和没被移走两种状态
    // 全置0，表没被移走
    memset(a, '0', l);
    for(int i = 0; i < m; ++i){
        int s, e;
        scanf("%d %d", &s, &e);
        // 显然s到e有(e - s) + 1棵树
        int t = (e - s) + 1;
        // 置1，表被移走
        memset(a + s, '1', t);
    }
    int cnt = 0;
    // 从0开始数，总共有L + 1棵树
    for(int i = 0; i <= l; ++i){
        if(a[i] == '0') ++cnt;
    }
    printf("%d", cnt);
    return 0;
}