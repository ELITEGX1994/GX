#define MRP_DEFAULT_JOINTIMER_MS 200
#define MRP_DEFAULT_LEAVETIMER_MS 10000
#define MRP_DEFAULT_LEAVEALLTIMER_MS 15000
#define MRP_DEFAULT_PERIODICTIMER_MS 1000
#define MRP_DEFAULT_PERIODICTIMER_EN MMRP_FALSE



typedef struct tagMrpTimerCfg
{
	UINT32 uiPeriodTimerEn;
	UINT32 uiPeriodTimerInMs;
	UINT32 uiJoinTimerInMs;
	UINT32 uiLeaveTimerInMs;
	UINT32 uiLeaveAllTimerInMs;
}MRP_TIMER_CFG_S;


