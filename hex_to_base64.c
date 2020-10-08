#include<stdio.h>
#include<stdlib.h>

int main() {
    char base[64]={
            'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
            'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
            '0','1','2','3','4','5','6','7','8','9','+','/'};
    int count = 0;
    char *input = 0;
    char ch;
    do {
        scanf("%c",&ch);
        input=(char*)realloc(input,count);
        input[count++]=ch;
    }while(ch!='\n');
    int input_n[count];
    int n=count-1;
    for(int i=0;i<n;i++){
        printf("%c",input[i]);
        if(input[i]<='9'&&input>='0'){
            input_n[i]=input[i]-'0';
        }else{
            input_n[i]=input[i]-'7';
        }
    }
    for(int i=0;i<n;i++){
        printf("%d  ",input_n[i]);
    }
    for (int i = 0; i < (n / 3); i++) {
        int a = 0, b = 0, c = 0, total = 0;
        int answer1, answer2;
        a = input_n[i * 3] * 256;
        b = input_n[i * 3 + 1] * 16;
        c = input_n[i * 3 + 2];
        total = a + b + c;
        answer1 = total / 64;
        answer2 = total % 64;

        printf("%c%c", base[answer1], base[answer2]);


    }
    switch(n%3){
        case 0:
            break;
        case 1:
            printf("%c",base[input_n[n-1]*4]);
            printf("=");
            break;
        case 2:
            printf("%c",base[input_n[n-2]*16+input_n[n-1]*4]);
            printf("==");
            break;
    }








    return 0;
}
