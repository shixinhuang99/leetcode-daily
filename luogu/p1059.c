#include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
int main(void){
    int n;
    scanf("%d", &n);
    int ar[n];
    int ct = n;
    // srand(time(0));
    for(int i = 0; i < n; i++){
        scanf("%d", &ar[i]);
        // ar[i] = (rand() % 1000) + 1;
    }
    for(int i = 0; i < n; i++){
        int min = ar[i];
        for(int j = i + 1; j < n; j++){
            // ����
            if(min > ar[j]){
                min = ar[j];
                ar[j] = ar[i];
                ar[i] = min;
            // ȥ�ء�min != 0 �������Ѿ���Ϊ0�����޳����������ظ��Ƚϻ�ʹct��ֵ����
            }else if(min == ar[j] && min != 0){
                ar[j] = 0;
                ct--;
            }
        }
    }
    printf("%d\n", ct);
    for(int i = 0; i < n; i++){
        if(ar[i] != 0){
            printf("%d ", ar[i]);
        }
    }
    return 0;
}