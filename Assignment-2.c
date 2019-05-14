
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int t;
void asc(int ar[10], int n)                                  //function for ascending order
{
        for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                        if(ar[j]>ar[j+1])
                        {
                                t=ar[j];                        //swap 
                                ar[j]=ar[j+1];
                                ar[j+1]=t;
                        }

}



void desc(int ar[10], int n)                                    //function for descending order
{
        for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                        if(ar[j]<ar[j+1])
                        {
                                t=ar[j];                          //swap
                                ar[j]=ar[j+1];
                                ar[j+1]=t;
                        } 
                        
}

int main()
{
     int ar[10];
     int a;

printf("\nEnter Array Size:");       
scanf("%d",&a);

for(int i=0;i<a;i++)                                   //for array elements
{
        printf("\nEnter Elements:");
        scanf("%d",&ar[i]);
}
pid_t mypid;
mypid=fork();



if(mypid==0)                                        //child process
{
        printf("\nCHILD PROCESS");
        printf("\nthe elements are:\n");
        asc(ar,a);
        for(int i=0;i<a;i++)
        {
                printf("%d",ar[i]);
                printf("\t");
        }
}

else                                                   //parent process
{
	wait(NULL);
        printf("\nPARENT PROCESS");
        printf("\nthe elements are:\n");
        desc(ar,a);
        for(int i=0;i<a;i++)
        {
                printf("%d",ar[i]);
                printf("\t");
        }
}
}

//OUTPUT
/*ibm@IBM:~/assg2$ gcc -o sort sort.c
ibm@IBM:~/assg2$ ./sort

ENTER THE ARRAY SIZE:4

ENTER THE ELEMENTS:11

ENTER THE ELEMENTS:45

ENTER THE ELEMENTS:34

ENTER THE ELEMENTS:23

CHILD PROCESS
the elements are:
11	23	34	45	
PARENT PROCESS
the elements are:
45	34	23	11	
*/
