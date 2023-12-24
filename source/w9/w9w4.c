int main() {
  init();
  char *str = s;
  int sum=0;
  int len=strlen(s);
  int i=len-1,total=0,count=1;
  while(i>=0){
  	if(str[i]>=48&&str[i]<=57){
    	total+=(str[i]-48)*count;
      	count*=10;
    }
    if(!(str[i]>=48&&str[i]<=57)&&total>0){
      	 sum+=total;
     	 total=0;
     	 count=1;
    }
    i--;
  }
  printf("%d", sum);
  return 0;
}