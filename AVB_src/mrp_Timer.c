typedef VOID(*MRP_TIMER_CALLBACK)(VOID *pArg);
typedef struct tagMrpSrcTimerInfo{
	UINT32 uiSrcTimerBaseInterval;
	MRP_TIMER_CALLBACK pfJoinTimerIntervalCallBack;
	MRP_TIMER_CALLBACK pfLeaveTimerIntervalCallBack;
	MRP_TIMER_CALLBACK pfLeaveAlltimerintervalCallBack;
	MRP_TIMER_CALLBACK pfPeriodicTimerIntervalCallBack;
}MRP_SRC_TIMER_INFO;
UINT32 MRP_TIMER_USLEEP(UINT32*time)
{
	usleep(time);
}
VOID MRP_PAT_JoinTimerIntervalCallBack(UINT32 AppType,MRP_PAT_S* pstMrpPat)
{
	pstMrpPat->uiJoinTimeCountDown--;
	if(pstMrpPat->uiJoinTimeCountDown==0)
	{
		//处理内容，未写
	}
}
VOID MRP_PAT_LeaveTimerIntervalCallBack(UINT32 AppType,MRP_PAT_S* pstMrpPat)
{
	for()
	{
		if(0==pstAttr->stFsmReg.uiLeaveTimeCountDown)
		{
			//触发leaveTimer！
			MRP_;//原文
		}
	}
}
VOID MRP_PAT_LeaveALLTimerIntervalCallBack(UINT32 AppType,MRP_PAT_S* pstMrpPat)
{
	pstMrpPat->stFsmLa.uiLATimeCountDown--;
	if(pstMrpPat->stFsmLa.uiLATimeCountDown==0)
	{
		//处理内容，未写
	}
}
VOID MRP_PAT_PeriodicTimerIntervalCallBack(UINT32 AppType,MRP_PAT_S* pstMrpPat)
{
	pstMrpPat->stFsmPrd.uiPeriodicTimeCountDown--;
	if(pstMrpPat->stFsmPrd.uiPeriodicTimeCountDown==0)
	{
		//处理内容，未写
	}
}
UINT32 MRP_PAT_PauseJoinTimerInterval(MRP_PAT_S* pstMrpPat){
}
UINT32 PAT_PauseLeaveALLTimerInterval(MRP_PAT_S* pstMrpPat){
}

UINT32 PAT_PausePeriodicTimerInterval(MRP_PAT_S* pstMrpPat){
}

UINT32 PAT_PauseLeaveTimerInterval(UINT32 uiAppType,UINT uiSubType,void *pstMrpAttr)
{
	if(uiAppType==MVRP_ETHTYPE){
		MVRP_MRPATTR_S *pstv=(MVRP_MRPATTR_S*)(pstMrpAttr);
	}
	else if(uiAppType==MSRP_ETHTYPE)
	{
		if(uiSubType==MSRP_DOMAIN_ATTR)
		{
			MSRP_DOMAINATTR_S *psts=(MSRP_DOMAINATTR_S *)(pstMrpAttr);
			pst->stFsmReg.uiLeaveTimeCountDown==;//后面没了
		}
		else if(uiSubType==MSRP_TALKER_ATTR||uiSubType==MSRP_TALKERFAILED_ATTR)
		{
			MSRP_TALKERATTR_S *psts=(MSRP_TALKERATTR_S *)(pstMrpAttr);
			pst->stFsmReg.uiLeaveTimerCountDown==;//后面没了
		}
		else if(uiSubType==MSRP_LISTENER_ATTR)
		{
			MSRP_LISTENERATTR_S *psts=(MSRP_LISTENERATTR_S *)(pstMrpAttr);
			psts->stFsmReg.uiLeaveTimeCountDown==;//+1
		}
		else
			//error
	}
	else
		//error
}
VOID MRP_PAT_JoinTimerStart(MRP_PAT_S *pstMrpPat)
{
}
VOID MRP_PAT_LeaveAllTimerStart(MRP_PAT_S *pstMrpPat)
{
}
VOID MRP_PAT_PeriodicTimerStart(MRP_PAT_S *pstMrpPat)
{
}
VOID MRP_PAT_LeaveTimerStart(UINT32 uiAppType，UINT32 uiSubType,void *pstMrpAttr)
{
}