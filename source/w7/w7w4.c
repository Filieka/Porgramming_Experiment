#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,location,i,count,kill,max,action=0,d=-1;
    do{
        scanf("%d%d",&num,&location);
        if(num==0||location==0){
            break;
        }
        int* line=(int*)malloc(num*sizeof(int));
        for(i=0;i<num;i++){
            line[i]=i;
        }
        max=num;
        if(num>1){
            count=0;
            i=0;
            while(num>1){
                if(line[i]!=-1){
                    if(i==d&&count>location){
                        i++;
                        if(i==max){
                            i=0;
                        }
                        continue;
                    }
                    count++;
                    if(count==location&&action==0){
                        d=i;
                        action=1;
                    }
                    if(count==location*2&&action==1){
                        line[d]=line[i];
                        line[i]=-1;
                        i=d;
                        action=0;
                        num--;
                        count=0;
                    }
                }
                i++;
                if(i==max){
                    i=0;
                }            
            }
        }
        i=0;
        while(line[i]==-1){
            i++;
        }
        i=line[i]+1;
        i=1+max-i+1;
        while(i>max){
            i-=max;
        }
        printf("%d\n",i);
    }while(1);

    return 0;
}