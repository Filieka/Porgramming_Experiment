#include<stdio.h>

int f(int x){
    return 3*x+1;
}

int g(int x,int y){
    return x*y-3;
}

int main(){
    int i,ans;
    char cal[100];
    char lest;
    scanf("%s",cal);
    for(i=0;cal[i]!='\0';i++){
        lest=' ';
        if(cal[i]=='F'||cal[i]=='G'){
            lest=cal[i];
        }
    }
    if(lest==' '){}
    if(lest=='F'){

    }

}