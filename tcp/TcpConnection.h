#pragma once
#include "EventLoop.h"
#include "Buffer.h"
#include "Channel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include <memory>

//#define MSG_SEND_AUTO

class TcpConnection
{
public:
    TcpConnection(int fd, EventLoop* evloop);
    ~TcpConnection();

    static int processRead(void* arg);
    static int processWrite(void* arg);
    static int destroy(void* arg);
private:
    string m_name;
    EventLoop* m_evLoop;
    Channel* m_channel;
    std::unique_ptr<Buffer> m_readBuf;
    std::unique_ptr<Buffer> m_writeBuf;
    std::unique_ptr<HttpRequest> m_request;
    std::unique_ptr<HttpResponse> m_response;
};