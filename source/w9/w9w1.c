int main() {
  init();
  void *p = &block;
  size_t move;
  printf("%d, %c, %f",*(int*)p,*(char*)p+4*move,*(float*)(p+5*move));
  return 0;
}