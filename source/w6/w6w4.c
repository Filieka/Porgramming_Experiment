#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[1000];
    int length,i,j,ans,count=0,max=0,num;
    int frequency[256];
    scanf("%s",input);
    length=strlen(input);
    for(i=0;i<256;i++){
        frequency[i]=-1;
    }
    for(i=0;i<length;i++){
        if(frequency[input[i]]<0){
            frequency[input[i]]=i;
            count++;
            continue;
        }
        if(count>max){
            max=count;
            ans=i-count;
        }
        i=frequency[input[i]];
        count=0;
        for(j=0;j<256;j++){
            frequency[j]=-1;
        }
    }
    if(count>max){
        max=count;
        ans=i-count;
    }
    for(i=0;i<max;i++){
        printf("%c",input[ans+i]);
    }
    printf("\n");
   
    return 0;
}