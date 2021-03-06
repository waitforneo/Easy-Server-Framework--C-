#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"


int socket_accept(int s,char *ip,uint16 *port) {
  struct sockaddr_in si;
  socklen_t len = sizeof si;
  int fd;
  if ((fd=accept(s,(struct sockaddr*) &si,&len))<0) return -1;
  *(uint32*)ip = *(uint32*)&si.sin_addr;
  uint16_unpack_big((char *) &si.sin_port,port);
  return fd;
}
