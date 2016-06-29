Readme.txt
-------------
Preparation:
Open two terminals, in two different CSE machines. I used cse01 and cse06. 

How this program works:

1. compile server.c using gcc -o server server.c
2. compile client.c using gcc -o client client.c
3. In the first terminal, run server and give a port number: ./server <portnumber>
4. Then in the second terminal, run client with a CSE machine host and 
   give it the SAME port number from step 3: ./client cseXX.cse.unt.edu <portnumber>
5. You will receive a prompt- Enter your message:	
6. Enter a HTTP GET request in this format: GET hostname.com/file.html HTTP/1.1
7. You will either get one of the following messages back from the server:
"HTTP 200: OK...Requested file found!" or "HTTP 404: The file requested was not found". 
8.  If the second message displays, you will get another prompt: "Retrieve file from internet? [Y/N]"
9.  If you pick yes, the file is retrieved from the internet and sent to your directory.
10. If you pick no, the connection is closed and program ends with a goodbye message. 
