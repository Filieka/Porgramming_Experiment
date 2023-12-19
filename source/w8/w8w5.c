#include<stdio.h>
#define SIZE 19
#define right board[i+1][j]==c&&board[i+2][j]==c&&board[i+3][j]==c&&board[i+4][j]==c
#define rightdown board[i+1][j+1]==c&&board[i+2][j+2]==c&&board[i+3][j+3]==c&&board[i+4][j+4]==c
#define down board[i][j+1]==c&&board[i][j+2]==c&&board[i][j+3]==c&&board[i][j+4]==c
#define leftdown board[i-1][j+1]==c&&board[i-2][j+2]==c&&board[i-3][j+3]==c&&board[i-4][j+4]==c

char judge(char c,int i,int j,char board[SIZE][SIZE]){
    if(i<SIZE-4&&right){
        return c;
    }
    if(i<SIZE-4&&j<SIZE-4&&rightdown){
        return c;
    }
    if(j<SIZE&&down){
        return c;
    }
    if(i>3&&j<SIZE-4&&leftdown){
        return c;
    }
    
}

int main(){
    char board[SIZE][SIZE];
    int i,j;
    char ans;
    for(i=0;i<SIZE;i++){
        scanf("%s",board[i]);
    }
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]!='_'){
                ans=judge(board[i][j],i,j,board);
                if(ans=='O'){
                    printf("White\n");
                    return 0;
                }
                else if(ans=='X'){
                    printf("Black\n");
                    return 0;
                }
            }
        }
    }
    printf("No winner\n");

    return 0;
}
