#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,i,t=0;
    float sum;
    scanf("%d",&num);
    int* score=(int*)malloc(num*sizeof(int));
    for(i=0;i<num;i++){
        scanf("%d",&score[i]);
        sum+=score[i];
    }
    sum/=num;
    for(i=0;i<num;i++){
        if(score[i]<sum){
            t++;
        }
    }
    printf("%d\n",t);

    return 0;
}