#include <stdlib.h>
#include "msrp.h"
#include "mrp.h"
#include "mrp_fsm.h"
#include "mrp_fsm_applicant.h"
#include "mrp_fsm_leave.h"
#include "mrp_fsm_register.h"
#include "mrp_fsm_periodic.h"
#include "packet.h"

void * msrpAttrMalloc(INT32 attrType);
void * msrpAttrLookUp(MSRP_MRPATTR_S* stMsrpAttr, INT32 attrType, void * attr);
INT32 msrpAttrAdd(MSRP_MRPATTR_S* stMsrpAttr, INT32 attrType, void * attr);
INT32 msrpAttrMerge(MSRP_MRPATTR_S* stMsrpAttr, INT32 attrType, void * attr);


INT32 msrpEvtProcLVA(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr);
INT32 msrpEvtProcPRD(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr);
INT32 msrpEvtProcREG(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr);
INT32 msrpEvtProcAPPL(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr);


// 注意调用该函数需要判断返回值是否具是NULL
void * msrpAttrMalloc(INT32 attrType){
    void* pAttr;

    // 注意此处是使用packet.h中的属性定义，而不是msrp.h中的定义（注意歧义）
    if(attrType < MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType >= MSRP_ATTR_TYPE_MAX){
        return NULL;
    }

    if(attrType == MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType == MSRP_ATTR_TYPE_TALKER_FAILED){
        pAttr = (void*)malloc(sizeof(MSRP_TALKERATTR_S));
    }else if(attrType == MSRP_ATTR_TYPE_LISTENER){
        pAttr = (void*)malloc(sizeof(MSRP_LISTENERATTR_S));        
    }else{
        pAttr = (void*)malloc(sizeof(MSRP_DOMAINATTR_S));                
    }
    // 初始化APPL状态机和REG状态机,待补充
    return pAttr;
}




// 测试时需要注意，是否缺少强制类型转换
void * msrpAttrLookUp(MSRP_MRPATTR_S* stMsrpAttr, INT32 attrType, void * attr){
    if(stMsrpAttr == NULL || attr == NULL){
        return NULL;
    }

    if(attrType < MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType >= MSRP_ATTR_TYPE_MAX){
        return NULL;
    }

    void* pAttr;
    INT32 cmp;
    if(attrType == MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType == MSRP_ATTR_TYPE_TALKER_FAILED){
        // 遍历stMsrpAttr中的taker链表寻找属性，依据StreamID
        pAttr = stMsrpAttr->stAttrTalkerList;
        while(pAttr != NULL){
            cmp = memcmp((MSRP_TALKERATTR_S)pAttr->ucStreamId, (MSRP_TALKERATTR_S)attr->ucStreamId, 8);
            if(cmp == 0){
                return pAttr;
            }
            pAttr = pAttr->next;
        }
    }else if(attrType == MSRP_ATTR_TYPE_LISTENER){
        // 遍历stMsrpAttr中的Listener链表寻找属性，依据StreamID
        pAttr = stMsrpAttr->stAttrListenerList;
        while(pAttr != NULL){
            cmp = memcmp((MSRP_LISTENERATTR_S)pAttr->ucStreamId, (MSRP_LISTENERATTR_S)attr->ucStreamId, 8);
            if(cmp == 0){
                return pAttr;
            }
            pAttr = pAttr->next;
        }
    }else{
        // 遍历stMsrpAttr中的Domain链表寻找属性，依据ClassID
        pAttr = stMsrpAttr->stAttrDomainList;
        while(pAttr != NULL){
            if((MSRP_DOMAINATTR_S)pAttr-> ucClassId == (MSRP_DOMAINATTR_S)attr->ucClassId){
                return pAttr;
            }
            pAttr = pAttr->next;
        }
    }
    return NULL;
}

// 按照StreamID或ClassID升序添加属性
// 注意：TalkerAdvertise和TalkerFailed是放在一起，那么如何进行升序排列呢?大腿需要注意
INT32 msrpAttrAdd(MSRP_MRPATTR_S* stMsrpAttr, INT32 attrType, void * attr){
    if(stMsrpAttr == NULL || attr == NULL){
        return NULL;
    }

    if(attrType < MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType >= MSRP_ATTR_TYPE_MAX){
        return NULL;
    }

    void* pAttr;
    if(attrType == MSRP_ATTR_TYPE_TALKER_ADVERTISE || attrType == MSRP_ATTR_TYPE_TALKER_FAILED){

    }else if(attrType == MSRP_ATTR_TYPE_LISTENER){

    }else{

    }   
}


