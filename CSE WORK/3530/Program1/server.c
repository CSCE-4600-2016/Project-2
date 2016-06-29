//	Asad Waheed
//	server.c
//	Desc: Server program
//	Sourced from here:http://www.linuxhowtos.org/C_C++/socket.htm
//	Some notes: All functions will be followed by a ---function--- comment
// 	For easier identification
//	Compile: gcc -w -o server server.c
// 	Run: ./server #### (where #### is a 4-digit port number)

// libraries
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>	// strstr
#include <stdlib.h> // malloc
#define SERVER "Server: Dynamic Thread\n"
#define CONTENT "Content-Type: text/html\r\n"


//----------------------error---------------------------//

// If unable to open the connection
void error(char *message)
{
	perror(message);
	exit(1);
}

/*void displayRequest(char s[])
{
	char* token = strtok(s, " ");
	char* str = "GET";
    while (token)
    {
        printf("token: %s\n", token);
        token = strtok(NULL, " ");
		if(strcmp(token,str) == 0){	printf("\n\n\nYou entered GET");}
    }
}*/




//-----------------parseHttpReq-----------------------------//


/* Source: http://www.dreamincode.net/forums/topic/228373-writing-my-own-web-server-in-c/ */
void parseHttpReq(unsigned char *buffcopy)
{
  int sock;
  char buffer[1024];
  int readIn;
  char *method, *path, *version;
  int v1, v2, m;
  //cast sock back to int
 //  sock = (int)buffcopy;

  //Get input from client
  readIn = recv(sock, buffer, 1024, 0);
  buffer[readIn] = '\0';

  //parse the HTTP method, path to the file and the HTTP version
  method = (char*)malloc(sizeof(buffer)+1);
  strstr(method, buffer);  		//	copy header data into method
  method = strtok(method, " ");
  printf("%s\n", method);
  path = strtok(path, " ");
  printf("%s\n", path);
  version = strtok(version, "\r\n");
//  printf("%s\n", version);

	printf("\nLine73works\n");

  //Find the HTTP version
  v1 = strcmp(version, "HTTP/1.0\r\n");
  v2 = strcmp(version, "HTTP/1.1\r\n");
   if(!v1)
    strcpy(version, "HTTP/1.0");
   else
     strcpy(version, "HTTP/1.1");



  ///Send back a 400 error message
  if((!v1) || (!v2))
    badRequest(sock);
  else
    { //See if the correct method is used -- only handle GET
      m = strcmp(method, "GET");
      if(m == 0)
	serve(sock, path);  //Send file
      else
	notGet(sock);
    }

  //	return arg;
  // free up memory from method variable
  free(method);
} // End of parseHttpReq


//---------------------badRequest------------------------//


void badRequest(int sock)
{
	  char buffer[1024];

	  // Send HTTP Response line by line
	  strcpy(buffer, "HTTP/1.0 400 Bad Request\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, SERVER);
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, CONTENT);
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "<html>\n<head>\n<title>Bad Request</title>\n</head>\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "<body>\n<p>400 Bad Request.</p>\n</body>\n</html>\r\n");
	  write(sock, buffer, strlen(buffer));

}	//	End of badRequest

//---------------------------goodRequest------------------------//

void goodRequest(int sock)
{
		char buffer[1024];

	  //Send HHTP Response line by line
	  strcpy(buffer, "HTTP/1.0 200 Ok\r\n");
	  send(sock, buffer, strlen(buffer), 0);
	  strcpy(buffer, SERVER);
	  send(sock, buffer, strlen(buffer), 0);
	  strcpy(buffer, CONTENT);
	  send(sock, buffer, strlen(buffer), 0);
	  strcpy(buffer, "\r\n");
}	//End of good request




//---------------------------notGet-----------------------------//

void notGet(int sock)
{
		char buffer[1024];

	  //Send HTTP Response line by line
	  strcpy(buffer, "HTTP/1.0 501 Method Not Implemented\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, SERVER);
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, CONTENT);
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "<html>\n<head>\n<title>Method Not Implemented</title>\n</head>\r\n");
	  write(sock, buffer, strlen(buffer));
	  strcpy(buffer, "<body>\n<p>501 HTTP request method not supported.</p>\n</body>\n</html>\r\n");
	  write(sock, buffer, strlen(buffer));
}

