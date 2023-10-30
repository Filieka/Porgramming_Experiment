#include<stdio.h>

int main(){
    char str;
    int end,enter=1;
    while(end=scanf("%c",&str)!=EOF){
        if(enter!=0&&str>=97&&str<=122){
            printf("%c",str-32);
            enter=0;
        }
        else if(str=='\n'||str=='.'||str=='?'){
            printf("%c",str);
            enter++;
        }
        else if(enter!=0&&str>=65&&str<=90){
            printf("%c",str);
            enter=0;
        }
        else if(str>=48&&str<=57){
            printf("%c",str);
            enter=0;
        }
        else{
            printf("%c",str);
        }
    }

    return 0;
}