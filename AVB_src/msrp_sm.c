#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "msrp_sm.h"
#include "msrp_common.h"


static struct msrp_attr* msrp_attr_malloc();
static int msrp_talk_listen_to_attr_memcpy(char * src, char* dst);
static int msrp_domain_to_attr_memcpy(char* dst, char * src);
static int msrp_attr_to_domain_memcpy(char* dst, char * src);

static int mrp_proc_req_prmt(int attr_type, char * pAttr_value, int event);


void msrp_consume(struct share_memory * shared);
static void msg_request_dispatcher(struct share_memory* shared);
void msrp_producer(int mrp_notify, struct msrp_attr * pAttr, struct share_memory * shared);
static void msg_indication_dispatcher(int mrp_notify, struct msrp_attr * pAttr, struct share_memory* shared);


// 35.2.3 provision and suport of stream registration service
// talker/listener/domain primitives 
static int register_stream_request(talker_listener_t * talk_listen);
static int deregister_stream_request(talker_listener_t * talk_listen);
//static int report_talker_status(talker_listener_t * talk_listen);

static int register_attach_request(talker_listener_t * talk_listen);
static int deregister_attach_request(talker_listener_t * talk_listen);
//static int report_listener_status(talker_listener_t * talk_listen);

static int register_domain_request(domain_t* domain);
static int deregister_domain_request(domain_t* domain);
//static int report_domain_status(domain_t* domain);


static int register_stream_indication(talker_listener_t * talk_listen, struct msrp_attr * pAttr);
static int deregister_stream_indication(talker_listener_t * talk_listen, struct msrp_attr * pAttr);

static int register_attach_indication(talker_listener_t * talk_listen, struct msrp_attr * pAttr);
static int deregister_attach_indication(talker_listener_t * talk_listen, struct msrp_attr * pAttr);

static int register_domain_indication(domain_t* domain, struct msrp_attr * pAttr);
static int deregister_domain_indication(domain_t* domain, struct msrp_attr * pAttr);



/******************************************************************************
    @author:hongyun 
    @detail:malloc and init for struct msrp_attr*
    @return:success struct msrp_attr*, error NULL
    @since 2017/1/12
    @type:private
******************************************************************************/
static struct msrp_attr* msrp_attr_malloc(){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    struct msrp_attr * attr;
    
    attr = (struct msrp_attr*)malloc(sizeof(struct msrp_attr));
    if(attr == NULL){
        return NULL;
    }

    memset(attr, 0, sizeof(struct msrp_attr));
    attr->applicant.mrp_appl_state = MRP_VO_STATE;
	attr->applicant.tx = 0;
	attr->applicant.sndmsg = MRP_SND_NULL;
	attr->applicant.encode = MRP_ENCODE_OPTIONAL;

    attr->registrar.mrp_rsg_state = MRP_MT_STATE;
	attr->registrar.notify = MRP_NOTIFY_NONE;

    return attr;
}


/******************************************************************************
    @author:hongyun 
    @detail:把src指向的内存中pAttr的数据，复制到dst指向的domain中去，; 
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/16
    @type:private
******************************************************************************/
static int msrp_attr_to_domain_memcpy(char* dst, char * src){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(src == NULL || dst == NULL){
        return MRP_ERROR;
    }
    domain_t * pDomain;
    struct msrp_attr * pAttr;
    
    pAttr = (struct msrp_attr *)src;
    pDomain = (domain_t*)dst;

    pDomain->SRclassID = pAttr->attribute.domain.SRclassID;
    pDomain->SRclassPriority = pAttr->attribute.domain.SRclassPriority;
    memcpy(pDomain->SRclassVID, pAttr->attribute.domain.SRclassVID, 2);

    return MRP_OK;
}


