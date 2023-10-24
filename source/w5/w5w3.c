#include<stdio.h>

int main(){
    int i=0,code;
    int  num[256];
    char end;
    char line[1001];
    for(i=0;i<256;i++){
        num[i]=0;
    }
    for(i=0;i<1001;i++){
        line[i]=0;
    }
    while((end=scanf("%c",&line[i]))!=EOF){
        if(line[i]!='\n'){
            code=line[i];
            num[code]++;
        }
        else{
            for(i=1;i<1001;i++){
                for(code=255;code>0;code--){
                    if(num[code]==i){
                        printf("%d %d\n",code,num[code]);
                    }
                }
            }
            printf("\n");
            for(i=0;i<1001;i++){
                line[i]=0;
            }
            for(i=0;i<256;i++){
                num[i]=0;
            }
        }
    }

    return 0;
}