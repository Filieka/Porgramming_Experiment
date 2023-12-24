#include<stdio.h>
int main() {
  init();
  char *str = s1;
  char *key = s2;
  int count=0;
  while(str!=NULL){
    str=strstr(str,key);
    if(str!=NULL){
      count++;
      str=&str[1];
    }
  }
  printf("%d", count);
  return 0;
}
