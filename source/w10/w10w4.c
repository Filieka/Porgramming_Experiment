#include <stdio.h>

int state(int i,int j,int l,int w,char g[2][100][100]){
    int x,y,t=0;
    for(x=-1;x<=1;x++){
        for(y=-1;y<=1;y++){
            if(!(x==0&&y==0)&&i+x>-1&&i+x<l&&j+y>-1&&j+y<w){
                if(g[0][i+x][j+y]=='1'){
                    t++;
                }
            }
        }
    }
    return t;
}

int main(){
    int k,i,j,a,t,l=0,w=0,count=0;
    char s;
    char g[2][100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            g[0][i][j]='0';
            g[1][i][j]='0';
        }
    }
    scanf("%d",&k);
    scanf("%*c");
    while(EOF!=scanf("%c",&s)){
        if(s!='\n'){
            g[0][l][count]=s;
            count++;
            w=count;
        }
        else{
            l++;
            count=0;
        }
    }
    l++;
    for(a=0;a<k;a++){
        for(i=0;i<l;i++){
            for(j=0;j<w;j++){
                t=0;
                t=state(i,j,l,w,g);
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
        for(i=0;i<l;i++){
            for(j=0;j<w;j++){
                g[0][i][j]=g[1][i][j];
                g[1][i][j]='0';
            }
        }
    }
    for(i=0;i<l;i++){
        for(j=0;j<w;j++){
            printf("%c",g[0][i][j]);
        }
        printf("\n");
    }
    
    return 0;
}