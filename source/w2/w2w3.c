#include <stdio.h> 
  
int main(){
	
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    /*if((c>d&&((a<=c&&c<b)||(c>=b&&d<=a)))||(d>c&&((a<=d&&d<b)||(d>=b&&c<=a)))){
        printf("overlay\n");
    }
    else if((d>c&&((b<=c&&c<a)||(d>=a&&c<=b)))||(c>d&&((b<=d&&d<a)||(c>=a&&d<=b)))){
        printf("overlay\n");
    }
    else{
        printf("no overlay\n");
    }*/
    if((d>c&&a>=d&&b>=d)||(c>d&&a>=c&&b>=c)||(d>c&&a<=c&&b<=c)||(c>d&&a<=d&&b<=d)){
        printf("no overlay\n");
    }
	else{
        printf("overlay\n");
    }

	return 0;
}
