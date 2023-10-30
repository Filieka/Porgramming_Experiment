#include<stdio.h>

int main(){
    int num,i;
    int ans[32];
    scanf("%d",&num);
    if(num==0){
        printf("0");
    }
    else{
        for(i=0;i<32;i++){
            ans[i]='0';
        }
        for(i=0;num>=1;i++){
            ans[i]=num%2;
            num/=2;
        }
        for(i=i-1;i>=0;i--){
            printf("%d",ans[i]);
        }
    }

    return 0;
}