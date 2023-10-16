#include<stdio.h>

int main(){
    int n[4];
    int m,i;
    for(i=0;i<4;i++){
        scanf("%d",&n[i]);
    }
    m=n[0];
    for(i=1;i<4;i++){
        if(n[i]>m){
            m=n[i];
        }
    }
    printf("%d\n",m);
    
    return 0;
}