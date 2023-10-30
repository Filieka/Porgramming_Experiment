#include<stdio.h>
#include<stdlib.h>

int prime(int num){
    int i;
    if(num<=1)return 0;
    if(num==2)return 1;
    if(num%2==0)return 0;    
    for(i=3;i<num;i++) {
        if(num%i==0){
            return 0;
        }
    }    
    return 1;
}

int compare(const void* a, const void* b){
    int num1=*(int*)a,num2=*(int*)b;    
    int prime1=prime(num1);
    int prime2=prime(num2);
    
    if(prime1&&prime2){
        return (num2-num1);
    }
    else if(prime1){
        return -1;
    }
    else if(prime2){
        return 1;
    }
    else{
        return (num1-num2);
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];    
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }    
    qsort(arr,n,sizeof(int),compare);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}