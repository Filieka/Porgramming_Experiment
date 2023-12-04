#include<stdio.h>
#include<stdlib.h>

void ans(int i,int* remain,int* count,int* data,int* memory){
    (*count)++;
    printf("%d ",data[i]);
    memory[i]=0;
    (*remain)--;
}

void end(int* remain,int* count){
    if((*remain)<=0){
        printf("\n");
        exit(0);
    }
    *count=0;
}

int main(){
    int x,y,i,num,k=0;
    int *remain=&num,*count=&k;
    scanf("%d %d",&x,&y);
    int* data=(int*)malloc(x*y*sizeof(int));
    int* memory=(int*)malloc(x*y*sizeof(int));
    for(i=0;i<x*y;i++){
        scanf("%d",&data[i]);
        memory[i]=1;
    }
    printf("%d ",data[0]);
    memory[0]=0;
    i=0;
    num=x*y-1;
    while(1){
        end(remain,count);
        do{
            i++;
            ans(i,remain,count,data,memory);
        }while(memory[i+1]!=0&&*count<y-1);
        end(remain,count);
        do{
            i+=y;
            ans(i,remain,count,data,memory);
        }while(memory[i+y]!=0&&*count<x-1);
        end(remain,count);
        do{
            i--;
            ans(i,remain,count,data,memory);
        }while(memory[i-1]!=0&&*count<y-1);
        end(remain,count);
        do{
            i-=y;
            ans(i,remain,count,data,memory);
        }while(memory[i-y]!=0&&*count<x-1);
    }
    free(data);
    free(memory);

    return 0;
}