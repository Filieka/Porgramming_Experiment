#include<stdio.h>

int main(){
    int num[1000];
    int i=-1;
    do{
        i++;
        scanf("%d",&num[i]);
    }while(num[i]!=0);
    for(i=0;num[i]!=0;i++){
        if(num[i]%11==0){
            printf("%d is a multiple of 11.\n",num[i]);
        }
        else{
            printf("%d is not a multiple of 11.\n",num[i]);
        }
    }

    return 0;
}