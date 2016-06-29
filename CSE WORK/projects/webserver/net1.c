// Socket Programming 1
// Today we are looking into the TCP/IP protocol
// Asad Waheed

// headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

//	main
int main( int argc, char **argv )
{
	// needed variables
	int sockfd;
	int conn;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	unsigned	short port = 31337;
	char buffer[128];
	char TimeBuff[128];
	time_t ticks;

	//	Logic
	// AF_INET refers to anything in the protocol; PF_INET is better option
	// SOCK_STREAM is used for TCP/IP; SOCK_DGRAM is used in UDP
	
	if(sockfd = socket(PF_INET, SOCK_STREAM, 0) = -1)
	{
		//	print an error message
		perror("socket creation failed!!");
		return 1;	//	trivial
	}


	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_add = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(port);

	if(bind(sockfd, 32) < 0)
	{
	}

}
