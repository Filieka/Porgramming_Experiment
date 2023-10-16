#include<stdio.h>

int main(){
    char n[4];
    int i,a=0;
    scanf("%s",n);
    for(i=0;i<4;i++){
        if(n[i]==52){
            a++;
        }
    }
    if(a>0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}