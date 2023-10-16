#include<stdio.h>

int main(){
    int l;
    float m;
    scanf("%d",&l);
    if(l>=200){
        l-=200;
        m=l*0.9;
        m+=240;
    }
    else{
        m=1.2*l;
    }
    printf("%.0f\n",m);

    return 0;
}