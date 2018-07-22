#define MRP_PKT_MAC_ATTR_TYPE_PER_APP 4
#define MRP_MAC_LEN 6

#define MMRP_PKT_ATTR_MAC_LEN 6
#define MMRP_PKT_ATTR_SRQ_LEN 1

#define MVRP_PKT_ATTR_LEN 2

#define MSRP_PKT_ATTR_TALKER_ADVERTISE_LEN 0x19
#define MSRP_PKT_ATTR_TALKER_FAILED_LEN 0x22
#define MSRP_PKT_TALKER_LEN 8
#define MSRP_PKT_DOMAIN_LEN 4

typedef enum enumMrpPktAttrEvt{
    MRP_PKT_ATTR_EVT_NEW = 0,
    MRP_PKT_ATTR_EVT_JOININ,
    MRP_PKT_ATTR_EVT_IN,
    MRP_PKT_ATTR_EVT_JOINMT,
    MRP_PKT_ATTR_EVT_MT,
    MRP_PKT_ATTR_EVT_LV,
    MRP_PKT_ATTR_EVT_LVA,
    MRP_PKT_ATTR_EVT_MAX,   
}MRP_PKT_ATTR_EVT_E;


typedef enum enumMrpPktVecPackType{
    MRP_PKT_VEC_3PACK = 3,
    MRP_PKT_VEC_4PACK = 4,
    MRP_PKT_VEC_MAXPACKTYPE
}MRP_PKT_VEC_PACK_TYPE_E;

typedef enum enumMrpApplicationType{
    MRP_APP_MMRP,
    MRP_APP_MVRP,
    MRP_APP_MSRP,
    MRP_APP_MAX    
}MRP_APP_TYPE_E;


typedef enum enumMmrpAttrType{
    MMMRP_ATTR_TYPE_SERVICE_REQUIRMENT = 1,
    MMMRP_ATTR_TYPE_MAC,
    MMMRP_ATTR_TYPE_MAX    
}MMMRP_ATTR_TYPE_E;

#define MVRP_ATTR_TYPE_VID 1

typedef enum enumMsrpAttrType{
    MSRP_ATTR_TYPE_TALKER_ADVERTISE = 1,
    MSRP_ATTR_TYPE_TALKER_FAILED,    
    MSRP_ATTR_TYPE_LISTENER,     
    MSRP_ATTR_TYPE_DOMAIN,        
    MSRP_ATTR_TYPE_MAX,        
}MSRP_ATTR_TYPE_E;


typedef struct tagMrpAttributeInfo{
    UCHAR ucAppType;
    UCHAR ucInternalAttrTypt;
    UCHAR ucAttriLenght;
    UCHAR ucPackType;
}MRP_ATTRIBUTE_INFO_S;


typedef struct tagMrpAttrType{
    UCHAR ucInternalAttrTypt;
    UCHAR ucPackType;
    UCHAR ucIsAttrListLenUsed;
    UCHAR ucRsvd;
    UINT32 uiAttrLen;
}MRP_ATTR_TYPE_S;


MRP_ATTR_TYPE_S g_acMrpAttrTypeInfo[MRP_APP_MAX][MRP_PKT_MAC_ATTR_TYPE_PER_APP] = {
    // MMRP
    {
        {MMMRP_ATTR_TYPE_SERVICE_REQUIRMENT, MRP_PKT_VEC_3PACK, MMRP_FALSE, 0, MMRP_PKT_ATTR_SRQ_LEN},
        {MMMRP_ATTR_TYPE_MAC, MRP_PKT_VEC_3PACK, MMRP_FALSE, 0, MMRP_PKT_ATTR_MAC_LEN},
        {0,0,0,0,0},
        {0,0,0,0,0}
    },
    // mvrp
    {
        {MVRP_ATTR_TYPE_VID, MRP_PKT_VEC_3PACK, MVRP_FALSE, 0, MVRP_PKT_ATTR_LEN},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}                        
    },
    // msrp
    {
        {MSRP_ATTR_TYPE_TALKER_ADVERTISE,MRP_PKT_VEC_3PACK, MSRP_FALSE, 0, MSRP_PKT_ATTR_TALKER_ADVERTISE_LEN},
        {MSRP_ATTR_TYPE_TALKER_FAILED,MRP_PKT_VEC_3PACK, MSRP_FALSE, 0, MSRP_PKT_ATTR_TALKER_FAILED_LEN},
        {MSRP_ATTR_TYPE_LISTENER,MRP_PKT_VEC_4PACK, MSRP_FALSE, 0, MSRP_PKT_ATTR_LISTENER_LEN},        
        {MSRP_ATTR_TYPE_DOMAIN,MRP_PKT_VEC_3PACK, MSRP_FALSE, 0, MSRP_PKT_ATTR_DOMAIN_LEN}      
    }
};

UCHAR g_aucMrpDstMac[MRP_APP_MAX][MRP_MAC_LEN] = {
    {0x01, 0x80, 0xC2, 0x00, 0x00, 0x20}, //mmrp
    {0x01, 0x80, 0xC2, 0x00, 0x00, 0x21},  //mvrp
    {0x01, 0x80, 0xC2, 0x00, 0x00, 0x0E}    //msrp
};

UINT16 g_aucMrpEthType[MRP_APP_MAX] = {
    0x88F6, //mmrp
    0x88F5, //mvrp
    0x22EA  //msrp
};

UCHAR g_aucMrpProtocolVersion[MRP_APP_MAX] = {
    0, //mmrp
    0, //mvrp
    0  //msrp
};