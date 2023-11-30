#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double slope(int point1x,int point1y,int point2x,int point2y){
    int dx,dy;
    dx=point2x-point1x;
    dy=point2y-point1y;
    
    return (double)dy/dx;
}
double calculate(int point1x,int point1y,int point2y,double a){
    double dx,dy,length;
    dy=point1y-point2y;
    dx=dy/a;
    dx=dx*dx;
    dy=dy*dy;
    length=dx+dy;
    length=sqrt(length);

    return length;
}

int main(){
    int time,n,t=0,num,i,j,change;
    scanf("%d",&time);
    while(t<time){
        int x=0,y=1;
        double length=0;
        scanf("%d",&num);
        int* data=(int*)malloc(num*2*sizeof(int));
        for(i=0;i<num*2;i+=2){
            scanf("%d%d",&data[i],&data[i+1]);
        }
        for(i=0;i<(num-1)*2;i+=2){
            for(j=0;j<num*2-i-2;j+=2){
                if(data[j]<data[j+2]){
                    change=data[j];
                    data[j]=data[j+2];
                    data[j+2]=change;
                    change=data[j+1];
                    data[j+1]=data[j+3];
                    data[j+3]=change;
                }
            }
        }
        for(i=3;i<num*2;i+=2){
            if(data[i]>data[y]){
                length=length+calculate(data[i-1],data[i],data[y],slope(data[i-1],data[i],data[i-3],data[i-2]));
                y=i;
            }
        }
        printf("%.2lf\n",length);
        t++;
        
        free(data);
    }
    
    return 0;
}