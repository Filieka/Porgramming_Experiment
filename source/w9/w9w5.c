int main() {
  float *a, *b;
  init(&a, &b);
  int sum = 0;
  
  while(a!=b){
    sum+=*((int*)a);
    a++;
  }
  
  printf("%d", sum);
  return 0;
}