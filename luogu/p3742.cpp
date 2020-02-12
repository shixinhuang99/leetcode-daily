/*
 * @Description  : P3742 umiµÄº¯Êý
 * @Author       : ApassEr
 * @Date         : 2020-02-12 11:45:31
 * @LastEditTime : 2020-02-12 12:07:20
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    char x[++n];
    char y[n];
    scanf("%s" ,x);
    scanf("%s" ,y);
    bool notfind = false;
    for(int i = 0; i < n; ++i){
        if(x[i] < y[i]){
            printf("-1");notfind = true;break;
        }
    }
    if(!notfind) printf("%s", y);
    return 0;
}