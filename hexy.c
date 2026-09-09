#include <stdio.h>
#include <stdlib.h>

void print_clear(char *s, int len) { printf("%s", s); }

int main() {
  int c;
  int mem_i = 0;
  char *s = (char *)calloc(0x10, sizeof(char));
  while ((c = getchar()) != EOF) {
    s[mem_i % 0x10] = c;
    if (mem_i % 0x10 == 0x0) {
      printf("%08x ", mem_i);
    }
    printf("%02x ", c);
    mem_i++;
    if (mem_i % 0x10 == 0x0) {
      print_clear(s, 0x10);
      printf("\n");
    }
  }
  printf("\n");
}
