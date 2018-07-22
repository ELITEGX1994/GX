#define MSRP_DOMAIN_ATTR 1
#define MSRP_TALKER_ATTR 2
#define MSRP_TALKERFAILED_ATTR 3
#define MSRP_LISTENER_ATTR 4

//描述MRP具体属性的结构体
typedef struct tagMsrpAttribute
{
	MSRP_DOMAINATTR_S *stAttrDomainList;
	MSRP_TALKERATTR_S *stAttrTalkerList;
	MSRP_LISTENERATTR_S *stAttrListenerList;
}MSRP_MRPATTR_S;

//domain属性结构体
typedef struct tagMsrpDomainAttr
{
	UCHAR ucClassId;
	UCHAR UCClassPri;

	UINT16 ucSRPvid;//两个字节
	UCHAR icBoundaryPort;
	MRP_FSM_APPL_S stFsmAppl;
	MRP_FSM_REG_S stFsmReg;
	MSRP_DOMAINATTR_S *prev;
	MSRP_DOMAINATTR_S *next;
}MSRP_DOMAINATTR_S

//talker属性结构体，两种方案表示talker属性，一种是将具体的参数全部在该结构体表示
//第二种是只记录流ID，是否失败及定位信息，再定义全局变量专门保存每个streamid对应的各种参数
//第二种方法需要确认针对每一流id，参数是否固定
typedef struct tagMsrpTalkerAttr
{
	UCHAR ucStreamId[8];
	UCHAR ucDestMac[8];
	UINT16 UIVlanId;
	UINT16 uiMaxFrameSize;
	UINT16 uiMaxIntervalFrames;
	UCHAR ucPriorityAndRank;
	UINT32 uiAccumulateLatency;
	UCHAR ucIfTakerFailed;
	UCHAR ucBridgeId[8];
	UCHAR ucFailurecode;
	MRP_FSM_APPL_S stFsmAppl;
	MRP_FSM_REG_S stFsmReg;
	MSRP_TALKERATTR_S *prev；
	MSRP_TALKERATTR_S *next;
}MSRP_TALKERATTR_S;

//Listener属性结构体
typedef struct tagMsrpListenerAttr
{
	UCHAR ucStreamId[8];
	UCHAR ucListenerSubType;
	MRP_FSM_APPL_S stFsmAppl;
	MRP_FSM_REG_S stFsmReg;
	MSRP_LISTENERATTR_S *prev;
	MSRP_LISTENERATTR_S *next;
}MSRP_LISTENERATTR_S;
