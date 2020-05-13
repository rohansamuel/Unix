#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

void err_sys(const char *x)
{
   printf("\n");
   perror(x);
   printf("\n");
   exit(1);
}

int main()
{
   pid_t pid;
  
  
   if( pid == 0 )
   {
       printf("\nHello, World!\n");
       printf("The child and parent ids are: %d and %d.\n\n", getpid(), getppid());
   }
    
   else if( (pid = fork()) == -1 )
    {
        err_sys("fork failed");
    }
    
  
   else
   {
       wait(NULL);
   }
}