/******************************************************************************
    @author:hongyun 
    @detail:domain to attribute memory copy; 
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/1/12
    @type:private
******************************************************************************/
static int msrp_domain_to_attr_memcpy(char* dst, char * src){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(src == NULL || dst == NULL){
        return MRP_ERROR;
    }

    domain_t * pDomain;
    struct msrp_attr * pAttr;
    
    pAttr = (struct msrp_attr *)dst;
    pDomain = (domain_t*)src;
    
    pAttr->operation = MSRP_OPERATION_DECLARE;
    pAttr->msrp_attr_type = MSRP_ATTR_TYPE_DOMAIN;
    pAttr->attribute.domain.SRclassID = pDomain->SRclassID;
    pAttr->attribute.domain.SRclassPriority = pDomain->SRclassPriority;
    memcpy(pAttr->attribute.domain.SRclassVID, pDomain->SRclassVID, 2);

    return MRP_OK;
}


/******************************************************************************
    @author:hongyun 
    @detail:把src指向的pAattr复制到dst指向的talk_listen中，是类型紧耦合的
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/1/12
    @type:private
******************************************************************************/
static int msrp_attr_to_talk_listen_memcpy(char* dst, char * src){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(src == NULL || dst == NULL){
        return MRP_ERROR;
    }

    talker_listener_t * pTalker_listener;
    struct msrp_attr * pAttr;
    
    pAttr = (struct msrp_attr *)src;
    pTalker_listener = (talker_listener_t *)dst;

    memcpy(pTalker_listener->StreamId, pAttr->attribute.talk_listen.StreamId, 8);
    memcpy(pTalker_listener->DataFrameParameters.DestMacAddr, pAttr->attribute.talk_listen.DataFrameParameters.DestMacAddr, 6);
    memcpy(pTalker_listener->DataFrameParameters.VlanID, pAttr->attribute.talk_listen.DataFrameParameters.VlanID, 2);
    memcpy(pTalker_listener->TSpec.MaxFrameSize, pAttr->attribute.talk_listen.TSpec.MaxFrameSize, 2);
    memcpy(pTalker_listener->TSpec.MaxIntervalFrames, pAttr->attribute.talk_listen.TSpec.MaxIntervalFrames, 2);
    memcpy(pTalker_listener->TSpec.MaxIntervalFrames, pAttr->attribute.talk_listen.TSpec.MaxIntervalFrames, 2);
    pTalker_listener->PriorityAndRank = pAttr->attribute.talk_listen.PriorityAndRank;
     pTalker_listener->AccumulatedLatency = pAttr->attribute.talk_listen.AccumulatedLatency;
    
    if(pAttr->msrp_attr_type == MSRP_ATTR_TYPE_TALKER_ADVERTISE){
        pTalker_listener->DeclarationType == MSRP_DECLARE_TYPE_ADVERTISE;
    }else{
        memcpy(pTalker_listener->FailureInformation.FailureBridgeId, pAttr->attribute.talk_listen.FailureInformation.FailureBridgeId, 8);
        memcpy(pTalker_listener->FailureInformation.FailureCode, pAttr->attribute.talk_listen.FailureInformation.FailureCode, 1);
        pTalker_listener->DeclarationType == MSRP_DECLARE_TYPE_FAILED;
    }
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun 
    @detail:talker listener to attribute memory copy; 
            把src指向的talk_listen复制到attr_t中，是类型紧耦合的
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/1/12
    @type:private
******************************************************************************/
static int msrp_talk_listen_to_attr_memcpy(char* dst, char * src){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(src == NULL || dst == NULL){
        return MRP_ERROR;
    }

    uint8_t dclrType;
    talker_listener_t * pTalker_listener;
    struct msrp_attr * pAttr;
    
    pAttr = (struct msrp_attr *)dst;
    pTalker_listener = (talker_listener_t *)src;
    dclrType = pTalker_listener->DeclarationType;

    pAttr->operation = MSRP_OPERATION_DECLARE;
    memcpy(pAttr->attribute.talk_listen.StreamId, pTalker_listener->StreamId, 8);
    memcpy(pAttr->attribute.talk_listen.DataFrameParameters.DestMacAddr, pTalker_listener->DataFrameParameters.DestMacAddr, 6);
    memcpy(pAttr->attribute.talk_listen.DataFrameParameters.VlanID, pTalker_listener->DataFrameParameters.VlanID, 2);
    memcpy(pAttr->attribute.talk_listen.TSpec.MaxFrameSize, pTalker_listener->TSpec.MaxFrameSize, 2);
    memcpy(pAttr->attribute.talk_listen.TSpec.MaxIntervalFrames, pTalker_listener->TSpec.MaxIntervalFrames, 2);
    memcpy(pAttr->attribute.talk_listen.TSpec.MaxIntervalFrames, pTalker_listener->TSpec.MaxIntervalFrames, 2);
    pAttr->attribute.talk_listen.PriorityAndRank = pTalker_listener->PriorityAndRank;
    pAttr->attribute.talk_listen.AccumulatedLatency =  pTalker_listener->AccumulatedLatency;
    
    if(dclrType == MSRP_DECLARE_TYPE_ADVERTISE){
        pAttr->msrp_attr_type = MSRP_ATTR_TYPE_TALKER_ADVERTISE;
    }else{
        memcpy(pAttr->attribute.talk_listen.FailureInformation.FailureBridgeId, pTalker_listener->FailureInformation.FailureBridgeId, 8);
        memcpy(pAttr->attribute.talk_listen.FailureInformation.FailureCode, pTalker_listener->FailureInformation.FailureCode, 1);
        pAttr->msrp_attr_type = MSRP_ATTR_TYPE_TALKER_FAILED;
    }
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun 
    @detail:process all event through calling fsm API; 
            通过调用FSM API处理所有接收到的事件（需要用到华为的FSM API）；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/1/12
    @type:private
******************************************************************************/
static int mrp_proc_req_prmt(int attr_type, char * pAttr_value, int event){
    printf("mrp_proc_req_prmt needs huawei API %d %d %s %d",attr_type,event,__FILE__,__LINE__);
}

/******************************************************************************
    @author:hongyun 
    @detail:是消费者使用的函数，通过调用分发函数static void msg_request_dispatcher(struct share_memory* shared)，
            实现根据talker或者listener传递过来的不同的消息类型调用不同的处理方法。
    @return:void
    @since 2017/2/07
    @type:public
******************************************************************************/
void msrp_consume(struct share_memory * shared){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    msg_request_dispatcher(shared);    
}


/******************************************************************************
    @author:hongyun 
    @detail:message dispatcher accordin to share_memory->cmd_t
            分发函数：根据不同的消息类型，调用不同的处理函数
    @return:void
    @since 2017/2/7
    @type:private
******************************************************************************/
// message dispatcher accordin to share_memory->cmd_t
static void msg_request_dispatcher(struct share_memory* shared){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    switch(shared->cmd_t) {
        case REGISTER_STREAM_REQUEST:
            register_stream_request(&(shared->attribute.talk_listen));
            break;
        case DEREGISTER_STREAM_REQUEST:
            deregister_stream_request(&(shared->attribute.talk_listen));
            break;
        // case REPORT_TALKER_STATUS:
        //     report_talker_status(&(shared->attribute.talk_listen));
        //     break;
        case REGISTER_ATTACH_REQUEST:
            register_attach_request(&(shared->attribute.talk_listen));
            break;
        case DEREGISTER_ATTACH_REQUEST:
            deregister_attach_request(&(shared->attribute.talk_listen));
            break;
        // case REPORT_LISTENER_STATUS:
        //     report_listener_status(&(shared->attribute.talk_listen));
        //     break;
        case REGISTER_DOMAIN_REQUEST:
            register_domain_request(&(shared->attribute.domain));
            break;
        case DEREGISTER_DOMAIN_REQUEST:
            deregister_domain_request(&(shared->attribute.domain));
            break;
        // case REPORT_DOMAIN_STATUS:
        //     report_domain_status(&(shared->attribute.domain));
        //     break;
        default:
#ifdef MRP_DEBUG
            printf("What' wrong? %s,%d\n\n",__FILE__,__LINE__);
#endif
            break;
	}
}

/******************************************************************************
    @author:hongyun 
    @detail:调用了mrp_proc_req_prmt函数，对REGISTER_STREAM_REQUEST原语处理
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:此处调用了msrp_attr_malloc（）申请了内存，但是没有free
******************************************************************************/
static int register_stream_request(talker_listener_t * pTalk_listen){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(pTalk_listen == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int rc = 0;
    int dclrType = pTalk_listen->DeclarationType;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    if(MSRP_DECLARE_TYPE_ADVERTISE == dclrType || MSRP_DECLARE_TYPE_FAILED == dclrType){

        rc = msrp_talk_listen_to_attr_memcpy((char*)pAttr, (char*)pTalk_listen);
        if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
            free(pAttr);
            return MRP_ERROR;
        }
        return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_JOIN);
    }
#ifdef MRP_DEBUG
    printf("debug %s,%d", __FILE__,__LINE__);
#endif
    return MRP_ERROR;
}


/******************************************************************************
    @author:hongyun 
    @detail:对DEREGISTER_STREAM_REQUEST 原语的处理
            Talker Application应该触发一个DEREGISTER_STREAM_REQUEST 原语给MSRP，移除Talker的advertivs声明，
            这样就移除了一个Talker的advertivs声明的声明；
            一接收到DEREGISTER_STREAM_REQUEST 原语，MSRP应该触发一个MAD_Leave.request原语，同时设置属性类为
            关联的StreamID。同时属性参数应该携带和以前注册请求相同的属性值。
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:state模块应该做的是：查找该StreamID，LV
******************************************************************************/
static int deregister_stream_request(talker_listener_t * pTalk_listen){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif

    if(pTalk_listen == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int dclrType = pTalk_listen->DeclarationType;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    memcpy(pAttr->attribute.talk_listen.StreamId, pTalk_listen->StreamId, 8);
    return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_LV);
}


/******************************************************************************
    @author:hongyun 
    @detail:DEREGISTER_STREAM_REQUEST process
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/08
    @type:private
    @note:malloc, not free
******************************************************************************/
// static int report_talker_status(talker_listener_t * pTalk_listen);



/******************************************************************************
    @author:hongyun 
    @detail:REGISTER_ATTACH_REQUEST原语处理(35.2.3.1.7 Page 1418)
            一个Listener Application应该触发一个REGISTER_ATTACH_REQUEST原语去发起向某一特定流的请求；
            一接收到REGISTER_ATTACH_REQUEST原语，MSRP应该触发一个类型为Talker的MAD_join.request；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:此处调用了msrp_attr_malloc（）申请了内存，但是没有free
******************************************************************************/
static int register_attach_request(talker_listener_t * pTalk_listen){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(pTalk_listen == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int dclrType = pTalk_listen->DeclarationType;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    pAttr->msrp_attr_type = MSRP_ATTR_TYPE_LISTENER;
    memcpy(pAttr->attribute.talk_listen.StreamId, pTalk_listen->StreamId, 8);
    pAttr->substate = dclrType;
    return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_JOIN);
}

/******************************************************************************
    @author:hongyun 
    @detail:DEREGISTER_ATTACH_REQUEST原语处理(35.2.3.1.7 Page 1418)
            一个Listener Application应该触发一个DEREGISTER_ATTACH_REQUEST原语去移除向某一特定流的请求；
            一接收到DEREGISTER_ATTACH_REQUEST原语，MSRP应该触发一个类型为Talker的MAD_Leave.request；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/13
    @type:private
    @note:此处调用了msrp_attr_malloc（）申请了内存，但是没有free
******************************************************************************/
static int deregister_attach_request(talker_listener_t * pTalk_listen){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif

    if(pTalk_listen == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int dclrType = pTalk_listen->DeclarationType;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }

    pAttr->msrp_attr_type = MSRP_ATTR_TYPE_LISTENER;
    memcpy(pAttr->attribute.talk_listen.StreamId, pTalk_listen->StreamId, 8);
    pAttr->substate = dclrType;
    return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_LV);
}



