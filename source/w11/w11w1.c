#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* replace(char* source,char* target,char* replacement,int mode) {
    char* i;
    i=strstr(source,target);
    if(mode==1){
        if(i!=NULL){
            memmove(&i[strlen(replacement)],&i[strlen(target)],strlen(&i[strlen(target)-1]));
            memcpy(i,replacement,strlen(replacement));
        }
    }
    else if(mode==2){
        while(i!=NULL){
            memmove(&i[strlen(replacement)],&i[strlen(target)],strlen(&i[strlen(target)-1]));
            memcpy(i,replacement,strlen(replacement));
            i=strstr(source,target);
        }
    }
    return source;
}