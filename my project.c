#include<stdio.h>
#include<process.h>
#include<conio.h>

int main() 
{ 
      int i ; 
	  int lim , totl = 0 ; 
	  int x , con = 0; 
	  int time_quan , j ; 
      
	  int waiting_time = 0, turn_around_time = 0 ;
	  int pos , z , p[10] , priority[10] ;
	  int arrival_time[10] , burst_time[10] , temp[10] , b; 
      
	  float average_wait_time, average_turnaround_time;
      
      system("color a");
	  printf("\nEnter total Number of Processes:"); 
      
	  scanf("%d", &lim); 
      
	  x = lim; 
      for(i = 0; i < lim; i++) 
      {
	    p[i]=i+1;
	   
	    priority[i]=0;
            printf("\nEnter totl Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &time_quan); 
      system("color F2");
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(totl = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<lim;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<lim;j++)
			{
			    if(priority[j]<priority[pos])
				pos=j;
			}
		 
		temp1=priority[z];
	
		priority[z]=priority[pos];
	
		priority[pos]=temp1;
		 
			temp1=burst_time[z];
			burst_time[z]=burst_time[pos];
			burst_time[pos]=temp1;
		 			temp1=arrival_time[z];
				arrival_time[z]=arrival_time[pos];
			arrival_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= time_quan && temp[i] > 0) 
            { 
                  totl = totl + temp[i]; 
                  temp[i] = 0; 
                  con = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quan; 
                  totl = totl + time_quan; 
            } 

	for(b=0;b<lim;b++)
		{
			if(b==i)
			priority[b]+=1;
			else
			priority[b]+=2;
		}

            if(temp[i] == 0 && con == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\t\t%d", p[i], burst_time[i], totl - arrival_time[i], totl - arrival_time[i] - burst_time[i],priority[i]);
                  waiting_time = waiting_time + totl - arrival_time[i] - burst_time[i]; 
                  turn_around_time = turn_around_time + totl - arrival_time[i]; 
                  con = 0; 
            } 
            if(i == lim - 1) 
            {
                  i = 0; 
            
			}
            else if(arrival_time[i + 1] <= totl) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}

