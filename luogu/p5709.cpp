/*
 * @Description  : P5709 ¡¾Éî»ù2.Ï°6¡¿Apples Prologue
 * @Author       : ApassEr
 * @Date         : 2020-02-12 20:37:48
 * @LastEditTime : 2020-02-12 20:53:47
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);
    if(t == 0){
        printf("%d", m);
        return 0;
    }
    int ans;
    if(s % t == 0) ans = m - s / t;
    else ans = m - (s / t + 1);
    if(ans < 0) printf("0");
    else printf("%d", ans);
    return 0;
}