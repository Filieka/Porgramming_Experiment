#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ans[32];

char* convertToDifferentBase(int dec,int base,char *result){
    char b64[64]="0123456789ABCDEFGHIJKMNLOPQRSTUVWXYZabcdefghijkmnlopqrstuvwxtz+/";
    int i=31;
    while(dec/base!=0){
        ans[i]=b64[dec%base];
        dec/=base;
        i--;
    }
    if(dec!=0){
        ans[i]=b64[dec];
    }
    else{
        i++;
    }
    return &ans[i];

}