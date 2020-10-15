#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
int main(int argc,char **argv) {

    char base[64]={
            'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
            'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
            '0','1','2','3','4','5','6','7','8','9','+','/'};
    int count = 0;
    char *input = 0;
    char ch;
    int c=0;

    FILE *fpi;
    FILE *fpo;
    while((c= getopt(argc,argv,"i:o:"))!=EOF){
        switch(c){
            case 'i':
                fpi=fopen(optarg,"r");
                printf("optarg=%s\n",optarg);
                break;
            case 'o':
                fpo=fopen(optarg,"w");

                break;
        }
    }
    if(fpi==NULL){
        printf("reading file error");
        return 1;
    }
    while((ch=getc(fpi))!=EOF){
        input=(char*)realloc(input,count+1);
//        printf("%c",ch);

        input[count++]=ch;
    }

    int input_n[count];
    int n=count;
    for(int i=0;i<n;i++){
//        printf("%c",input[i]);
        if(input[i]<='9'&&input[i]>='0'){
            input_n[i]=input[i]-'0';
        }else{
            input_n[i]=input[i]-'7';
        }
    }
    free(input);
//    for(int i=0;i<n;i++){
//        printf("%d  ",input_n[i]);
//    }
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
//        fwrite(base[answer1],sizeof(base[answer1]),1,fpi);
//        fwrite(base[answer2],sizeof(base[answer2]),1,fpi);
        fprintf(fpo,"%c%c", base[answer1], base[answer2]);
    }

    switch(n%3){
        case 0:
            break;
        case 1:
            printf("%c",base[input_n[n-1]*4]);
//            fwrite(base[input_n[n-1]*4],sizeof(base[input_n[n-1]*4]),1,fpi);
            fprintf(fpo,"%c",base[input_n[n-1]*4]);
            printf("=");

            break;
        case 2:
            printf("%c",base[input_n[n-2]*16+input_n[n-1]*4]);
            fprintf(fpo,"%c",base[input_n[n-2]*16+input_n[n-1]*4]);
            printf("==");
            break;
    }
    fclose(fpi);
    fclose(fpo);
    return 0;
}
