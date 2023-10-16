#include<stdio.h>

int main(){
    float a,b,c,d;
    scanf("%f",&a);
    a*=1000;
    b=(int)a%10;
    d=a-b;
    d/=1000;
    if(b>=5){
        printf("%.2f\n",d+0.01);
        printf("%.2f\n",d);
    }
    else{
        printf("%.2f\n",d);
        printf("%.2f\n",d);
    }

    return 0;

}