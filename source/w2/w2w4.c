#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b<=c){
        printf("can not construct\n");
    }
    else if(a*a+b*b==c*c){
        printf("right triangle\n");
    }
    else if(a*a+b*b>c*c){
        printf("acute triangle\n");
    }
    else if(a*a+b*b<c*c){
        printf("obtuse triangle\n");
    }

    return 0;

}