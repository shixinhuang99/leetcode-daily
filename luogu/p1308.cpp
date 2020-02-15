/*
 * @Description  : P1308 ͳ�Ƶ�����
 * @Author       : ApassEr
 * @Date         : 2020-02-14 12:24:23
 * @LastEditTime : 2020-02-15 15:18:35
 */
#include<bits/stdc++.h>

using namespace std;

void func(char str[]){
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        str[i] = tolower(str[i]);
    }
}
int main(void){
    char target[11];
    scanf("%s", target);
    func(target);
    char str[31];
    int w_cnt = 0, ch_cnt = -1;
    // ��һ�γ��ֵ�λ��
    bool first = true;
    bool quit = false;
    // �ַ�Ϊ��ĸ������ַ���
    bool instr = false;
    // �ַ�Ϊ��ĸ��Ŀո񣬴������
    bool done = false;
    int index;
    int i = 0;
    char ch;
    getchar();
    while(!quit){
        ch = getchar();
        ++ch_cnt;
        if(isspace(ch) || ch == EOF){
            if(ch == EOF) quit = true;
            if(instr){
                str[i] = '\0';
                i = 0;
                instr = false;
                done = true;
                func(str);
            }
        }else if(isalpha(ch)){
            instr = true;
            str[i++] = ch;
        }
        if(done){
            if(strcmp(str, target) == 0){
                ++w_cnt;
                if(first){
                    int len = strlen(str);
                    index = ch_cnt - len;
                    first = false;
                }
            }
            done = false;
        }
    }
    if(w_cnt == 0) printf("-1");
    else printf("%d %d", w_cnt, index);
    return 0;
}