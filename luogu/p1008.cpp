/*
 * @Description  : P1008 ÈýÁ¬»÷
 * @Author       : ApassEr
 * @Date         : 2020-02-12 21:57:46
 * @LastEditTime : 2020-02-12 22:26:17
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    char str[10];
    char target[10] = "123456789";
    for(int i = 123; i < 334; ++i){
        sprintf(str, "%d%d%d", i, i * 2, i * 3);
        sort(str, str + 9);
        if(strcmp(str, target) == 0){
            printf("%d %d %d\n", i, i * 2, i * 3);
        }
    }
    return 0;
}