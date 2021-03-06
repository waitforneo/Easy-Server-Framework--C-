#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "socket.h"

#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT EINVAL
#endif

int socket_udp6(void)
{
#ifdef LIBC_HAS_IP6
  int s;

  if (noipv6) goto compat;
  s = socket(PF_INET6,SOCK_DGRAM,0);
  if (s == -1) {
    if (errno == EINVAL || errno == EAFNOSUPPORT) {
compat:
      s=socket(AF_INET,SOCK_DGRAM,0);
      noipv6=1;
      if (s==-1) return -1;
    } else
    return -1;
  }
  return s;
#else
  return socket_udp();
#endif
}
