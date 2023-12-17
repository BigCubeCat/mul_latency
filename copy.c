#include <stdio.h>
#include <stdlib.h>

#define N 1

union ticks {
  unsigned long long t64;
  struct s32 {
    long th, tl;
  } t32;
} begin, end;

unsigned long long func() {
  int a;
  int b;
  scanf("%d", &a);
  scanf("%d", &b);
  asm("rdtsc\n" : "=a"(begin.t32.th), "=d"(begin.t32.tl));
  a = a * b;
  asm("rdtsc\n" : "=a"(end.t32.th), "=d"(end.t32.tl));
  printf("%d\n", a);
  return (end.t64 - begin.t64) / N;
}

int main() { printf("%lld\n", func()); }
