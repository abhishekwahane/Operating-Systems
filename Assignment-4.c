//203165
//Abhishek Wahane
//B1 Batch
//Banker's Algorithm

#include<stdio.h>

void read_matrix(int n,int m,int mat[20][20])                       //reading the matrix
{
    int i,j;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            scanf("%d",&mat[i][j]);
            }
        }
}

void print_matrix(int n,int m,int mat[20][20])                //function to display the matrix
{
    int i,j;
    for(i=0;i<n;i++)
            {
            for(j=0;j<m;j++)
                {
                printf("%d\t",mat[i][j]);
                }
            printf("\n");
            }

}

void read_vector(int size,int array[20])                     //function for reading the maximum available resources
{
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
}

void print_vector(int size,int array[20])                      //function for displaying maximum available resources
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t",array[i]);
    }
}

void comp_need(int n,int m,int need[20][20],int alloc[20][20],int max_claim[20][20])           //function for computing the need matrix
{
    int i,j;
        for(i=0;i<n;i++)
            {
            for(j=0;j<m;j++)
                {
                 need[i][j]=max_claim[i][j]-alloc[i][j];

                }
            }
        printf("\n");
}

int is_safe(int n,int m,int need[20][20],int alloc[20][20],int avail[20])            //function to compute whether the system is in safe state or not
{
    int i,j,flag,k=0;
    int seq[20],work[20],finish[20];
    for(i=0;i<n;i++)
        finish[i]=0;
    for(j=0;j<m;j++)
        work[j]=avail[j];
    while(1)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                        break;
                }
                if(j==m)
                {
                    seq[k]=i;
                    k++;
                    finish[i]=1;
                    flag=1;
                    for(j=0;j<m;j++)

                        {
                        work[j]=work[j]+alloc[i][j];
                        }
                }
            }
        }
          if((flag==0||k==n))
          break;
    }
        if(k==n)                                 //if in safe state display safety sequence
        {
            printf("System status: SAFE\n");
            printf("Safety sequence is: \n");
            for(i=0;i<n;i++)
              printf("P%d\t",seq[i]);
            printf("\n");
            return 1;

        }
        else
        {
            printf("\nSystem status: NOT SAFE\n");
            return 0;
        }


}

int main()                          
{
    printf("Banker's Algorithm\n");
    
    int m,n,flag;
    int avail[20],max_avail[20],alloc[20][20],need[20][20],max_claim[20][20];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);

    printf("Enter allocation matrix: \n");
    read_matrix(n,m,alloc);

    printf("Enter maximum instances of each resource type: ");
    read_vector(m,avail);

    printf("Enter maximum demand or claim matrix: ");
    read_matrix(n,m,max_claim);

    comp_need(n,m,need,alloc,max_claim);

    printf("\nCurrent Snap shot is: \n");
    printf("\nCurrent available resources: \n");
    print_vector(m,avail);

    printf("\nMax claim matrix is:\n");
    print_matrix(n,m,max_claim);

    printf("\nAllocation matrix is:\n");
    print_matrix(n,m,alloc);

    printf("\nNeed matrix is:\n");
    print_matrix(n,m,need);

    printf("\nChecking for safe state...\n");
    flag=is_safe(n,m,need,alloc,avail);
}


/*
ibm@IBM:~$ gcc -o ass4 OS-4.c
ibm@IBM:~$ ./ass4
Banker's Algorithm
Enter number of processes: 5
Enter number of resource types: 3
Enter allocation matrix: 
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter maximum instances of each resource type: 10 5 7
Enter maximum demand or claim matrix: 7 5 3
3 2 2
9 0 2
2 2 2
4 3 3


Current Snap shot is: 

Current available resources: 
10	5	7	
Max claim matrix is:
7	5	3	
3	2	2	
9	0	2	
2	2	2	
4	3	3	

Allocation matrix is:
0	1	0	
2	0	0	
3	0	2	
2	1	1	
0	0	2	

Need matrix is:
7	4	3	
1	2	2	
6	0	0	
0	1	1	
4	3	1	

Checking for safe state...
System status: SAFE
Safety sequence is: 
P0	P1	P2	P3	P4	
ibm@IBM:~$ 
*/
