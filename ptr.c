#include<stdio.h>
#include<string.h>

void strcat_Ptr(char *s, char *t)  {
    while(*s) {
        s++;
    }
    while(*t) {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}

int main() {
    char s[20], t[20];
    printf("Enter two strings: ");
    scanf("%s%s", &s, &t);
    strcat_Ptr(s, t);
    printf("string is %s", s);
    return 0;
}

