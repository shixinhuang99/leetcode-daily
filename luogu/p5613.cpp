/*
 * @Description  : P5613 [MtOI2019]ºÚÎÃ×Ó¶à
 * @Author       : ApassEr
 * @Date         : 2020-02-12 17:30:04
 * @LastEditTime : 2020-02-12 17:59:37
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[k];
    if(k != 0){
        for(int i = 0; i < k; ++i){
            scanf("%d", &a[i]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ){
        for(int j = 0; j < k; ++j){
            if(i == a[j]){
                ++m;break;
            }
        }
        i += m;
        ++cnt;
    }
    printf("%d", cnt);
    return 0;
}