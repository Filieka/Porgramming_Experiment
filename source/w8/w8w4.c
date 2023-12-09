#include<stdio.h>

int main(){
    int a,b,i,id,s,k,total=1,fail=0,n=0;
    scanf("%d%d",&a,&b);
    int table[5][a];
    for(i=0;i<a;i++){
        table[0][i]=0;
        table[1][i]=0;
        table[2][i]=0;
        table[3][i]=0;
        table[4][i]=0;
        scanf("%d%d%*d",&table[0][i],&table[1][i]);
    }
    for(i=0;i<b;i++){
        scanf("%d%d",&id,&s);
        for(k=0;table[0][k]<id;k++){}
        table[2][k]++;
        table[3][k]+=s;
    }
    for(i=0;i<a;i++){
        if(table[3][i]/table[2][i]<60){
            table[4][i]=1;
        }
    }
    for(i=1;i<a;i++){
        for(k=0;k<i;k++){
            n=0;
            if(table[1][k]==table[1][i]){
                n=1;
                break;
            }
        }
        if(n==0){
            total++;
        }
    }
    for(i=0;i<a;i++){
        n=0;
        if(table[4][i]==1){
            for(k=0;k<i;k++){
                if(table[4][k]==1&&table[1][k]==table[1][i]){
                    n=1;
                    break;
                }
            }
            if(n==0){
                fail++;
            }
        }
    }
    printf("%d %d\n",total,fail);
}