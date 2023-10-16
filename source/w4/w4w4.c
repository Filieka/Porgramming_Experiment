#include<stdio.h>

int main(){
    char num[1000];
    int i,sum1,sum2,d;
    while(1==1){
        scanf("%s",num);
        if(num[0]=='0'){
            break;
        }
        for(i=0;i<1000;i++){
            if(i%2==1){
                sum1+=num[i]-'0';
            }
            else{
                sum2+=num[i]-'0';
            }
        }
        d=sum1-sum2;
        if(d%11==0){
            printf("%s is a multiple of 11.\n",num);
        }
        else{
            printf("%s is not a multiple of 11.\n",num);
        }
    }

    return 0;
}