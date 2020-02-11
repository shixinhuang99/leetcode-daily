/*
 * @Description  : P2669 金币
 * @Author       : ApassEr
 * @Date         : 2020-02-09 11:39:33
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-09 17:25:27
 */
#include<stdio.h>
#include<math.h>
int main(void){
    int k;
    scanf("%d", &k);
    int gold = 0;
    int n = 1;
    // 等差数列前n项和
    while(n * (n + 1) <= 2 * k){
        ++n;
    }
    n -= 1;
    for(int i = 1; i <= n; ++i){
        gold += pow(i, 2);
    }
    // 剩下的
    int t = k - ((n * (n + 1)) / 2);
    gold += (t * (n + 1));
    printf("%d", gold);
    return 0;
}