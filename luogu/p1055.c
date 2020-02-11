#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void){
    char isbn[14];
    unsigned int r = 0;
    gets(isbn);
    for(int i = 0, j = 1; i < 11; ++i){
        if(isdigit(isbn[i])){
            r += ((isbn[i] - 48) * j);
            ++j;
        }
    }
    r %= 11;
    if(r == isbn[12] - 48 || (r == 10  && isbn[12] == 'X')){
        printf("Right");
    }else{
        if(r != 10){
            isbn[12] = r + 48;
            puts(isbn);
        }else{
            isbn[12] = 'X';
            puts(isbn);
        }
    }
    return 0;
}