// 处理该event事件对LVA状态机的影响
INT32 msrpEvtProcLVA(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr){
    UCHAR fsmEvt;
    UCHAR ucCurState;    
    UCHAR ucNextState;
    UCHAR ucHistoryNextIndex;
    UCHAR ucIsHistoryArrayFull;        
    MRP_FSM_TBL_S stMrpFsmTbl;
    void * pAttr;
    
    if(event < MRP_EVT_BEGIN || event > MRP_EVT_MAX){
        return -1;
    }

    fsmEvt = g_aucMrpEvtToFsmEvt[event][MRP_FSM_LA];
    if(fsmEvt >= MRP_EVT_LA_BEGIN && fsmEvt < MRP_EVT_LA_MAX){
        ucCurState = stMrpAppDesc->stMrpPat->stFsmLa->ucCurState;
        stMrpFsmTbl = g_astMrpFsmTblLeaveAll[fsmEvt][ucCurState];
        if(stMrpFsmTbl->usNextState < MRP_STATE_LA_MAX){
            stMrpAppDesc->stMrpPat->stFsmLa->ucCurState = stMrpFsmTbl->usNextState;
            // 把当前状态放到历史状态中，更新当前状态
            ucIsHistoryArrayFull = stMrpAppDesc->stMrpPat->stFsmLa->ucIsHistoryArrayFull;
            ucHistoryNextIndex = stMrpAppDesc->stMrpPat->stFsmLa->ucHistoryNextIndex;
            if(ucIsHistoryArrayFull){
                ucHistoryNextIndex = 0;
            }
            stMrpAppDesc->stMrpPat->stFsmLa->ausHistoryStateEvt[ucHistoryNextIndex++] = ucCurState;
            stMrpAppDesc->stMrpPat->stFsmLa->ucHistoryNextIndex = ucHistoryNextIndex;
            if(ucHistoryNextIndex == MRP_HISTORY_EVT_MAX){
                stMrpAppDesc->stMrpPat->stFsmLa->ucIsHistoryArrayFull = 1;
            }
            // 事件函数处理
            // 待补充需要处理stMrpFsmTbl->aucAction[2]中的两个动作，
            // MRP_PA_LA_STARTLEAVEALLTIMER,
            // MRP_PA_LA_SLA,
        }
    }
}

// 处理该event事件对PRD状态机的影响
INT32 msrpEvtProcPRD(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr){
    UCHAR fsmEvt;
    UCHAR ucCurState;    
    UCHAR ucNextState;
    UCHAR ucHistoryNextIndex;
    UCHAR ucIsHistoryArrayFull;        
    MRP_FSM_TBL_S stMrpFsmTbl;
    void * pAttr;
    
    if(event < MRP_EVT_BEGIN || event > MRP_EVT_MAX){
        return -1;
    }

    fsmEvt = g_aucMrpEvtToFsmEvt[event][MRP_FSM_PRD];
    if(fsmEvt >= MRP_EVT_PRD_BEGIN && fsmEvt < MRP_EVT_PRD_MAX){
        ucCurState = stMrpAppDesc->stMrpPat->stFsmPrd->ucCurState;
        stMrpFsmTbl = g_astMrpFsmTblPeriodic[fsmEvt][ucCurState];
        if(stMrpFsmTbl->usNextState < MRP_STATE_PRD_MAX){
            stMrpAppDesc->stMrpPat->stFsmPrd->ucCurState = stMrpFsmTbl->usNextState;
            // 把当前状态放到历史状态中，更新当前状态
            ucIsHistoryArrayFull = stMrpAppDesc->stMrpPat->stFsmPrd->ucIsHistoryArrayFull;
            ucHistoryNextIndex = stMrpAppDesc->stMrpPat->stFsmPrd->ucHistoryNextIndex;
            if(ucIsHistoryArrayFull){
                ucHistoryNextIndex = 0;
            }
            stMrpAppDesc->stMrpPat->stFsmPrd->ausHistoryStateEvt[ucHistoryNextIndex++] = ucCurState;
            stMrpAppDesc->stMrpPat->stFsmPrd->ucHistoryNextIndex = ucHistoryNextIndex;
            if(ucHistoryNextIndex == MRP_HISTORY_EVT_MAX){
                stMrpAppDesc->stMrpPat->stFsmPrd->ucIsHistoryArrayFull = 1;
            }
            // 事件函数处理
            // 待补充需要处理stMrpFsmTbl->aucAction[2]中的两个动作，
            // MRP_PA_PRD_STARTPERIODICTIMER,
            // MRP_PA_PRD_PERIODIC,
        }
    }
}


