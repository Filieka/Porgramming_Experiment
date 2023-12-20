#include <stdio.h>
#include <math.h>
#define sl (line.point.y-point.y)/(line.point.x-point.x)

typedef struct {
  float x, y;
} Point;

typedef struct {
  Point point;
  float slope;
} Line;

int main(){
    Line line;
    Point point;
    float s;
    scanf("%f%*c%f%*c%f",&line.point.x,&line.point.y,&line.slope);
    scanf("%f%*c%f",&point.x,&point.y);
    s=(float)fabs(sl);
    if(s==line.slope){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
  
}
