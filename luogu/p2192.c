/*
 * @Description  : P2192 HXY�濨Ƭ
 * @Author       : ApassEr
 * @Date         : 2020-02-07 21:22:14
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-07 21:42:35
 */
#include<stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    char ch;
    char five[n];
    char zero[n];
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        ch = getchar();
        if(ch == ' ' || ch == '\n' || ch == '\r'){
            --i;
        }else if(ch == '5'){
            five[x++] = '5';
        }else{
            zero[y++] = '0';
        }
    }
    int cnt;
    int t = x * 5;
    while(t % 9 != 0){
        t -= 5;
    }
    cnt = t / 5;
    if(cnt == 0 && y != 0){
        printf("0");
    }else if(cnt == 0 && y == 0){
        printf("-1");
    }else{
        for(int i = 0; i < cnt; ++i){
            printf("5");
        }
        for(int i = 0; i < y; ++i){
            printf("0");
        }
    }
    return 0;
}