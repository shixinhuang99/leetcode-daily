/*
 * @Description  : P2525 Uim�����˽������֮��
 * @Author       : ApassEr
 * @Date         : 2020-02-08 16:42:36
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-08 17:16:29
 */
#include<stdio.h>
#include<stdlib.h>
// �׳�
int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n - 1);
}
int comp(const void*a, const void*b){
    return *(int*)a - *(int*)b;
}
int main(void){
    int n;
    scanf("%d", &n);
    char a[n + 1];
    for(int i = 0; a[i] = getchar(); ++i){
        if(a[i] == ' ' || a[i] == '\n' || a[i] == '\r'){
            --i;
        }else if(a[i] == EOF){
            a[i] == '\0';break;
        }
    }
    // ���Ѿ��ù�����
    int m[n + 1];
    for(int i = 0; i < n + 1; ++i){
        m[i] = 0;
    }
    // ��1��ʼ������ʼ��Ϊ1
    int ans = 1;
    // ����չ��
    int f = n - 1;
    for(int i = 0; i < n; ++i){
        int len = a[i] - '0';
        int cnt = 0;
        for(int j = 1; j < len; ++j){
            if(m[j] == 0){
                ++cnt;
            }
        }
        ans += (cnt * factorial(f--));
        m[len] = len;
    }
    if(ans == 1){
        printf("ERROR");
    }else{
        // �濵��չ��
        ans -= 2;
        f = n - 1;
        // ѡ������
        int target[n];
        for(int i = 0; i < n; ++i){
            target[i] = i + 1;
        }
        for(int i = 0; i < n - 1; ++i){
            // ��t����С����
            int t = ans / factorial(f);
            int cnt = t;
            // ���ù������ŵ�����
            qsort(target, n, sizeof(int), comp);
            // ��֪��t����С��������֪�����ǵ�ǰ��t + 1��û�б�ѡ�ϵ���
            printf("%d ", target[t]);
            // ��֪n <= 9
            target[t] = 10;
            ans -= (cnt * factorial(f--));
        }
        for(int i = 0; i < n; ++i){
            if(target[i] != 10){
                printf("%d", target[i]);break;
            }
        }
    }
    return 0;
}