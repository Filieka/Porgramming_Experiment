#include<stdio.h>
#include<stdlib.h>

int main(){
    int xl,h,xr,max=0,min=0,i;
    int* house=(int*)malloc(sizeof(int));
    while(scanf("%d%d%d",&xl,&h,&xr)!=EOF){
        if(max<xr){
            i=max;
            max=xr;
            house=(int*)realloc(house,(max+1)*sizeof(int));
            for(i=i;i<max;i++){
                house[i]=0;
            }
        }
        for(i=xl;i<xr;i++){
            if(house[i]<h){
               house[i]=h;
           }
        }
    }
    for(i=1;i<=max;i++){
        if(house[i]!=house[i-1]){
            printf("%d %d ",i,house[i]);
        }
    }
    free(house);

    return 0;
}