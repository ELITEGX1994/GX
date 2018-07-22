// mrp_fsm_register.h

typedef enum enumMrpStateReg{
    MRP_STATE_REG_IN,
    MRP_STATE_REG_MT,
    MRP_STATE_REG_LV,
    MRP_STATE_REG_MAX,
}MRP_STATE_REG_E;

typedef enum enumMrpEvtReg{
    MRP_EVT_REG_BEGIN,
    MRP_EVT_REG_RNEW,
    MRP_EVT_REG_RJOININ,
    MRP_EVT_REG_RJOINMT,
    MRP_EVT_REG_RLV,
    MRP_EVT_REG_RLA,
    MRP_EVT_REG_TXLA,
    MRP_EVT_REG_REDECLARE,
    MRP_EVT_REG_FLUSH,
    MRP_EVT_REG_LEAVETIMER,
    MRP_EVT_REG_MAX,
}MRP_EVT_REG_E;


typedef enum enumMrpPAReg{
    MRP_PA_REG_NEW,
    MRP_PA_REG_JOIN,
    MRP_PA_REG_LV,
    MRP_PA_REG_STARTLEAVETIMER,
    MRP_PA_REG_STOPLEAVETIMER,
    MRP_PA_REG_MAX,
}MRP_PA_REG_E;

