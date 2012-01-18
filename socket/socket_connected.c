#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"


int socket_connected(int s) {
  struct sockaddr si;
  socklen_t sl=sizeof si;
  if (getpeername(s,&si,&sl))
    return 0;
  return 1;
}
