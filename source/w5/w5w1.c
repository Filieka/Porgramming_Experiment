#include<stdio.h>
int* sort(int n,int* line){
    int i,j,change;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(line[j]<line[j+1]){
                change=line[j+1];
                line[j+1]=line[j];
                line[j]=change;
            }
        }
    }
    return line;
}
void ans(int n,int* num,int divide,int i){
    int seperate[n],odd[n],even[n];
    int j,k=0,e=0,o=0;
    int* ans;
    for(j=0;j<n;j++){
      seperate[j]=0;
      odd[j]=0;
      even[j]=0;
    }
    for(j=0;j<n;j++){
        if(num[j]%divide==i){
            seperate[k]=num[j];
            k++;
        }
    }
    for(j=0;j<k;j++){
        if(seperate[j]%2==0){
            even[e]=seperate[j];
            e++;
        }
        else{
            odd[o]=seperate[j];
            o++;
        }
    }
    ans=odd;
    ans=sort(o,ans);
    for(j=0;j<o;j++){
        printf("%d\n",ans[j]);
    }
    ans=even;
    ans=sort(e,even);
    for(j=e-1;j>-1;j--){
        printf("%d\n",ans[j]);
    }
}
int main(){
    do{
        int n,divide,i;
        scanf("%d%d",&n,&divide);
        if(n==0&&divide==0){
            printf("0 0\n");
            break;
        }
        int num[n];
        for(i=0;i<n;i++){
            num[i]=0;
        }
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        printf("%d %d\n",n,divide);
        for(i=(1-divide);i<divide;i++){
            ans(n,num,divide,i);
        }
    }while(1==1);
    return 0;
}