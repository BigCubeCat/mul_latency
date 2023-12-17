#include <stdio.h>
#include <stdlib.h>

#define N 1

union ticks {
  unsigned long long t64;
  struct s32 {
    long th, tl;
  } t32;
} begin, end;

unsigned long long func(int a, int b) {
  asm("rdtsc\n" : "=a"(begin.t32.th), "=d"(begin.t32.tl));
  a = a * b;
  asm("rdtsc\n" : "=a"(end.t32.th), "=d"(end.t32.tl));
  printf("%d\n", a);
  return (end.t64 - begin.t64) / N;
}

int writeResult(unsigned long long result) {
  FILE *file = fopen("myfile2.txt", "a");
  fprintf(file, "%lld", result);
  fclose(file);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    printf("No args\n");
    exit(1);
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  writeResult(func(a, b));
}
