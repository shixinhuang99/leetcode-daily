/* P1720 ����������Ǯ */
#include<stdio.h>
#include<math.h>
int main(void){
    double n;
    scanf("%lf", &n);
    double fn;
    // ��ʵ��쳲���������
    fn = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
    printf("%.2lf", fn);
    return 0;
}