/*
 * @Description  : P1047 У�������
 * @Author       : ApassEr
 * @Date         : 2020-02-13 12:04:14
 * @LastEditTime : 2020-02-13 15:24:09
 * ���˼·
 */
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int l, m;
    scanf("%d %d", &l, &m);
    char a[++l];
    // ��ֻ�б����ߺ�û����������״̬
    // ȫ��0����û������
    memset(a, '0', l);
    for(int i = 0; i < m; ++i){
        int s, e;
        scanf("%d %d", &s, &e);
        // ��Ȼs��e��(e - s) + 1����
        int t = (e - s) + 1;
        // ��1��������
        memset(a + s, '1', t);
    }
    int cnt = 0;
    // ��0��ʼ�����ܹ���L + 1����
    for(int i = 0; i <= l; ++i){
        if(a[i] == '0') ++cnt;
    }
    printf("%d", cnt);
    return 0;
}