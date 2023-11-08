#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,end,i,j,change;
    while((end=scanf("%d",&n))!=EOF){
        int* num=(int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(num[j]>num[j+1]){
                    change=num[j+1];
                    num[j+1]=num[j];
                    num[j]=change;
                }
            }
        }
        if(n&1){
            n/=2;
            printf("%d ",num[n]);
            i=1;
            j=1;
            while(num[n+j]==num[n]||num[n-j]==num[n]){
                if(num[n+j]==num[n]){
                    i++;
                }
                if(num[n-j]==num[n]){
                    i++;
                }
                j++;
            }
            printf("%d ",i);
            printf("1\n");
        }
        else{
            n/=2;
            printf("%d ",num[n-1]);
            i=1;
            j=1;
            while(num[n-1+j]==num[n-1]||num[n-1-j]==num[n-1]){
                if(num[n-1+j]==num[n-1]){
                    i++;
                }
                if(num[n-1-j]==num[n-1]){
                    i++;
                }
                j++;
            }
            printf("%d ",i);
            printf("%d\n",(num[n]-num[n-1])+1);
        }
        free(num);
    }

    return 0;
}