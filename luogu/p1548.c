/* P1548 �������� */
#include<stdio.h>
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int s = 0, r = 0;
    int _long = (n >= m ? n : m);
    int _short = (n <= m ? n : m);
    for(int i = _short, j = _long; i >= 1; --i, --j){
        s += (i * j);
    }
    for(int i = _short, j = _long; i >= 1; --i, --j){
        for(int k = j - 1; k >= 1; --k){
            r += (i * k);
        }
    }
    for(int i = _long, j = _short; i >= 1; --i, --j){
        for(int k = j - 1; k >= 1; --k){
            r += (i * k);
        }
    }
    printf("%d %d", s, r);
    return 0;
}
// ����Ϊ����
/* ��׼��ʽ��
          mn(m + 1)(n + 1)
���θ��� ��------------------    �����θ�����n * m + (n - 1) * (m - 1).....ֱ���̱ߵ���0
                  4
�����θ��� = ���θ��� - �����θ��� */