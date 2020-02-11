/* P1014 Cantor±í */
#include<stdio.h>
#include<stdbool.h>
int main(void){
    unsigned long n, temp;
    unsigned long line; // ÐÐÊý
    scanf("%lu", &n);
    temp = n;
    for(line = 1; temp > line; ++line){
        temp -= line;
    }
    bool odd = true;
    if(line % 2 == 0){
        odd = false;
    }
    unsigned long a, b;
    if(odd){
        printf("%lu/%lu", line - temp + 1, temp);
    }else{
        printf("%lu/%lu", temp, line - temp + 1);
    }
    return 0;
}