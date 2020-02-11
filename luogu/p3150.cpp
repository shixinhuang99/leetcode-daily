/*
 * @Description  : P3150 pbµÄÓÎÏ·£¨1£©
 * @Author       : ApassEr
 * @Date         : 2020-02-11 21:28:13
 * @LastEditTime : 2020-02-11 21:34:39
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(a[i] % 2 == 0){
            printf("pb wins\n");
        }else{
            printf("zs wins\n");
        }
    }
    return 0;
}