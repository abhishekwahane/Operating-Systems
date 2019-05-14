//203165
//Abhishek Wahane
//B1 Batch
//CPU Scheduling - FIFO

#include<stdio.h>
typedef struct
{
	int at,bt,wt,ta,cs;
	
}process;

int main()
{
process p[20];
int n;
int i;

	int sta=0;
	int awt=0;
	int ata=0;
	int swt=0;
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter Arrival Time and Burst Time for the processes: \n");
	for(int i=0;i<n;i++)
	{
		printf("\nArrival Time of process P%d:",i+1);
		scanf("%d",&p[i].at);
		printf("Burst Time of process P%d:",i+1);
		scanf("%d",&p[i].bt);
	}
	p[0].wt=0;
	p[0].cs=0;
	p[0].ta=p[0].bt;
	for(i=1;i<n;i++)
	{
		p[i].cs=p[i-1].cs+p[i-1].bt;
		p[i].wt=p[i].cs-p[i].at;
	}
	for(int i=0;i<n;i++)
	{
		p[i].wt=0;
		for(int j=0;j<i;j++)
			p[i].wt=p[i].wt+p[j].bt;
			//printf("\nWaiting Time: \n");
			//printf("%d",p[i].wt);
		
	}
	for(int i=0;i<n;i++)
	{
		p[i].ta=0;
		for(int j=0;j<i;j++)
			p[i].ta=p[i].wt+p[i].bt;
			//printf("\nTurn Around Time: \n");
			//printf("%d",p[i].ta);
		
	}
	for(int i=0;i<n;i++)
	{
		swt=swt+p[i].wt;
		sta=sta+p[i].ta;
	}
	
	awt=swt/n;
	ata=sta/n;
    printf("\nGantt Chart: ");
	printf("\n--------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("P%d(%d-%d)|",i+1,p[i].cs,p[i].cs+p[i].bt);
	}
	printf("\n--------------------------------------------------------\n");
	printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\n",i+1,p[i].at,p[i].bt,p[i].wt,p[i].ta);	
	}
	
	printf("\nAverage Waiting Time: %d",awt);
	printf("\nAverage turn Around Time: %d\n\n",ata);
return 0;
}
