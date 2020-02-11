/*
 * @Description  : P2670 É¨À×ÓÎÏ·
 * @Author       : ApassEr
 * @Date         : 2020-02-09 12:27:36
 * @LastEditors  : ApassEr
 * @LastEditTime : 2020-02-09 12:48:46
 */
#include<stdio.h>
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    char board[n][m];
    char ch = getchar();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            board[i][j] = getchar();
            if(board[i][j] == '\n' || board[i][j] == '\r'){
                --j;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == '?'){
                // È·¶¨É¨Ãè·¶Î§
                int x1 = i - 1;
                x1 < 0 ? x1 = 0 : x1 == x1;
                int x2 = i + 1;
                x2 > n - 1 ? x2 = n - 1 : x2 == x2;
                int y1 = j - 1;
                y1 < 0 ? y1 = 0 : y1 == y1;
                int y2 = j + 1;
                y2 > m - 1 ? y2 = m - 1 : y2 == y2;

                int cnt = 0;
                for(int k = x1; k <= x2; ++k){
                    for(int l = y1; l <= y2; ++l){
                        if(board[k][l] == '*')++cnt;
                    }
                }
                board[i][j] = cnt + '0';
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            putchar(board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}