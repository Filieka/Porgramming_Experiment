#include <stdio.h>

int state(int i,int j,char g[2][5][7]){
    int x,y,t=0;
    for(x=-1;x<=1;x++){
        for(y=-1;y<=1;y++){
            if(!(x==0&&y==0)&&i+x>-1&&i+x<5&&j+y>-1&&j+y<7){
                if(g[0][i+x][j+y]=='1'){
                    t++;
                }
            }
        }
    }
    return t;
}

int main(){
    int k,i,j,a,t;
    char g[2][5][7];
    scanf("%d",&k);
    for(i=0;i<5;i++){
        for(j=0;j<7;j++){
            g[0][i][j]='0';
            g[1][i][j]='0';
            scanf(" %c",&g[0][i][j]);
        }
    }
    for(a=0;a<k;a++){
        for(i=0;i<5;i++){
            for(j=0;j<7;j++){
                t=0;
                t=state(i,j,g);
                if(t>=2){
                    if(g[0][i][j]=='1'){
                        if(t<=3){
                            g[1][i][j]='1';
                        }
                        else{
                            g[1][i][j]='0';
                        }
                    }
                    else{
                        if(t==3){
                            g[1][i][j]='1';
                        }
                        else{
                            g[1][i][j]='0';
                        }
                    }
                }
                else{
                    g[1][i][j]='0';
                }
            }   
        }
        for(i=0;i<5;i++){
            for(j=0;j<7;j++){
                g[0][i][j]=g[1][i][j];
                g[1][i][j]='0';
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<7;j++){
            printf("%c",g[0][i][j]);
        }
        printf("\n");
    }
    
    return 0;
}