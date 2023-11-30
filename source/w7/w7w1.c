#include<stdio.h>
#include<stdlib.h>

int algorithm(int n){
    int count=1;
    while(1){
        if(n==1){
            return count;
        }
        if(n&1){
            n=3*n+1;
        }
        else{
            n/=2;
        }
        count++;
    }
}

int main(){
    int start,end,i,max,a,b;
    while(1){
        max=0;
        if(scanf("%d",&start)==EOF){
            break;
        }
        scanf("%d",&end);
        if(start>end){
            a=start;
            b=end;
        }
        else{
            a=end;
            b=start;
        }
        int* each=(int*)malloc((a-b+1)*sizeof(int));
        for(i=0;i<a-b+1;i++){
            each[i]=algorithm(b+i);
            if(each[i]>max){
                max=each[i];
            }
        }
        printf("%d %d %d\n",start,end,max);
        free(each);
        
    }

    return 0;
}