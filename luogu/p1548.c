/* P1548 棋盘问题 */
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
// 以上为手推
/* 标准公式：
          mn(m + 1)(n + 1)
矩形个数 ：------------------    正方形个数：n * m + (n - 1) * (m - 1).....直到短边等于0
                  4
长方形个数 = 矩形个数 - 正方形个数 */