#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "TcpServer.h"

int main(int argc, char* argv[])
{
#if 0
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    chdir(argv[2]);
#else
    unsigned short port = 10000;
int ret = chdir("/home/wcy/snap");
if(ret == -1)
{
    perror("chdir failed"); // 失败会打印原因
}
else
{
    printf("chdir success! current work dir: ");
    char buf[256];
    getcwd(buf, sizeof(buf));
    printf("%s\n", buf); // 打印当前工作目录，验证是否切到snap
}


#endif
    // 启动服务器
    TcpServer* server = new TcpServer(port, 4);
    server->run();

    return 0;
}