#include <stdio.h>
#include <string.h>

typedef struct {
    char inte[1000];
    char dec[1000];
} DeciVar;

int main(){
    int i,over=0,adecl,bdecl,aIntl,bIntl,decMax,intMax;
    char c;
    DeciVar a,b,ans;
    for(i=0;i<1000;i++){
        ans.dec[i]=0;
        ans.inte[i]=0;
    }
    i=0;
    while(a.inte[i-1]!='.'){
        scanf("%c",&c);
        a.inte[i]=c;
        i++;
    }
    a.inte[i-1]=0;
    scanf("%s",a.dec);
    i=0;
    while(b.inte[i-1]!='.'){
        scanf(" %c",&c);
        b.inte[i]=c;        
        i++;
    }
    b.inte[i-1]=0;
    scanf("%s",b.dec);
    adecl=strlen(a.dec);
    bdecl=strlen(b.dec);
    decMax=adecl;
    if(adecl>bdecl){
        for(i=bdecl;i<adecl;i++){
            b.dec[i]='0';
        }
    }
    else if(adecl<bdecl){
        for(i=adecl;i<bdecl;i++){
            a.dec[i]='0';
        }
        decMax=bdecl;
    }
    for(i=decMax-1;i>-1;i--){
        ans.dec[i]=(a.dec[i]+b.dec[i]-96+over)%10+48;
        over=(a.dec[i]+b.dec[i]-96+over)/10;        
    }
    aIntl=strlen(a.inte);
    bIntl=strlen(b.inte);
    intMax=aIntl;
    i=1;
    if(aIntl>bIntl){
        strncpy(&b.inte[aIntl-bIntl],b.inte,aIntl*sizeof(char));
        for(i=0;i<aIntl-bIntl;i++){
            b.inte[i]='0';
        }
        b.inte[aIntl]=0;
    }
    else if(aIntl<bIntl){
        strncpy(&a.inte[bIntl-aIntl],a.inte,bIntl*sizeof(char));
        for(i=0;i<bIntl-aIntl;i++){
            a.inte[i]='0';
        }
        a.inte[bIntl]=0;
        intMax=bIntl;
    }
    for(i=intMax-1;i>-1;i--){
        ans.inte[i]=(a.inte[i]+b.inte[i]-96+over)%10+48;
        over=(a.inte[i]+b.inte[i]-96+over)/10;        
    }
    if(over!=0){
        printf("%d",over);
    }
    printf("%s",ans.inte);
    for(i=0;i<decMax;i++){
        if(ans.dec[i]!='0'){
            printf(".%s",ans.dec);
            return 0;
        }
    }

    return 0;
}
