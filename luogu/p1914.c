// С��ͯ--����
#include<stdio.h>
#include<string.h>
int main(void){
    char str[51];
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    n %= 26;
    for(int i = 0; i < strlen(str); ++i){
        // Ϊ��ֹ����char���ͷ�Χ����str[i] + n���Ƚ϶�����str[i] += n
        while(str[i] + n > 'z'){
            str[i] -= 26;
        }
        str[i] += n;
        putchar(str[i]);
    }
    return 0;
}