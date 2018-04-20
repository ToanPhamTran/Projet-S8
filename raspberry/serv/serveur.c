#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int main(int argc , char *argv[])
{
    int socket_desc , new_socket , c;
    const int trueFlag =1;
    struct sockaddr_in server , client;
    char *message;
    int read_size,ge;
    char client_message[2000],yes[]="Y", no[]="N",quit[]="Z";
    char caract, buffer[2000],ch;
    FILE *file;
    long file_size = 0,i;
    char file_name[]="test.csv";

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //reuse of port
    setsockopt(socket_desc,SOL_SOCKET,SO_REUSEPORT,&trueFlag,sizeof(int));
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
        printf("Address %s\nPort %d\n",inet_ntoa(client.sin_addr),client.sin_port);

        //Reply to the client
        message = "Hello I'm the Interface\nDo you want to receive Data? \nType Y/N \nType Z to quit \n";
        send(new_socket , message , strlen(message),MSG_CONFIRM);

         while( (read_size = recv(new_socket , client_message , 2000 , 0)) > 0 )
    {
        puts(client_message);
        if (strpbrk(client_message,yes))
        {
            message = "I will now procede to the Data transfert\n";
            puts(message);
            send(new_socket , message , strlen(message),MSG_CONFIRM);

            file=fopen(file_name,"r");
            if (file==NULL) perror ("Error opening file");
            else
            {
/*          Counting Nb of words in the file      */
            fseek(file,0,SEEK_END);
            file_size=ftell(file);
            rewind(file);
            printf ("Size of %s: %ld bytes.\n",file_name,file_size);

/*          Sending the file      */
            message = "Sending ";
            send(new_socket , message , strlen(message),MSG_CONFIRM);
            send(new_socket, &file_size, sizeof(long),MSG_CONFIRM);
            message = " bytes\n";
            send(new_socket , message , strlen(message),MSG_CONFIRM);

            for(i=file_size;i>=0;i--)
            {
                //fscanf(file, "%s",buffer);
                ge=getc(file);
                send(new_socket, ge, sizeof(int),MSG_CONFIRM);
                //send(new_socket,buffer,strlen(buffer),MSG_CONFIRM);
            }
            printf("The file was sent successfully");
            fclose(file);
            }
        }
        else if (strpbrk(client_message,no))
        {
            message = "I will wait for you to be ready\n";
            puts(message);
            send(new_socket , message , strlen(message),MSG_CONFIRM);
        }

	else if (strpbrk(client_message,quit))
        {
            message = "Thank you, see you soon\n";
            puts(message);
            send(new_socket , message , strlen(message),MSG_CONFIRM);
            close(new_socket);
        }
    }

    	if(read_size == 0)
    	{
        	puts("Client disconnected");
        	fflush(stdout);
    	}
    	else if(read_size == -1)
    	{
       		 perror("recv failed");
  	 }
    }

    if (new_socket<0)
    {
        perror("accept failed");
        return 1;
    }

close(socket_desc);
    return 0;
}
