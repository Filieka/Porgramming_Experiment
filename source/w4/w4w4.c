#include <stdio.h>

int main(){
    char num[1001];    
    while(1){
        int sum1=0,sum2=0,i,d;
        scanf("%s", num);
        if (num[0]=='0'){
            break;
        }
        for(i=0;num[i]!='\0';i++){
            if (i%2==0) {
                sum1+=num[i]-'0';
            } else {
                sum2+=num[i]-'0';
            }
        }
        d=sum1-sum2;        
        if(d%11==0){
            printf("%s is a multiple of 11.\n",num);
        }
        else {
            printf("%s is not a multiple of 11.\n",num);
        }
    }

    return 0;
}

