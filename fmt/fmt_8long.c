#include "fmt.h"

unsigned int fmt_8long(char *dest,unsigned long i) {
  register unsigned long len,tmp;
  /* first count the number of bytes needed */
  for (len=1, tmp=i; tmp>7; ++len) tmp>>=3;
  if (dest)
    for (tmp=i, dest+=len; ; ) {
      *--dest = (tmp&7)+'0';
      if (!(tmp>>=3)) break;
    }
  return len;
}