// 处理该event事件对REG状态机的影响
INT32 msrpEvtProcREG(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr){
    UCHAR fsmEvt;
    UCHAR ucCurState;    
    UCHAR ucNextState;
    UCHAR ucHistoryNextIndex;
    UCHAR ucIsHistoryArrayFull;        
    MRP_FSM_TBL_S stMrpFsmTbl;
    void * pAttr;
    
    if(event < MRP_EVT_BEGIN || event > MRP_EVT_MAX){
        return -1;
    }
    // 如果该事件对APPL和REG带来影响的话，一定是对某一属性造成影响，所有要判断属性值
    if(attr == NULL){
        return 0;
    }
    // 数据库中寻找该属性
    pAttr = msrpAttrLookUp(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
    if(pAttr == NULL){
        msrpAttrAdd(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
        pAttr = attr;
    }else{
        msrpAttrMerge(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
        free(attr);
    }

    // 处理该event事件对REG状态机的影响
    fsmEvt = g_aucMrpEvtToFsmEvt[event][MRP_FSM_REG];
    if(fsmEvt >= MRP_EVT_REG_BEGIN && fsmEvt < MRP_EVT_REG_MAX){
        ucCurState = pAttr->stFsmReg->ucCurState;
        stMrpFsmTbl = g_astMrpFsmTblReg[fsmEvt][ucCurState];
        if(stMrpFsmTbl->usNextState < MRP_STATE_PRD_MAX){
            pAttr->stFsmReg->ucCurState = stMrpFsmTbl->usNextState;
            // 把当前状态放到历史状态中，更新当前状态
            ucIsHistoryArrayFull = pAttr->stFsmReg->ucIsHistoryArrayFull;
            ucHistoryNextIndex = pAttr->stFsmReg->ucHistoryNextIndex;
            if(ucIsHistoryArrayFull){
                ucHistoryNextIndex = 0;
            }
            pAttr->stFsmReg->ausHistoryStateEvt[ucHistoryNextIndex++] = ucCurState;
            pAttr->stFsmReg->ucHistoryNextIndex = ucHistoryNextIndex;
            if(ucHistoryNextIndex == MRP_HISTORY_EVT_MAX){
                pAttr->stFsmReg->ucIsHistoryArrayFull = 1;
            }
            // 事件函数处理
            // 待补充需要处理stMrpFsmTbl->aucAction[2]中的两个动作，
            // MRP_PA_REG_NEW,
            // MRP_PA_REG_JOIN,
            // MRP_PA_REG_LV,
            // MRP_PA_REG_STARTLEAVETIMER,
            // MRP_PA_REG_STOPLEAVETIMER,
            // MRP_PA_REG_MAX,
        }
    }
}

// 处理该event事件对APPL状态机的影响
INT32 msrpEvtProcAPPL(MRP_APP_DESC_S* stMrpAppDesc, INT32 event, INT32 attrType, void * attr){
    UCHAR fsmEvt;
    UCHAR ucCurState;    
    UCHAR ucNextState;
    UCHAR ucHistoryNextIndex;
    UCHAR ucIsHistoryArrayFull;        
    MRP_FSM_TBL_S stMrpFsmTbl;
    void * pAttr;
    
    if(event < MRP_EVT_BEGIN || event > MRP_EVT_MAX){
        return -1;
    }
    // 如果该事件对APPL和REG带来影响的话，一定是对某一属性造成影响，所有要判断属性值
    if(attr == NULL){
        return 0;
    }
    // 数据库中寻找该属性
    pAttr = msrpAttrLookUp(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
    if(pAttr == NULL){
        msrpAttrAdd(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
        pAttr = attr;
    }else{
        msrpAttrMerge(&(stMrpAppDesc->stMrpPat->unMrpAtt->stMsrpAttr), attrType, attr);
        free(attr);
    }
    // 处理该event事件对APPL状态机的影响
    fsmEvt = g_aucMrpEvtToFsmEvt[event][MRP_FSM_APPL];    
    if(fsmEvt >= MRP_EVT_APPL_BEGIN && fsmEvt < MRP_EVT_APPL_MAX){
        ucCurState = pAttr->stFsmAppl->ucCurState;
        stMrpFsmTbl = g_astMrpFsmTblApplicant[fsmEvt][ucCurState];
        if(stMrpFsmTbl->usNextState < MRP_STATE_APPL_MAX){
            pAttr->stFsmAppl->ucCurState = stMrpFsmTbl->usNextState;
            // 把当前状态放到历史状态中，更新当前状态
            ucIsHistoryArrayFull = pAttr->stFsmAppl->ucIsHistoryArrayFull;
            ucHistoryNextIndex = pAttr->stFsmAppl->ucHistoryNextIndex;
            if(ucIsHistoryArrayFull){
                ucHistoryNextIndex = 0;
            }
            pAttr->stFsmAppl->ausHistoryStateEvt[ucHistoryNextIndex++] = ucCurState;
            pAttr->stFsmAppl->ucHistoryNextIndex = ucHistoryNextIndex;
            if(ucHistoryNextIndex == MRP_HISTORY_EVT_MAX){
                pAttr->stFsmAppl->ucIsHistoryArrayFull = 1;
            }
            // 事件函数处理
            // 待补充需要处理stMrpFsmTbl->aucAction[2]中的两个动作，
            // MRP_PA_APPL_S,
            // MRP_PA_APPL_SN,
            // MRP_PA_APPL_SJ,
            // MRP_PA_APPL_SL,
            // MRP_PA_APPL_SJ_OPT,
            // MRP_PA_APPL_S_OPT,
            // //MRP_PA_APPL_REQOPPOPORTUNITY,
            // MRP_PA_APPL_MAX
        }
    }
}

