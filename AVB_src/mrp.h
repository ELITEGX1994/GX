#define MVRP_ETHTYPE 0x88F5
#define MSRP_ETHTYPE 0x22EA

//MVRP 应用属性个数的统计
typedef struct tagMvrpAttrCount
{
	UINT32 uiVlanAttrCount;
}MRP_MVRP_ATTR_COUNT_S;

//MSRP 应用属性个数的统计
typedef struct tagMsrpAttrCount
{
	UINT32 uiTalkerAttrCount；
	UINT32 uiListenerAttrCount;
	UCHAR uiDomainAttrCount;
}MRP_MSRP_ATTR_COUNT_S;

//属性统计结构体，针对mvrp只统计vlan，对于msrp分别统计domain属性，talker属性，listener属性
typedef union tagMrpAttrCount
{
	MRP_MVRP_ATTR_COUNT_S stMvrpAttrCount;
	//MRP_MMRP_ATTR_COUNT_S stMmrpAttrCount;
	MRP_MSRP_ATTR_COUNT_S stMsrpAttrCount;
}MRP_ATTR_COUNT_U;

//定义attribute的联合体
typedef union tagMrpAttr
{
	MVRP_MRPATTR_S stMvrpAttr;
	MSRP_MRPATTR_S stMsrpAttr;
}MRP_ATTR_U;

//描述MRP参与者的结构体
typedef struct tagMrpParticipant
{
	UCHAR ucPortNo;
	UCHAR ucMrpEnable;

	MRP_TIMER_CFG_S stTimercfg;
	UINT32 uiJoinTimeCountDown;
	MRP_FSM_PRD_S stFsmPrd;
	MRP_FSM_LA_S stFsmLa;
	MRP_ATTR_U *unMrpAtt;
	MRP_PAT_S *pre;
	MRP_PAT_S *next;
}MRP_PAT_S;

//描述MRP应用的结构体
typedef struct tagMrpAppDesc
{
	UCHAR ucAppEthType[4];
	UCHAR ucMrpPatTotalCnt;//总共参与者
	UCHAR ucMrpPatActiveCnt;//正在使用的参与者，如果端口故障不使用，参与者插到队尾

	MRP_PAT_S *stMrpPat;

	//函数命名规范确认，其余函数开发过程中需要再添加
	VOID(*JOIN_INDICATION_FUN)();
	VOID(*LEAVE_INDICATION_FUN)();
	VOID(*JOIN_REQUEST_FUN)();
	VOID(*LEAVE_REQUEST_FUN)();

	VOID(*SEND_MRPDU_FUN)();
	VOID(*RECEIVE_MRPDU_FUN)();

	VOID(*ATTR_PROGAGATE_FUN)();
}MRP_APP_DESC_S;
/*end tagMrpAppDesc?*/
//在某个应用初始化的时候对状态改变时要执行的操作进行初始化
g_astMrpFsmPAtoFunc4LeaveAll_[0] = MRP_APP_DESC_S.JOIN_REQUEST_FUN;
 