#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

/*
 * In the included file <sys/un.h> a sockaddr_un is defined as follows
 * struct sockaddr_un {
 *  short   sun_family;
 *  char    sun_path[108];
 * };
 */


#include <stdio.h>


#define NAME "home/msrp/domain_socket/socket"

int msrpCreateUDS(CHAR * pathName){
    int sock, length, rt;
    struct sockaddr_un name;
    char buf[1024];


    /* Create socket from which to read. */
    if ((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        perror("opening datagram socket");
        exit(1);
    }

    /* Create name. */
    name.sun_family = AF_UNIX;
    strcpy(name.sun_path, pathName);

    rt = bind(sock, (struct sockaddr *) &name, sizeof(struct sockaddr_un));
    /* Bind the UNIX domain address to the created socket */
    if (rc) {
        perror("binding name to datagram socket");
        exit(1);
    }
    return rt;
}

int msrpRecvUDS(int sock){
    if(sock < 0){
        return -1;
    }
    char *msgbuf;
	struct sockaddr_un client_addr;
	struct msghdr msg;
	struct iovec iov;
	int bytes = 0;

	msgbuf = (char *)malloc(1500);
	if (NULL == msgbuf)
		return -1;

	memset(&msg, 0, sizeof(msg));
	memset(&client_addr, 0, sizeof(client_addr));
	memset(msgbuf, 0, 1500);

	iov.iov_len = 1500;
	iov.iov_base = msgbuf;
	msg.msg_name = &client_addr;
	msg.msg_namelen = sizeof(client_addr);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	bytes = recvmsg(sock, &msg, 0);
	if (bytes <= 0)
		perror("recvmsg");
	// 出来传递过来的控制消息
	msrpProcessUDS(msgbuf, bytes, &client_addr);
	return -1;
	
}

int msrpProcessUDS(char *buf, int buflen, struct sockaddr_un *client){
    printf("I'm msrpProcessUDS");
    printf("-->%s\n", buf);
}
/*
 * This program creates a UNIX domain datagram socket, binds a name to it,
 * then reads from the socket.
 */
main()
{
    int sock;
    char buf[1024];

    sock = msrpCreateUDS(NAME);
    printf("socket -->%s\n", NAME);

    while(1){
        /* Read from the socket */
        msrpRecvUDS(sock);
        // if (read(sock, buf, 1024) < 0)
        //     perror("receiving datagram packet");
        // printf("-->%s\n", buf);
    }
    close(sock);
    unlink(NAME);
}