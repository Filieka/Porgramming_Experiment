#include<stdio.h>

int main(){
    int input,i;
    int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char* roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    scanf("%d",&input);
    for(i=0;i<13;i++){
        while(input>=num[i]){
            printf("%s",roman[i]);
            input-=num[i];
        }
    }

    return 0;
}