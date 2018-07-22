//applicant状态各名称
UCHAR* g_apucFsmApplStateName[MRP_STATE_APPL_MAX+1] = 
{
	"VO",
	"VP",
	"VN",
	"AN",
	"AA",
	"QA",
	"LA",
	"AO",
	"QO",
	"AP",
	"QP",
	"LO",
	"ERROR"
};

UCHAR g_apucFsmApplEvtName[MRP_EVT_APPL_MAX+1] = 
{
	"Begin!",
	"New!",
	"Join!",
	"Lv!",
	"rNew!",
	"rJoinIn!",
	"rIn!",
	"rJoinMt!",
	"rMt!",
	"rLv!",
	"rLA!",
	"Re-declare!",
	"periodic!",
	"tx!",
	"txLA!",
	"txLAF!",
	"ERROR"
};

UCHAR g_aucMrpFsmApplSendPAToSendEvt[MRP_PA_APPL_SJ_OPT+1][MRP_STATE_REG_MAX] = 
{
	/*   MRP_S_REG_IN                MRP_S_REG_MT                MRP_S_REG_LV*/
	/*MRP_PA_APPL_S,s*/
	{MRP_PKT_ATTR_EVT_IN,			MRP_PKT_ATTR_EVT_MT,		MRP_PKT_ATTR_EVT_MT},
	/*MRP_PKT_APPL_SN,sN*/
	{MRP_PKT_ATTR_EVT_NEW,		    MRP_PKT_ATTR_EVT_NEW,		MRP_PKT_ATTR_EVT_NEW},
	/*MRP_PKT_APPL_SN,sJ*/
	{MRP_PKT_ATTR_EVT_JOININ,		MRP_PKT_ATTR_EVT_JOINMT,	MRP_PKT_ATTR_EVT_JOINMT},
	/*MRP_PKT_APPL_SN,sL*/
	{MRP_PKT_ATTR_EVT_LV,			MRP_PKT_ATTR_EVT_LV,		MRP_PKT_ATTR_EVT_LV},
	/*MRP_PA_APPL_SJ_OPT,OPT的作用确认*/
	{MRP_PKT_ATTR_EVT_JOININ,		MRP_PKT_ATTR_EVT_JOINMT,	MRP_PKT_ATTR_EVT_JOINMT},
	/*MRP_PA_APPL_S_OPT*/
	{MRP_PKT_ATTR_EVT_IN,			MRP_PKT_ATTR_EVT_MT,		MRP_PKT_ATTR_EVT_MT},
};

//applicant状态机状态转换表
MRP_FSM_TBL_S g_astMrpFsmTblApplicant[MRP_EVT_APPL_MAX][MRP_STATE_APPL_MAX] = 
{
	/*表项结构示意
	//当前发生的事件
	{
		//当前状态A
		{下一个状态，需要进行的处理数组}，
		//当前状态B
		{下一个状态，需要进行的处理数组}，
		......
	},*/
	/*MRP_EVT_APPL_BEGIN*/
	{
		/*MRP_STATE_APPL_VO*/
		{MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
		/*MRP_STATE_APPL_VP*/
		{MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
		/*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	  	/*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_NEW*/
	{
	    /*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	    /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_JOIN*/
	{
		 /*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_AP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_QP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_LV*/
	{
		 /*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_LA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_LA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_LA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_LA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_AO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_QO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RNEW*/
	{
		 /*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RJOININ*/
	{
		 /*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_AO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_AP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_QO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_QP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RIN*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA内源中此项为MAX*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RJOINMT*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_AO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_AP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RMT*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_AO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_AP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_EVT_APPL_RLV*/
	/*MRP_EVT_APPL_RLA*/
	/*MRP_EVT_APPL_REDCLARE*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_VN,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_VP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_STATE_APPL_PERIODIC*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_AP,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_MAX,MRP_PA_APPL_MAX}},
	},
	/*MRP_STATE_APPL_TX*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_AN,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_SJ_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_SL,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_VO,{MRP_PA_APPL_S,MRP_PA_APPL_MAX}},
	},
	/*MRP_STATE_APPL_TXLA*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_S,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_AN,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	},
	/*MRP_STATE_APPL_TXLAF*/
	{
		/*MRP_STATE_APPL_VO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VP*/
	    {MRP_STATE_APPL_AA,{MRP_PA_APPL_S,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_VN*/
	    {MRP_STATE_APPL_AN,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AN*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SN,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AA*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QA*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LA*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QO*/
	    {MRP_STATE_APPL_LO,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_AP*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_QP*/
	    {MRP_STATE_APPL_QA,{MRP_PA_APPL_SJ,MRP_PA_APPL_MAX}},
	     /*MRP_STATE_APPL_LO*/
	    {MRP_STATE_APPL_MAX,{MRP_PA_APPL_S_OPT,MRP_PA_APPL_MAX}},
	},
	//下面有还有一部分没有拍到。。。
};