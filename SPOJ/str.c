#include<stdio.h>

void rev_str(char *s){
    int i,len;
    char tmp;
    for(len=0;s[len]!='\0';len++);
    for(i=0;i<(len/2);i++){
        tmp  = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}

int main(){
    char *str = "What the hell";
    scanf("%[^\t\n]s",str);
    rev_str(str);
    printf("%s",str);
}
