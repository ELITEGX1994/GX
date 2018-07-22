#ifndef _MRP_BASE_TYPE_H_
#define _MRP_BASE_TYPE_H_

#ifdef __cplusplus
	#if __cplusplus
	 extern "C"{
	#endif
#endif/*__cplusplus*/

#ifdef MMRP_FALSE
#undef MMRP_FALSE
#endif
#define MMRP_FALSE 0

#ifdef MVRP_FALSE
#undef MVRP_FALSE
#endif
#define MVRP_FALSE 0

#ifdef MVRP_TRUE
#undef MVRP_TRUE
#endif
#define MVRP_TRUE 1

#ifdef MSRP_FALSE
#undef MSRP_FALSE
#endif
#define MSRP_FALSE 0

#ifdef MSRP_TRUE
#undef MSRP_TRUE
#endif
#define MSRP_TRUE 1

#ifdef CHAR
#undef CHAR
#endif
typedef char CHAR;

#ifdef UCHAR
#undef UCHAR
#endif
typedef unsigned char UCHAR;

#ifdef SHORT
#undef SHORT
#endif
typedef short SHORT;

#ifdef UINT16
#undef UINT16
#endif
typedef unsigned short UINT16;

#ifdef LONG
#undef LONG
#endif
typedef long LONG;

#ifdef ULONG
#undef ULONG
#endif
typedef unsigned long ULONG;

#ifdef ULONG32
#undef ULONG32
#endif
typedef unsigned long ULONG32;

#ifdef INT32
#undef INT32
#endif
typedef LONG INT32;

#ifdef UINT32
#undef UINT32
#endif
typedef ULONG UINT32;

#ifdef __cplusplus
	#if __cplusplus
	}
	#endif
#endif/*__cplusplus*/
#endif