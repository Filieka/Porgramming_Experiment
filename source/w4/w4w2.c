#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,change;
    float ans;
    scanf("%d",&n);
    int* num=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(num[j]<num[j+1]){
                change=num[j+1];
                num[j+1]=num[j];
                num[j]=change;
            }
        }
    }
    for(i=3;i<n-3;i++){
        ans+=num[i];
    }
    ans/=(n-6);
    printf("%.2f\n",ans);
    free(num);

    return 0;
}