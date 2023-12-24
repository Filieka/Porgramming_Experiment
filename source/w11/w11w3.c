#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void las(int i,int n,char* in){
    if(!(i<n)){}
    else{
        printf("%s\n",in);
        int count,k=0,j=0;
        char* ans=(char*)malloc(2*strlen(in)*sizeof(char));
        while(k<strlen(in)){
            count=0;
            while(k+count<strlen(in)&&in[k+count]==in[k]){
                count++;
            }
            ans[j]=count+48;
            ans[j+1]=in[k];
            j+=2;
            k=k+count;
        }
        las(i+1,n,ans);
        free(ans);
    }
}

int main(){
    int n,i=0;
    char in[2]={'1'};
    scanf("%d",&n);
    las(i,n,in);

}