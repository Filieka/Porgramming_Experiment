#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,row,col,i,j,location,x,y,v;
    scanf("%d %d %d",&row,&col,&num);
    int* ans=(int*)malloc(row*col*sizeof(int));
    for(i=0;i<row*col;i++){
        ans[i]=0;
    }
    for(i=0;i<num;i++){
        scanf("%d %d %d",&x,&y,&v);
        location=x*col+y;
        ans[location]=v;
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",ans[col*i+j]);
        }
        printf("\n");
    }

    free(ans);
    return 0;
}