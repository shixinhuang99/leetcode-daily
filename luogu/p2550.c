/*
 * @Description  : P2550 [AHOI2001]²ÊÆ±Ò¡½±
 * @Author       : ApassEr
 * @Date         : 2020-02-08 17:46:33
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-08 18:15:20
 */
#include<stdio.h>
#include<string.h>
int main(void){
    int n;
    scanf("%d", &n);
    int target[7];
    for(int i = 0; i < 7; ++i){
        scanf("%d", &target[i]);
    }
    int ticket[n][7];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 7; ++j){
            scanf("%d", &ticket[i][j]);
        }
    }
    int award[7] = {0};
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < 7; ++j){
            for(int k = 0; k < 7; ++k){
                if(ticket[i][j] == target[k]){
                    ++cnt;
                }
            }
        }
        if(cnt > 0){
            award[cnt - 1]++;
        }
    }
    for(int i = 6; i >= 0; --i){
        printf("%d ", award[i]);
    }
    return 0;
}