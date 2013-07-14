#include<stdio.h>

#define strlen(s,len) for(len=0;*(s+len)!='\0';len++);

void revers(char *txt){
    int i,tmp=0;
    int len=0;
    strlen(txt,len);
    for(i=len-1;i>=0;i++){
        tmp++;
        if()
    }
    printf("%d\n",len);
}

int main(){
    char* str = "My name is 1234";
    revers(str);
}
