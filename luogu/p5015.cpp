/*
 * @Description  : P5015 标题统计
 * @Author       : ApassEr
 * @Date         : 2020-02-12 14:22:00
 * @LastEditTime : 2020-02-12 14:33:45
 */
#include<bits/stdc++.h>
using namespace std;
int main(void){
    char s[10];
    int cnt = 0;
    for(int i = 0; s[i] = getchar(); ++i){
        if(isspace(s[i])) continue;
        else if(s[i] == EOF) break;
        ++cnt;
    }
    printf("%d", cnt);
    return 0;
}