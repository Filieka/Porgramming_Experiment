#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int goal,int* ans){
    int i;
    for(i=0;ans[i]!=goal;i++){}
    return i;
}
void inital(int location,int num,int* ans,int max){
    int i=0,count=0;
    while(1){
        if(ans[i]==-1){
            count++;
            if(count>num){
                break;
            }
        }
        i++;
    }
    memmove(&ans[location],&ans[location+1],(max-location-1)*sizeof(int));
    if(i>location){
        i--;
    }
    memmove(&ans[i+1],&ans[i],(max-i-1)*sizeof(int));
    ans[i]=num;
}
void moveonto(int num1,int num2,int* ans,int max){
    int num1_location=search(num1,ans);
    int i;
    if(ans[num1_location+1]!=-1){
        for(i=num1_location+1;ans[i]!=-1;i++){
            inital(i,ans[i],ans,max);
            i=search(num1,ans);
        }
    }
    num1_location=search(num1,ans);
    int snap=ans[num1_location];
    if(num1==num2){
        return;
    }
    memmove(&ans[num1_location],&ans[num1_location+1],(max-num1_location-1)*sizeof(int));
    int num2_location=search(num2,ans);
    if(ans[num2_location+1]!=-1){
        for(i=num2_location+1;ans[i]!=-1;i++){
            inital(i,ans[i],ans,max);
            i=search(num2,ans);
        }
    }
    memmove(&ans[num2_location+2],&ans[num2_location+1],(max-num2_location-2)*sizeof(int));
    memcpy(&ans[num2_location+1],&snap,1*sizeof(int));
}
void moveover(int num1,int num2,int* ans,int max){
    int num1_location=search(num1,ans);
    int i;
    if(ans[num1_location+1]!=-1){
        for(i=num1_location+1;ans[i]!=-1;i++){
            inital(i,ans[i],ans,max);
            i=search(num1,ans);
        }
    }
    num1_location=search(num1,ans);
    int snap=ans[num1_location];
    if(num1==num2){
        for(i=num1_location;ans[i]!=-1;i++){}
        memmove(&ans[num1_location],&ans[num1_location+1],(i-num1_location-1)*sizeof(int));
        memcpy(&ans[i-1],&snap,1*sizeof(int));
        return;
    }
    memmove(&ans[num1_location],&ans[num1_location+1],(max-num1_location-1)*sizeof(int));
    int num2_location=search(num2,ans);
    for(i=num2_location;ans[i]!=-1;i++){}
    memmove(&ans[i+1],&ans[i],(max-i-1)*sizeof(int));
    memcpy(&ans[i],&snap,1*sizeof(int));
}
void pileonto(int num1,int num2,int* ans,int max){
    int num2_location=search(num2,ans);
    int i,j;
    if(ans[num2_location+1]!=-1){
        for(i=num2_location+1;ans[i]!=-1;i++){
            inital(i,ans[i],ans,max);
            i=search(num2,ans);
        }
    }
    int num1_location=search(num1,ans);
    for(i=num1_location;ans[i]!=-1;i++){}
    int* snap=(int*)malloc((i-num1_location)*sizeof(int));
    memcpy(snap,&ans[num1_location],(i-num1_location)*sizeof(int));
    for(j=0;j<i-num1_location;j++){
        if(snap[j]==num2){
            free(snap);
            return;
        }
    }
    memmove(&ans[num1_location],&ans[i],(max-i)*sizeof(int));
    num2_location=search(num2,ans);
    memmove(&ans[num2_location+i-num1_location+1],&ans[num2_location+1],(max-num2_location-1-i+num1_location)*sizeof(int));
    memcpy(&ans[num2_location+1],snap,(i-num1_location)*sizeof(int));
    free(snap);
}
void pileover(int num1,int num2,int* ans,int max){
    int num1_location=search(num1,ans);
    int i,j,k;
    for(i=num1_location;ans[i]!=-1;i++){}
    int* snap=(int*)malloc((i-num1_location)*sizeof(int));
    memcpy(snap,&ans[num1_location],(i-num1_location)*sizeof(int));
    for(k=0;k<i-num1_location;k++){
        if(snap[k]==num2){
            free(snap);
            return;
        }
    }
    memmove(&ans[num1_location],&ans[i],(max-i)*sizeof(int));
    int num2_location=search(num2,ans);
    for(j=num2_location;ans[j]!=-1;j++){}
    memmove(&ans[j+i-num1_location],&ans[j],(max-j-i+num1_location)*sizeof(int));
    memcpy(&ans[j],snap,(i-num1_location)*sizeof(int));
    free(snap);
}
int main(){
    int input,num1,num2,i,j=0;
    char com1[5],com2[5];
    char* command[]={"move","pile","onto","over","quit"};
    scanf("%d",&input);
    int max=2*input;
    int* ans=(int*)malloc(max*sizeof(int));
    for(i=0;i<input*2;i+=2){
        ans[i]=i/2;
        ans[i+1]=-1;
    }
    while(1){
        scanf("%s",com1);
        if(strcmp(com1,command[4])==0){
            for(i=0;i<input;i++){
                printf("%d:",i);
                while(ans[j]!=-1){
                    printf(" %d",ans[j]);
                    j++;
                }
                printf("\n");
                j++;
            }
            free(ans);
            return 0;
        }
        scanf("%d %s %d",&num1,com2,&num2);
        if(strcmp(com1,command[0])==0){
            if(strcmp(com2,command[2])==0){
                moveonto(num1,num2,ans,max);
            }
            else if(strcmp(com2,command[3])==0){
                moveover(num1,num2,ans,max);
            }
        }
        else if(strcmp(com1,command[1])==0){
            if(strcmp(com2,command[2])==0){
                pileonto(num1,num2,ans,max);
            }
            else if(strcmp(com2,command[3])==0){
                pileover(num1,num2,ans,max);
            }
        }
    }

    return 0;
}