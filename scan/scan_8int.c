#include "scan.h"

unsigned int scan_8int(const char* src,unsigned int* dest) {
  unsigned long l;
  register int len=scan_8long(src,&l);
  *dest=l;
  return len;
}
