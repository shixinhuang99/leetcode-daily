/*
 * @Description  : P1887 乘积最大3
 * @Author       : ApassEr
 * @Date         : 2020-02-06 21:37:57
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-06 22:34:43
 */
/*
打表：
#include<stdio.h>
void func(int n, int m){
    if(m == 0){
        return;
    }
    int t;
    if(n % m == 0){
        t = n / m;
    }else{
        t = (n / m) + 1;
    }
    printf("%d\n", t);
    --m;
    n -= t;
    return func(n, m);
}
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    func(n, m);
    return 0;
}
*/

#include<stdio.h>
int n, m;
int main(void){
    scanf("%d %d", &n, &m);
    // 当一个数n被分为m份时，当每份数量相等，这m个数的乘积最大
    int x = n / m;
    // 如果不能整除，求出余数y，平均分配给y个数，即让其中y个数都+1
    int y = n % m;
    // 要求字典序最小，让结尾的y个数都+1
    for(int i = m; i >= y + 1; --i){
        printf("%d ", x);
    }
    for(int i = y; i >= 1; --i){
        printf("%d ", x + 1);
    }
    return 0;
}