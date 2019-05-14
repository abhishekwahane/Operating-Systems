//203165
//Abhishek Wahane
//B1 Batch
//Page Replacement

#include<stdio.h>

int main()
{
      
      printf("Page Replacement Algorithm");
      int choice;
      printf("\nChoose Method: ");
      printf("\n1. FIFO \n2. LRU\n");
      scanf("%d", &choice);
      
      if(choice==1)
      {
      		
      int reference_string[20], page_faults = 0, m, n, s, pages, frames;
      printf("\nEnter Total Number of Pages: \n");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No [%d]:\n", m + 1);
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames: \n");
      {
            scanf("%d", &frames);
      }
      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            for(n = 1; n <= frames; n++)
            {
                  if(reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[m] = reference_string[m];
            }   
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
            printf("\n");
            for(n = 0; n < frames; n++)
            {     
                  printf("%d\t", temp[n]);
            }
            if(s == 0)
            	printf("\t*");
      } 
      printf("\nTotal Page Faults:\n%d\n", page_faults);
      return 0;
      	  	
      }
      
      else if(choice==2)
      {
      int frames[10], temp[10], pages[10];
      int total_pages, m, n, position, k, l, total_frames;
      int a = 0, b = 0, page_fault = 0;
      printf("\nEnter Total Number of Frames: \n");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      printf("Enter Total Number of Pages: \n");
      scanf("%d", &total_pages);
      printf("Enter Values for Reference String: \n");
      for(m = 0; m < total_pages; m++)
      {
            printf("Value No [%d]: \n", m + 1);
            scanf("%d", &pages[m]);
      }
      for(n = 0; n < total_pages; n++)
      {
            a = 0, b = 0;
            for(m = 0; m < total_frames; m++)
            {
                  if(frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if(a == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for(m = 0; m < total_frames; m++)
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            printf("\n");
            for(m = 0; m < total_frames; m++)
            {
                  printf("%d\t", frames[m]);
            }
      }
      printf("\nTotal Number of Page Faults: \n%d\n", page_fault);
      return 0;
      }
      
      else
      {
	    return 0;
      }

}

/*
ibm@IBM:~$ gcc -o fifo fifo.c
ibm@IBM:~$ ./fifo

Enter Total Number of Pages: 
5

Enter values of Reference String:
Value No [1]:
1
Value No [2]:
1
Value No [3]:
1
Value No [4]:
1
Value No [5]:
1

Enter Total Number of Frames: 
3

1	-1	-1		*
1	1	-1		*
1	1	-1	
1	1	-1	
1	1	-1	
Total Page Faults:
2
ibm@IBM:~$ 

*/


/*
ibm@IBM:~$ gcc -o lru lru.c
ibm@IBM:~$ ./lru

Enter Total Number of Frames: 
3
Enter Total Number of Pages: 
5
Enter Values for Reference String: 
Value No [1]: 
2
Value No [2]: 
2
Value No [3]: 
2
Value No [4]: 
2
Value No [5]: 
2

2	-1	-1	
2	-1	-1	
2	-1	-1	
2	-1	-1	
2	-1	-1	
Total Number of Page Faults: 
0
ibm@IBM:~$ 

*/
