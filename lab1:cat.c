#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(int argc, char **argv)
{

   int i;
   int fd;
   int closed;
   ssize_t bytesRead;
   uint8_t buf[180];
   if (argc>1)
   {
      for (i=1; i<argc; i++)
      { 	
   		  printf("File %d is %s", i, argv[i]);	
   		  fd = open (argv[i], O_RDONLY);
   		  if (fd== -1)
   		  {
   		    	perror(argv[0]);
   			    //exit(errno);
   		   }				
   		   while(1==1)
   		   {
   		     bytesRead = read(fd, buf, 180);
   		     if (bytesRead == -1)
   		     {
   		       perror(argv[0]);
   			   //exit(errno);
   		     }
   		     printf("%s\n",buf);
   		     if (bytesRead<180) break;
   		    } 
   		    closed = close(fd);
   	   }
   	 }
   	 else
   	 {
   	     
   	     char c[1];
   	     while(1==1)
   	     {
   	       bytesRead = read(STDIN_FILENO, c,1);
   	       write(STDOUT_FILENO,c,1);
   	     }
   	 }
}
