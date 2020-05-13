#include <pthread.h>
#include <stdio.h>

int sumOfN = 0;
int arr[1000];
int n;

void * findSumOfN(void *a){
    
    printf("Thread 1 Starting\n");
    sumOfN = (n * (n+1)) / 2;   //finds sum of first n natural numbers
    printf("Thread 1 Finished\n");
    pthread_exit(0);
    
}

void * fibonacci(void *a){
    
    printf("Thread 2 Starting\n");
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n;i++)           //find fibonacci numbers iteratively
        arr[i]=arr[i-1]+arr[i-2];
    printf("Thread 2 Finished\n");
    pthread_exit(0);
    
}

int main(void){
    
    
    printf("Please enter the value of n \n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Wrong input ! \n");       //input validation
        return 0;
    }
    
    pthread_t thread1, thread2;
    
    pthread_create(&thread1,NULL, findSumOfN, NULL);   //Create threads
    pthread_create(&thread2,NULL, fibonacci, NULL);
    
    pthread_join(thread1,NULL);   //Start threads
    pthread_join(thread2, NULL);
    
    printf("The sum of first %d numbers is : %d \n",n, sumOfN);
    printf("The first %d fibonacci numbers are : \n",n);
    
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return(0);
    
}