/******************************************************************************
    @author:hongyun
    @detail:处理domain_register_request函数(申请join一个domain)
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:此处调用了msrp_attr_malloc（）申请了内存，但是没有free
******************************************************************************/
static int register_domain_request(domain_t* pDomain){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif

    if(pDomain == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int rc = 0;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    rc = msrp_domain_to_attr_memcpy((char*)pAttr, (char*)pDomain);
    if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        free(pAttr);
        return MRP_ERROR;
    }
    return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_JOIN);
}

/******************************************************************************
    @author:hongyun
    @detail:处理domain_deregister_request函数(申请leave一个domain)
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:此处调用了msrp_attr_malloc（）申请了内存，但是没有free
******************************************************************************/

static int deregister_domain_request(domain_t* pDomain){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif

    if(pDomain == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int rc = 0;
    struct msrp_attr * pAttr;

    pAttr = msrp_attr_malloc();
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    rc = msrp_domain_to_attr_memcpy((char*)pAttr, (char*)pDomain);
    if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        free(pAttr);
        return MRP_ERROR;
    }
    return mrp_proc_req_prmt(pAttr->msrp_attr_type, pAttr, MRP_EVENT_LV);
}


/******************************************************************************
    @author:hongyun 
    @detail:报告domain的状态
            分发函数：根据不同的消息类型，调用不同的处理函数
    @return:void
    @since 2017/2/16
    @type:private
******************************************************************************/
// static int report_domain_status(domain_t* pDomain);


