/*
 * @Description  : P5660 Êý×ÖÓÎÏ·
 * @Author       : ApassEr
 * @Date         : 2020-02-12 19:58:52
 * @LastEditTime : 2020-02-12 20:00:43
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char s[9];
    scanf("%s", s);
    int cnt = 0;
    for(int i = 0; i < 8; ++i){
        if(s[i] == '1') ++cnt;
    }
    printf("%d", cnt);
    return 0;
}