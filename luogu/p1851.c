/*
 * @Description:P1851 ∫√≈Û”—
 * @Author: ApassEr
 * @Date: 2020-02-06 16:20:57
 * @LastEditors  : ApssEr
 * @LastEditTime : 2020-02-06 17:22:47
 */
#include<stdio.h>
#include<stdbool.h>
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = n; i <= 19000; ++i){
        int ans1 = 0;
        for(int j = 2; j <= i; ++j){
            if(i % j == 0){
                ans1 += (i / j);
            }
        }
        if(ans1 == i){
            continue;
        }
        int ans2 = 0;
        for(int j = 2; j <= ans1; ++j){
            if(ans1 % j == 0){
                ans2 += (ans1 / j);
            }
        }
        if(ans2 == i){
            printf("%d %d", i, ans1);
            break;
        }
    }
    return 0;
}