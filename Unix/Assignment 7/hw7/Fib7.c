#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void err_sys(const char* x)
{
   perror(x);
   exit(1);
}

int main(){

int n,k , c, i,f;
int *arr;
printf("Enter number of terms: ");
scanf("%d", &n);
arr = (int*) malloc(n* sizeof(int));

arr[0] = 0;
arr[1] = 1;

k= fork();



if(k ==0){
//child process

for(i=0; i<n; i++)
{
    if(i != 0 && i !=1)
       arr[i] = arr[i-1] + arr[i-2];

    printf("%d ",arr[i]);
}
}
    else if(k < 0)
    {
        
        err_sys("Fork failed");
    }
else{
    //parent process

    c = wait(NULL);
    printf("\n Child process ID %d \n", c);
    printf(" Parent process ID %d\n", getpid());
}

    return 0;
}
