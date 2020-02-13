/*
 * @Description  : P1003 铺地毯
 * @Author       : ApassEr
 * @Date         : 2020-02-13 16:11:58
 * @LastEditTime : 2020-02-13 16:53:01
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int m[n][4];
    for(int i = 0; i < n; ++i){
        scanf("%d %d %d %d", &m[i][0], &m[i][1], &m[i][2], &m[i][3]);
    }
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = -1;
    // 每个矩形的范围为 x;a -> a + g y:b -> b + k;
    // 逆序查找即可
    for(int i = n - 1; i >= 0; --i){
        bool a = (x >= m[i][0] && x <= m[i][0] + m[i][2]);
        bool b = (y >= m[i][1] && y <= m[i][1] + m[i][3]);
        if(a && b){
            ans = i + 1;break;
        }
    }
    printf("%d", ans);
    return 0;
}