/******************************************************************************
    @author:hongyun 
    @detail:是生产者函数，通过调用分发函数static void msg_request_dispatcher(struct share_memory* shared)，
            实现根据talker或者listener传递过来的不同的消息类型调用不同的处理方法。
    @return:void
    @since 2017/2/07
    @type:public
******************************************************************************/
void msrp_producer(int mrp_notify, struct msrp_attr * pAttr, struct share_memory * shared){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    msg_indication_dispatcher(mrp_notify, pAttr, shared);
}

/******************************************************************************
    @author:hongyun 
    @detail:分发函数：根据不同的mrp_notify类型和属性类型，调用不同的indication函数去
    @return:void
    @since 2017/2/7
    @type:private
******************************************************************************/
// message dispatcher accordin to share_memory->cmd_t
static void msg_indication_dispatcher(int mrp_notify, struct msrp_attr * pAttr, struct share_memory* shared){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(pAttr == NULL) {
        return ;
    }
    switch(mrp_notify) {
        case MRP_NOTIFY_NEW:
        case MRP_NOTIFY_JOIN:
            switch(pAttr->msrp_attr_type){
                case MSRP_ATTR_TYPE_DOMAIN:
                    shared->cmd_t = REGISTER_DOMAIN_INDICATION;
                    register_domain_indication(&(shared->attribute.domain), pAttr);
                    break;
                case MSRP_ATTR_TYPE_LISTENER:
                    shared->cmd_t = REGISTER_ATTACH_INDICATION;
                    register_attach_indication(&(shared->attribute.talk_listen), pAttr);
                    break;
                case MSRP_ATTR_TYPE_TALKER_ADVERTISE:
                case MSRP_ATTR_TYPE_TALKER_FAILED:
                    shared->cmd_t = REGISTER_STREAM_INDICATION;
                    register_stream_indication(&(shared->attribute.talk_listen), pAttr);
                    break;
            }
        case MRP_NOTIFY_LV:
            switch(pAttr->msrp_attr_type){
                    case MSRP_ATTR_TYPE_DOMAIN:
                        shared->cmd_t = DEREGISTER_DOMAIN_INDICATION;
                        deregister_domain_indication(&(shared->attribute.domain), pAttr);
                        break;
                    case MSRP_ATTR_TYPE_LISTENER:
                        shared->cmd_t = DEREGISTER_ATTACH_INDICATION;
                        deregister_attach_indication(&(shared->attribute.talk_listen), pAttr);
                        break;
                    case MSRP_ATTR_TYPE_TALKER_ADVERTISE:
                    case MSRP_ATTR_TYPE_TALKER_FAILED:
                        shared->cmd_t = DEREGISTER_STREAM_INDICATION;
                        deregister_stream_indication(&(shared->attribute.talk_listen), pAttr);
                        break;
            }
            break;
        default:
#ifdef MRP_DEBUG
            printf("MRP_NOTIFY_NONE %s,%d\n\n",__FILE__,__LINE__);
#endif
            break;
	}
}


