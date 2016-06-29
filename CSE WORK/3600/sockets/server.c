/*///////////////////////////////////////////////////////////
 *
 * Minor Assignment 6 -- Team 19
 *
 * A simple server in the internet domain using TCP
 * The port number is passed as an argument
 *
 * Adapting Vinod Pillai's client-server application
 * into a theater ticketing system for this program
 *
 *///////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     int i;

     // Front-end user display
     printf("\nTicketing System v_1\n-------------------\n-------------------\n");
     printf("\n\nWaiting for client request...\n");

    /* Now we use an array of random numbers to simulate "tickets" */

	// fill array with pseudo random numbers
	
	int SIZE = 20; // number of tickets
	int tickets[SIZE];
        srand(time(NULL)); //seed the generator
	for(i = 0; i < SIZE; i++) //populate array
	{
	     tickets[i] = rand()% 20; // Note it's possible to have
				      // repeat ticket values if rand limit is < 20
	}

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     if (sockfd < 0) 
        error("ERROR opening socket");

     bzero((char *) &serv_addr, sizeof(serv_addr));

     portno = atoi(argv[1]);

     serv_addr.sin_family = AF_INET;

     serv_addr.sin_addr.s_addr = INADDR_ANY;

     serv_addr.sin_port = htons(portno);

     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");

     listen(sockfd,5);

     clilen = sizeof(cli_addr);

     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);

     if (newsockfd < 0) 
          error("ERROR on accept");


     bzero(buffer,256);
     n = read(newsockfd,buffer,255);

     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"SUCCESS: RECEIVED REQUEST",18);

     if (n < 0) error("ERROR writing to socket");
     close(newsockfd);
     close(sockfd);

     return 0; 
}
