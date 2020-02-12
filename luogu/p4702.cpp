/*
 * @Description  : P4702 È¡Ê¯×Ó
 * @Author       : ApassEr
 * @Date         : 2020-02-12 12:50:04
 * @LastEditTime : 2020-02-12 12:51:26
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 0, t; i < n; ++i){
        scanf("%d", &t);
        sum += t;
    }
    if(sum % 2 == 0) printf("Bob");
    else printf("Alice");
    return 0;
}