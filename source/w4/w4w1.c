#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,i;
    float u=0,t,ans;
    scanf("%d",&n);
    int* num=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        u+=num[i];
    }
    u/=n;
    for(i=0;i<n;i++){
        t+=(num[i]-u)*(num[i]-u);
    }
    t/=n;
    ans=sqrt(t);
    printf("%.2f",ans);
    free(num);

    return 0;
}