/******************************************************************************
    @author:hongyun
    @detail:处理REGISTER_STREAM.indication原语
            REGISTER_STREAM.indication原语通知Listener application，在连接的网络上收到相关Talker的流的advertised的时候；
            一接收到属性类型是talker advertise或者talker failed类型的MAD_Join.indication原语后，MSRP应用就会触发一
            个REGISTER_STREAM.indication原语，去通知listen application；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存中的数据，复制到talker_listener中去，
******************************************************************************/
static int register_stream_indication(talker_listener_t * pTalk_listen, struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    int rc = 0;
    rc = msrp_attr_to_talk_listen_memcpy((char*)pTalk_listen, (char*)pAttr);
    if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun
    @detail:处理DEREGISTER_STREAM.indication原语
            DEREGISTER_STREAM.indication原语通知Listener application,在连接的网络上收到相关的流的不再被advertised，
            一接收到属性类型是talker advertise或者talker failed类型的MAD_Leave.indication原语后，MSRP应用就会触发一
            个REGISTER_STREAM.indication原语，去通知listen application；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存中的数据，复制到talker_listener中去，
******************************************************************************/
static int deregister_stream_indication(talker_listener_t * pTalk_listen,struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    int rc = 0;
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    memcpy(pTalk_listen->StreamId, pAttr->attribute.talk_listen.StreamId, 8);
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun
    @detail:处理REGISTER_ATTACH.indication原语
            REGISTER_ATTACH.indication原语通知Talker application,相关的流正在被一个或多个Listener请求；
            一接收到属性类型是listener advertise类型的MAD_join.indication原语后，MSRP应用就会触发一
            个REGISTER_ATTACH.indication原语，去通知Talker application；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存中的数据，复制到talker_listener中去，
******************************************************************************/
static int register_attach_indication(talker_listener_t * pTalk_listen,struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    int rc = 0;
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    memcpy(pTalk_listen->StreamId, pAttr->attribute.talk_listen.StreamId, 8);
    pTalk_listen->DeclarationType = pAttr->substate;
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun
    @detail:处理DEREGISTER_ATTACH.indication原语(Page 1419)
            DEREGISTER_ATTACH.indication原语通知Talker application,相关的流不再被任何Listener请求；
            一接收到属性类型是listener advertise类型的MAD_Leave.indication原语后，MSRP应用就会触发一
            个DEREGISTER_ATTACH.indication原语，去通知Talker application；
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存中的数据，复制到talker_listener中去;
******************************************************************************/
static int deregister_attach_indication(talker_listener_t * talk_listen, struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    memcpy(talk_listen->StreamId, pAttr->attribute.talk_listen.StreamId, 8);
    return MRP_OK;
}


/******************************************************************************
    @author:hongyun
    @detail:处理domain_register_indication函数(申请join一个domain)
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存空间的值复制到domain中去
******************************************************************************/
static int register_domain_indication(domain_t* domain, struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
    int rc = 0;
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    rc = msrp_attr_to_domain_memcpy((char*)domain, (char*)pAttr);
    if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    return MRP_OK;
}

/******************************************************************************
    @author:hongyun
    @detail:处理domain_deregister_indication函数(申请join一个domain)
    @return:success == MRP_OK, error = MRP_ERROR
    @since 2017/2/15
    @type:private
    @note:把pAttr指向的内存空间的值复制到domain中去
******************************************************************************/
static int deregister_domain_indication(domain_t* domain, struct msrp_attr * pAttr){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif

    int rc = 0;
    if(pAttr == NULL){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    rc = msrp_attr_to_domain_memcpy((char*)domain, (char*)pAttr);
    if(MRP_ERROR == rc){
#ifdef MRP_DEBUG
    printf("debug %s,%d\n\n", __FILE__,__LINE__);
#endif
        return MRP_ERROR;
    }
    return MRP_OK;
}