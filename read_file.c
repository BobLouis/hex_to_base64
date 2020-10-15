#include<stdio.h>
#include<stdlib.h>

int main() {

    int count = 0;
    char *input = 0;
    char ch;

    FILE *fp = fopen("input.txt", "r+");
    if (fp == NULL) {
        printf("reading file error");
        return 1;
    }
    while ((ch = getc(fp)) != EOF) {
        input = (char *) realloc(input, count + 1);
        printf("%c", ch);

        input[count++] = ch;
    }

    return 0;
}