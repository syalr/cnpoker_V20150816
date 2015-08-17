#ifndef _COMMON_H_INCLUDED_
#define _COMMON_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>	
#include <assert.h>
#include <errno.h>	
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>	
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>	

#include <iostream>
#include <vector>
#include <map>
#include <list>

typedef unsigned int uint;

typedef int64_t 	INT64;
typedef int32_t 	INT32;
typedef int16_t 	INT16;
typedef int8_t 		INT8;
typedef uint64_t 	UINT64;
typedef uint32_t 	UINT32;
typedef uint16_t 	UINT16;
typedef uint8_t 	UINT8;
typedef int 		SOCKET;
typedef int 		BOOL;

typedef uint8_t 	BYTE;
typedef uint16_t 	WORD;
typedef uint32_t 	DWORD;
typedef uint16_t 	USHORT;

typedef float 		FLOAT;
typedef double 		DOUBLE;
typedef int 		INT;
typedef unsigned int 	UINT;
typedef char 		CHAR;
typedef short 		SHORT;
typedef unsigned short 	USHORT;
typedef char 		*LPSTR, *PSTR;
typedef const char 	*LPCSTR, *PCSTR;

typedef void		VOID, *LPVOID;
typedef long		LONG;
typedef unsigned long	ULONG;

#include <string.h>

#include "Const.h"
#include "Define.h"
#include "Protocol.h"
#include "CommStruct.h"
#include "PackageStruct.h"
#include "PackageStruct_AG.h"
#include "PackageStruct_AL.h"
#include "PackageStruct_CA.h"

#include "PackageStruct_GD.h"
#include "PackageStruct_LD.h"

#include "Protocol_AG.h"
#include "Protocol_AL.h"
#include "Protocol_CA.h"
#include "Protocol_CL.h"
#include "Protocol_GD.h"
#include "Protocol_LD.h"

#endif // _COMMON_H_INCLUDED_
