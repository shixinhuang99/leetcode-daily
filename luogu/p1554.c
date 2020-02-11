/* P1554 梦中的统计 */
#include<stdio.h>
int main(void){
    int m, n;
    scanf("%d %d", &m, &n);
    int ct[10] = {0};
    for(int i = m; i <= n; ++i){
        int t = i;
        while(t){
            ct[t % 10]++;
            t /= 10;
        }
    }
    for(int i = 0; i < 10; ++i){
        printf("%d ", ct[i]);
    }
    return 0;
}