#include<stdio.h>

int main(){
    int i,j,k,l,n,num,change,count;
    scanf("%d",&num);
    for(k=0;k<num;k++){
        scanf("%d",&l);
        int* line=(int*)malloc(l*sizeof(int));
        for(n=0;n<l;n++){
            scanf("%d",&line[n]);
        }
        count=0;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-i-1;j++){
                if(line[j]>line[j+1]){
                    change=line[j+1];
                    line[j+1]=line[j];
                    line[j]=change;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }

    return 0;
}