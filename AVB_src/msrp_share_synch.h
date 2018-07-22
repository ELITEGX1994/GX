#ifndef _MSRP_SHARE_SYNCH_H_HEADER
#define _MSRP_SHARE_SYNCH_H_HEADER

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdint.h>

#define REGISTER_STREAM_REQUEST 0
#define DEREGISTER_STREAM_REQUEST 1
#define REPORT_TALKER_STATUS 2

#define REGISTER_ATTACH_REQUEST 3
#define DEREGISTER_ATTACH_REQUEST 4
#define REPORT_LISTENER_STATUS 5

#define REGISTER_DOMAIN_REQUEST 6
#define DEREGISTER_DOMAIN_REQUEST 7
#define REPORT_DOMAIN_STATUS 8


#define REGISTER_STREAM_INDICATION 9
#define DEREGISTER_STREAM_INDICATION 10

#define REGISTER_ATTACH_INDICATION 11
#define DEREGISTER_ATTACH_INDICATION 12

#define REGISTER_DOMAIN_INDICATION 13
#define DEREGISTER_DOMAIN_INDICATION 14

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
#else
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

/*35.2.3 page 1415-1419*/
typedef struct talker_listener_primitives_t {
  uint8_t StreamId[8];
  uint8_t DeclarationType;
  struct {
      uint8_t DestMacAddr[6];
      uint16_t VlanID;
  } DataFrameParameters;
  struct {
      uint16_t MaxFrameSize;
      uint16_t MaxIntervalFrames;
  } TSpec;
  uint8_t PriorityAndRank;
  unsigned AccumulatedLatency;
  struct {
		uint8_t FailureBridgeId[8];
		uint8_t FailureCode;
	} FailureInformation;
} talker_listener_t;

typedef struct domain_primitives_t {
  uint8_t SRclassID;
  uint8_t SRclassPriority;
  uint8_t SRclassVID[2];
} domain_t;


struct share_memory {
	uint8_t cmd_t; // domain or talk_listen
	union {
		talker_listener_t talk_listen;
		domain_t domain;
	} attribute;
};

#define SHM_SIZE (sizeof(struct share_memory))
#define SHM_MODE 0666
#define SEM_MODE 0666

void sigSem(int semSetId, int semNum);
void waitSem(int semSetId, int semNum);

#endif
