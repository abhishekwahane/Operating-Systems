//203165
//Abhishek Wahane
//B1 Batch
//CPU Scheduling - SJF

#include<stdio.h>
#include<stdlib.h>
struct term{
int at;     // arrival time
int bt;     // burst time
int rt;     // remaing time
int name;
int wt;     // waiting time
int tat;    // turnaround time
};
typedef struct term sjterm;
 
void sjfpm(sjterm p[10], int n)
{
   int i,j,min,curr_time,min_index;
   curr_time = p[0].at;
    printf("\nGantt Chart: \n");
   printf("%d",curr_time);
   while(1)
   {
	     min = 999;
	     min_index= -1;
	     i=0;
	     while (i<n && p[i].at <= curr_time)   // check wheteher process arrived
	     {
	     if(  p[i].rt!=0 && p[i].rt < min) // detect minimum remaining time process
	       {
	          min = p[i].rt;
	          min_index=i;
	       }
	     i++;
	    }
	    if(i==n && min_index ==-1)break;
	    else if(i!=n && min_index ==-1)   // CPU idle
	      {
	     printf("<-IDLE->");
	     curr_time=p[i].at;
	      }
	   else if(i==n && min_index!=-1) // all process arrived
	     {
	       j=min_index;
	       printf("<--P%d-->",p[j].name);
	       curr_time = curr_time + p[j].rt;
	       p[j].rt = 0;
	       p[j].tat = curr_time - p[j].at;
	       p[j].wt = p[j].tat - p[j].bt;
	     }
	   else // execute the process only for 1 unit of time
	     {
	    j=min_index;
	    printf("<--P%d-->",p[j].name);
	    curr_time=curr_time+1;
	    p[j].rt=p[j].rt-1;
	    if(p[j].rt==0)
	      {
	        p[j].tat = curr_time - p[j].at;
	        p[j].wt = p[j].tat - p[j].bt;
	      }
	     }
	     printf("%d",curr_time);
 }
}

void display(sjterm p[10],int n)
{
	  int i;
	  printf("\n\n\nProcess AT      BT     WT      TAT\n");
	  for(i=0;i<n;i++)
	  {
	    printf("\nP%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);
	  }
      int sta=0,swt=0,awt=0,ata=0;
      for(i=0;i<n;i++)
      {
         swt=swt+p[i].wt;
         sta=sta+p[i].tat;
      }
      awt=swt/n;
      ata=sta/n;
      printf("\n\nAverage Waiting Time: %d\n",awt);
      printf("Average Turn Around Time: %d\n\n",ata);
}

void sort(sjterm process[10],int n)
	{
	  int i,j;
	  sjterm t;
	  for(i=0;i<n-1;i++)
	   {
	      for(j=i+1;j<n;j++)
	    {
	       if(process[i].at > process[j].at)
	          {
	        t= process[i];
	        process[i] = process[j];
	        process[j] = t;
	          }
	    }
   }
}

void read_data(sjterm process[10],int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    printf("\nProcess: P%d \n",i+1);
    process[i].name = i+1;
    printf("Arrival Time: ");
    scanf("%d",&process[i].at);
    printf("Burst Time: ");
    scanf("%d",&process[i].bt);
    process[i].rt = process[i].bt;
    process[i].wt = 0;
    process[i].tat = 0;
  }
}


int main()
{
  sjterm process[10];
  int n;
  printf("\nEnter number of processes: \n");
  scanf("%d",&n);
  read_data(process,n);
  sort(process,n);
  sjfpm(process,n);
  display(process,n);
  return 0;
}