//-------------------notFound--------------------------//

void notFound(int sock)
{
	char buffer[1024];

	//Send HTTP Response line by line
	strcpy(buffer, "HTTP/1.0 404 Not Found\r\n");
	write(sock, buffer, strlen(buffer));
	strcpy(buffer, SERVER);
	write(sock, buffer, strlen(buffer));
	strcpy(buffer, CONTENT);
	write(sock, buffer, strlen(buffer));
	strcpy(buffer, "\r\n");
	write(sock, buffer, strlen(buffer));
	strcpy(buffer, "<html>\n<head>\n<title>Not Found</title>\n</head>\r\n");
	write(sock, buffer, strlen(buffer));
	strcpy(buffer, "<body>\n<p>404 Request file not found.</p>\n</body>\n</html>\r\n");
	write(sock, buffer, strlen(buffer));
}

//------------------------outputFile--------------------------//

void outputFile(int sock, FILE *html)
{
	char buffer[1024];  //Only supports small files

	//Read in file and store in buffer
	fgets(buffer, sizeof(buffer), html);
	while(!feof(html))
	  { send(sock, buffer, strlen(buffer), 0);
	    fgets(buffer, sizeof(buffer), html);
	  }//End of while
}

//End of output file

//---------------------serve-----------------------------------//


void serve(int sock, char *path)
{
	  FILE *html = NULL;
  	  char buffer[1024];
      int num = 1;

	  //determine file name
	  if(strcmp(path, "/"))
	     strcpy(path, "index.html");

	  //Open file
	  html = fopen(path, "r");
	  if(html == NULL)
	    notFound(sock);
	  else
	    { goodRequest(sock);
	      outputFile(sock, html);
	    }//Send file

	  //Close file
	  fclose(html);

}//End of serve





//----------------main----------------------------------//


int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno, clilen, n;
	//printf("\n\nLINE 236 good\n\n");
	/**
	 * 	sockfd and newsockfd are file descriptors, i.e. array subscripts into the file descriptor table . 
	 * 	These two variables store the values returned by the socket system call and the accept system call.
	 * 	portno stores the port number on which the server accepts connections.
	 * 	clilen stores the size of the address of the client. This is needed for the accept system call.
	 * 	n is the return value for the read() and write() calls; i.e. it contains the number of characters read or written.
	 * */
	 //printf("\n\nLine 244 good\n\n");

	 char buffer[256];

	 struct sockaddr_in serv_addr, cli_addr;
	 
	 if (argc < 2)
	 {
		 fprintf(stderr,"ERROR no port provided");
		 exit(1);
	 }
	 
	 sockfd = socket(AF_INET, SOCK_STREAM, 0);
	 if( sockfd < 0)
		error("Error opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	portno = atoi(argv[1]);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);	
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR on binding");
	
	listen(sockfd, 5);
	//printf("\n\nline 270 good\n\n");
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if(newsockfd < 0)
		error("Error on accept");

	bzero(buffer, 256);
	n = read(newsockfd, buffer, 255);
	if(n < 0) error("Error reading from socket");
	printf("Here is the message: %s", buffer);
	//printf("\n\nline 280 good");

	//parseHttpReq(buffer);

	// Take the buffer input and copy it to a new char array so we can pass
	// it around to our functions for parsing/processing

	 char *src = buffer;
   unsigned char *bufferCopy="";

   //memset(bufferCopy, '\0', sizeof(*bufferCopy)); // allocate space for bufferCopy

   strstr(bufferCopy, src);
	 printf("Server-side confirmation of client request: %s\n\n", bufferCopy);



	//Tokenize client get request
	char* token = strtok(buffer, " ");
	while (token != '\0')
	{
    	printf("token: %s\n", token);
    	token = strtok(NULL, " ");
	}

	//displayRequest(buffer);
  parseHttpReq(buffer);
	n = write(newsockfd, "I got the message", 18);

	if(n < 0) error("ERROR writing to socket");

	return 0;

}


