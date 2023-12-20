#include<stdio.h>

typedef struct {
  char studentID[20];
  int programming,programmingLab,calculus,total;
} Student;

int main(){
    int n,i,max,k;
    scanf("%d",&n);
    Student student[n];
    for(i=0;i<n;i++){
        scanf("%s%d%d%d",student[i].studentID,&student[i].programming,&student[i].programmingLab,&student[i].calculus);
        student[i].total=student[i].programming+student[i].programmingLab+student[i].calculus;
    }
    for(k=0;k<3;k++){
        max=0;
        for(i=0;i<n;i++){
            if(student[i].total>student[max].total){
                max=i;
            }
        }
        printf("%s\n",student[max].studentID);
        student[max].total=0;
    }
    
    return 0;
}
