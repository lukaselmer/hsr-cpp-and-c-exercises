#include <netinet/in.h>
#include <string>
class Socket {
public:
static int MakeTCPSocket();
static bool SetNonBlocking(int fd, bool how=true);
static bool SetReuseAddr(int fd);
static struct sockaddr_in MakeSocketAddr(const char *host,int port);
static std::string getHostIp(const char *host);
static bool Connect(int fd, struct sockaddr_in sa);
static bool Bind(int fd, struct sockaddr_in sa);
static bool Listen(int fd);
};
