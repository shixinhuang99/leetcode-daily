/*
 * @Description  : P1887 �˻����3
 * @Author       : ApassEr
 * @Date         : 2020-02-06 21:37:57
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-06 22:34:43
 */
/*
���
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
    // ��һ����n����Ϊm��ʱ����ÿ��������ȣ���m�����ĳ˻����
    int x = n / m;
    // ��������������������y��ƽ�������y��������������y������+1
    int y = n % m;
    // Ҫ���ֵ�����С���ý�β��y������+1
    for(int i = m; i >= y + 1; --i){
        printf("%d ", x);
    }
    for(int i = y; i >= 1; --i){
        printf("%d ", x + 1);
    }
    return 0;
}