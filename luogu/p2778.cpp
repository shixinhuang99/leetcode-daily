/*
 * @Description  : P2788 数学1（math1）- 加减算式
 * @Author       : ApassEr
 * @Date         : 2020-02-11 14:29:46
 * @LastEditTime : 2020-02-11 14:39:33
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    char str[60001];
    for(int i = 0; str[i] = getchar(); ++i){
        if(str[i] == '\n' || str[i] == '\r'){
            --i;
        }else if(str[i] == EOF){
            str[i] = '\0';break;
        }
    }
    ll ans = 0;
    ll t = 0;
    int len = strlen(str);
    int index;
    for(int i = 0; i < len; ++i){
        if(ispunct(str[i])){
            index = i;break;
        }
    }
    for(int i = len - 1, j = 1; i >= index; --i){
        if(ispunct(str[i])){
            switch(str[i]){
                case '+':ans += t;t = 0;j = 1;break;
                case '-':ans -= t;t = 0;j = 1;break;
            }
        }else{
            t += ((str[i] - '0') * j);
            j *= 10;
        }
    }
    for(int i = index - 1, j = 1; i >= 0; --i, j *= 10){
        ans += ((str[i] - '0') * j);
    }
    printf("%lld", ans);
    return 0;
}