/*created by gx 2017.03.03*/
#include "mrp_fsm.h"

UINT32 MRP_FSM_REG_Init(MRP_FSM_REG_S *pstFsmReg){
	if(pstFsmReg == NULL){
		return -1;
	}
	pstFsmReg->uiLeaveTimeCountDown = 0;
	pstFsmReg->ucLvTimerRunning = 0;
	pstFsmReg->ucCurState = MRP_STATE_REG_MT;
	pstFsmReg->ucHistoryNextIndex = 0;
	pstFsmReg->ucIsHistoryArrayFull = 0;

	return 0;
}


/*created by gx 2017.03.03*/
UINT32 MRP_FSM_PRD_Init( MRP_FSM_PRD_S *pstFsmPrd){
	if(pstFsmPrd == NULL){
		return -1;
	}

	pstFsmPrd->ucCurState = MRP_STATE_PRD_PASSIVE;
	pstFsmPrd->ucHistoryNextIndex = 0;
	pstFsmPrd->ucIsHistoryArrayFull =  0;

	return 0;
}

/*created by gx 2017.03.03*/
UINT32 MRP_FSM_LA_Init( MRP_FSM_LA_S *pstFsmLA){
	if(pstFsmLA == NULL){
		return -1;
	}
	pstFsmLA->ucCurState = MRP_STATE_LA_PASSIVE;
	pstFsmLA->ucLATimerRunning = 0;
	pstFsmLA->ucHistoryNextIndex = 0;
	pstFsmLA->ucIsHistoryArrayFull = 0;

	return 0;
}


/*created by gx 2017.03.03*/
UINT32 MRP_FSM_APPL_Init( MRP_FSM_APPL_S *pstFsmAppl){
	if(pstFsmAppl == NULL){
		return -1;
	}

	pstFsmAppl->ucCurState = MRP_STATE_APPL_VO;
	pstFsmAppl->ucTX = 0;
	pstFsmAppl->ucSndMsg = MRP_PKT_ATTR_EVT_MAX;
	pstFsmAppl->ucHistoryNextIndex = 0;
	pstFsmAppl->ucIsHistoryArrayFull = 0;

	return 0;
}