#ifndef TIMEOUTACCEPT_H
#define TIMEOUTACCEPT_H

#include "uint16.h"
#include "uint32.h"

extern int timeoutaccept4(int,char *,uint16*,unsigned int);
extern int timeoutaccept6(int,char *,uint16*,unsigned int,uint32 *scope_id);

#endif
