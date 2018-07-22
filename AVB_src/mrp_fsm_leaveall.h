// typedef UINT32 (*MRP_PA_LA_CALL)(void *p);  // 重定义函数指针类型

// UINT32 MRP_PA_StartLeaveAllTimer (MRP_FSM_LA_S* pstFsmLa);
// UINT32 MRP_PA_SendLA (void* p);
// MRP_PA_LA_CALL g_astMrpPALA[MRP_PA_LA_MAX] = {MRP_PA_StartLeaveAllTimer, MRP_PA_SendLA};

typedef enum enumMrpStateLA
{
	MRP_STATE_LA_ACTIVE,
	MRP_STATE_LA_PASSIVE,
	MRP_STATE_LA_MAX
}MRP_STATE_LA_E;

typedef enum enumMrpEvtLA
{
	MRP_EVT_LA_BEGIN,
	MRP_EVT_LA_TX,
	MRP_EVT_LA_RLA,
	MRP_EVT_LA_LEAVEALLTIMER,
	MRP_EVT_LA_MAX
}MRP_EVT_LA_E;

typedef enum enumMrpPALA
{
	MRP_PA_LA_STARTLEAVEALLTIMER,
	MRP_PA_LA_SLA,
	MRP_PA_LA_MAX
}MRP_PA_LA_E;