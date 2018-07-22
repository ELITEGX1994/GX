#ifndef _MSRP_SM_H_HEADER
#define _MSRP_SM_H_HEADER

#include <stdint.h>
#include <sys/types.h>
#include "share_synch.h"


/* 
 * In fact, there is no talker_fail listener_failed, listener_asking_failed.
 * just listener reaady or talker advertise
 */


//message dispatcher
// void msg_dispatcher(struct share_memory* shared);
// msrp consumer
void msrp_consume(struct share_memory * shared);


// 35.2.3 provision and suport of stream registration service
// talker/listener/domain primitives 
// int register_stream_request(talker_listener_t * talk_listen);
// int deregister_stream_request(talker_listener_t * talk_listen);
// int report_talker_status(talker_listener_t * talk_listen);

// int register_attach_request(talker_listener_t * talk_listen);
// int deregister_attach_request(talker_listener_t * talk_listen);
// int report_listener_status(talker_listener_t * talk_listen);

// int register_domain_request(domain_t* domain);
// int deregister_domain_request(domain_t* domain);
// int report_domain_status(domain_t* domain);

// int register_stream_indication(talker_listener_t * talk_listen);
// int deregister_stream_indication(talker_listener_t * talk_listen);

// int register_attach_indication(talker_listener_t * talk_listen);
// int deregister_attach_indication(talker_listener_t * talk_listen);

// int register_domain_indication(domain_t* domain);
// int deregister_domain_indication(domain_t* domain);



// log message dispatcher to debug
// void log_msg_dispatcher(struct share_memory* shared);
// msrp consumer to debug/log
void log_msrp_consume(struct share_memory * shared);
// print log
// void log_printf(char * buf, uint8_t cmd_t);

// print all kinds of log
// void log_register_stream_request(char * buf, uint8_t cmd_t);
// void log_deregister_stream_request(char * buf, uint8_t cmd_t);
// void log_report_talker_status(char * buf, uint8_t cmd_t);

// void log_register_attach_request(char * buf, uint8_t cmd_t);
// void log_deregister_attach_request(char * buf, uint8_t cmd_t);
// void log_report_listener_status(char * buf, uint8_t cmd_t);

// void log_register_domain_request(char * buf, uint8_t cmd_t);
// void log_deregister_domain_request(char * buf, uint8_t cmd_t);
// void log_report_domain_status(char * buf, uint8_t cmd_t);

// void log_register_stream_indication(char * buf, uint8_t cmd_t);
// void log_deregister_stream_indication(char * buf, uint8_t cmd_t);

// void log_register_attach_indication(char * buf, uint8_t cmd_t);
// void log_deregister_attach_indication(char * buf, uint8_t cmd_t);

// void log_register_domain_indication(char * buf, uint8_t cmd_t);
// void log_deregister_domain_indication(char * buf, uint8_t cmd_t);
#endif
