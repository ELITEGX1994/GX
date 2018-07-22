/******************************************************************************
    @author hongyun 
    @since 2016/12/01

******************************************************************************/
#ifndef _MSRP_COMMON_H_HEADER
#define _MSRP_COMMON_H_HEADER
#include <stdint.h>
#include "mrp_common.h"

// Table 10-2 MRP EtherType values
#define HW_MSRP_ETHERTYP	0x22EA

// Defined in 35.2.2.3
#define MSRP_PROT_VER	0x00

// Defined in 35.2.2.94/35.2.1.4 i/Table 9-2
#define MSRP_SR_PVID_DEFAULT	2

// Table 35-6 Reservation failure codes.
typedef enum msrp_talk_failure_code{
    MSRP_FAIL_INSUFFICIENT_BANDWIDTH = 1,
    MSRP_FAIL_INSUFFICIENT_BRIDGE_RESOURCES,
    MSRP_FAIL_INSUFFICIENT_BANDWIDTH_TRAFFIC_CLASS,
    MSRP_FAIL_ID_IS_BUSY,
    MSRP_FAIL_DSTADDR_BUSY,
    MSRP_FAIL_PREEMPTED_BY_HIGHER_RANK,
    MSRP_FAIL_LATENCY_CHNG,
    MSRP_FAIL_EGRESS_PORT_NOT_AVB,
    MSRP_FAIL_DSTADDR_HASHTABLE_FULL,
    MSRP_FAIL_OUT_OF_MSRP_RESOURCE,
    MSRP_FAIL_OUT_OF_MMRP_RESOURCE,
    MSRP_FAIL_OUT_OF_DSTADDR_RESOURCES,
    MSRP_FAIL_PRIORITY_NOT_SR,
    MSRP_FAIL_MAX_FRAME_SIZE_TOO_LARGE,
    MSRP_FAIL_FANIN_EXCEED,
    MSRP_FAIL_STREAM_CHANGE,
    MSRP_FAIL_VLAN_BLOCKED,
    MSRP_FAIL_VLAN_DISABLED,
    MSRP_FAIL_SR_PRIO_MISMATCH,
    MSRP_FAIL_FAILURE_CODE_MAX
} MSRP_FAIL_FAILURE_CODE_E;


// Defined in 35.2.2.9.2 & Table35-7 
typedef enum msrp_sr_class_id{
    MSRP_SR_CLASS_ID_B = 5,
    MSRP_SR_CLASS_ID_A = 6,
    MSRP_SR_CLASS_ID_MAX
}MSRP_SR_CLASS_ID_E;


// Defined in 35.2.2.9.3 & Table6-5
typedef enum msrp_sr_class_prio{
    MSRP_SR_CLASS_PRIO_B = 2,
    MSRP_SR_CLASS_PRIO_A = 3,
    MSRP_SR_CLASS_PRIO_MAX
}MSRP_SR_CLASS_PRIO_E;

// 35.2.1.3 declaretionType
typedef enum msrp_declare_t{
    MSRP_DECLARE_TYPE_ADVERTISE = 0,
    MSRP_DECLARE_TYPE_FAILED,
    MSRP_DECLARE_TYPE_ASKING_FAILED,
    MSRP_DECLARE_TYPE_READY,
    MSRP_DECLARE_TYPE_READY_FAILED
} MSRP_DECLARE_TYPE_E;

// Table 35-3--FourPackedEvent Values
typedef enum msrp_4packet_event{
    MSRP_4PACKET_EVENT_IGNORE = 0,
    MSRP_4PACKET_EVENT_ASKING_FAILED,
    MSRP_4PACKET_EVENT_READY,
    MSRP_4PACKET_EVENT_READY_FAILED,
    MSRP_4PACKET_EVENT_MAX
} MSRP_4PACKET_EVENT_E;


// Table 35-1--Attribute Type Values
typedef enum msrp_attr_t{
    MSRP_ATTR_TYPE_TALKER_ADVERTISE = 1,
    MSRP_ATTR_TYPE_TALKER_FAILED,
    MSRP_ATTR_TYPE_LISTENER,
    MSRP_ATTR_TYPE_DOMAIN,
    MSRP_ATTR_TYPE_MAX
} MSRP_ATTR_TYPE_E;

// Table 35-2 AttributeLength values
typedef enum msrp_attr_length {
    MSRP_ATTR_LEN_TALKER_ADVERTISE = 25,
    MSRP_ATTR_LEN_TALKER_FAILED = 34,
    MSRP_ATTR_LEN_LISTENER = 8,
    MSRP_ATTR_LEN_DOMAIN = 4,
} MSRP_ATTR_LEN_E;

// declare or register
typedef enum msrp_operation{
    MSRP_OPERATION_REGISTER = 0,
    MSRP_OPERATION_DECLARE = 1,
    MSRP_OPERATION_MAX
}MSRP_OPERATION_E;
 
// 35.2.2.8.1 structure definition and 
// Figure 35-2--Format of the component of the reservation First fields.
typedef struct msrp_talker_failed_attr_first_value {
  uint8_t StreamId[8];
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
} msrp_talker_failed_first_value_t;

//35.2.2.9 MSRP FirstValue definitions(Domain discovery)
typedef struct msrp_domain_attribute_first_value {
  uint8_t SRclassID;
  uint8_t SRclassPriority;
  uint8_t SRclassVID[2];
} msrp_domain_first_value_t;

struct msrp_attr {
	struct msrp_attr *prev;
	struct msrp_attr *next;
	uint32_t msrp_attr_type;
	union {
		msrp_talker_failed_first_value_t talk_listen;
		msrp_domain_first_value_t domain;
	} attribute;
	uint32_t substate;	/*for listener events */
	uint32_t operation;	/* DECLARE or REGISTER */
	mrp_appl_attr_t applicant;
	mrp_rsg_attr_t registrar;
};

/*struct msrp_database {
	struct mrp_database mrp_db;
	struct msrp_attribute *attrib_list;
	int send_empty_LeaveAll_flag;
	struct eui64set interesting_stream_ids;
	int enable_pruning_of_uninteresting_ids;
};*/

#endif