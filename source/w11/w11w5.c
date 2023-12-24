#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ans[32];
int i=31;

char* convertToDifferentBase(int dec,int base,char *result){
    char b64[64]="0123456789ABCDEFGHIJKMNLOPQRSTUVWXYZabcdefghijkmnlopqrstuvwxtz+/";
    ans[i]=b64[dec%base];
    dec/=base;
    i--;
    if(dec!=0){
        return convertToDifferentBase(dec,base,result);
    }
    else{
        return &ans[i+1];
    }
}