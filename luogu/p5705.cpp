/*
 * @Description  : P5705 【深基2.例7】数字反转
 * @Author       : ApassEr
 * @Date         : 2020-02-12 20:27:17
 * @LastEditTime : 2020-02-12 20:27:43
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char s[10];
    scanf("%s", s);
    int len = strlen(s);
    for(int i = len - 1; i >= 0; --i){
        putchar(s[i]);
    }
    return 0;
}