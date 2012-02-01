#ifndef RBCZMQ_POLLITEM_H
#define RBCZMQ_POLLITEM_H

typedef struct {
    VALUE socket;
    VALUE io;
    VALUE events;
    zmq_pollitem_t *item;
} zmq_pollitem_wrapper;

#define ZmqAssertPollitem(obj) ZmqAssertType(obj, rb_cZmqPollitem, "ZMQ::Pollitem")
#define ZmqGetPollitem(obj) \
    zmq_pollitem_wrapper *pollitem = NULL; \
    ZmqAssertPollitem(obj); \
    Data_Get_Struct(obj, zmq_pollitem_wrapper, pollitem); \
    if (!pollitem) rb_raise(rb_eTypeError, "uninitialized ZMQ pollitem!");

VALUE rb_czmq_coerce_pollable(VALUE obj);
VALUE rb_czmq_pollitem_pollable(VALUE obj);
VALUE rb_czmq_pollitem_events(VALUE obj);

void _init_rb_czmq_pollitem();

#endif