/* P1720 月落乌啼算钱 */
#include<stdio.h>
#include<math.h>
int main(void){
    double n;
    scanf("%lf", &n);
    double fn;
    // 其实是斐波那契数列
    fn = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
    printf("%.2lf", fn);
    return 0;
}