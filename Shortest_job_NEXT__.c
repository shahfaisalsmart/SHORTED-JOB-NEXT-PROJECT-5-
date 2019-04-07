///==================================================///
///               !! HELLO WORLD !!                  ///
///                 >>IT'S ME<<                      ///
///               MOHAMMAD FAISAL                    ///
///==================================================///
//THIS CODE IS IMPLEMENTED BY MOHAMMAD FAISAL 
/*

                DATED: 5-APRIL-2019;
*/
// author: MOHAMMAD FAISAL (email: mohammad.faisal78612@gmail.com)
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/queue.h>
// Creating a structure of a process. Because it is having more and one instance/Characteristics.
struct process
{
    int pid;        //process id variable
    float AT;       //arrival time variable
    float BT;        //burst time variable
    float WT;         // waiting time variable
    float priority;   //priority variable
    int status;        //status variable
    float TT;           //turnaround time variable
    float CC;           //completion time variable

    // status 0 : not available
    // status 1 : ready state
    // ststus 2 : processed
};

int main()
{
    printf("\n ************************* SHORTEST JOB NEXT SCHEDULING ALGORITHM PROJECT OF OPERATING SYSTEM ***********************************");
    printf("\t\t  SUBMITTED BY: MOHAMMAD FAISAL   REG NO. 11702044\n");
    printf("\n\n\n enter the number of processes you want to schedule :  ");
    int number,i;  // initialize number variable to hold the Number of process
    scanf("%d",&number);
    struct process proc[number];  // declare the number of process in the struct.
    
    printf("\n enter the burst time of the processes \n");
 
    for(i=0;i<number;i++)
    {
        printf("\n enter the burst time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].BT);    // taking input as a Burst time from the user.
        proc[i].pid=i+1;            // increament the process by one.
        proc[i].status=0;           // set the status as zero. 
        // it will speacify that it is not available in the system. 
    }

    // for the Arrival time input.
    printf("\n enter the arival time of the processes \n");
    for(i=0;i<number;i++)
    {
        printf("\n enter the arival time for the %d process  :  ",i+1);
        scanf("%f",&proc[i].AT);
    }

    system("cls");
     
    printf("\n Process:     |   Burst Time:     |   Arival Time:     | ");
    for(i=0;i<number;i++)
    {
        printf("\n   %d               %d                   %d      ",proc[i].pid,(int )proc[i].BT,(int )proc[i].AT);
    }
    printf("\n");
    // assign wating time of the process as zero.
    for(i=0;i<number;i++)
    {
        proc[i].WT=0;
    }

    int max_at=0;       // max_at is zero initally. It is used when I do comparison in the portion of the code.

    for(i=0;i<number;i++)
    {
        if((int)proc[i].AT>max_at)    // checking for the maximum arrival time of the process.
        {
            max_at=(int)proc[i].AT;
        }
    }    
 // Now we get the Maximum Arrival time of the process.
 //   printf("\n max is %d ",max);

   int timer=0;   // another variable as a timer of the process.
   int j=0;        
   int seq[number];   // sequence array where we will hold the processed variable.

    for (timer=0;timer<=max_at;timer++)    // it will go upto the Maximum arrival time.
    {
        for(i=0;i<number;i++)   // for all the number of process
        {
            if(timer>=(int)proc[i].AT)  // checking the arrival time as compare to the timer.
            {
                if(proc[i].status==0)   // Also check the status of the process.
                {
                    seq[j++]=proc[i].pid; // it will the assign to sequence Array so that we will processed 
                    proc[i].status=1;  // and then status is updated to the in ready state.
                }
            }
        }
    }
    printf("\n\n\n");


    int final_sequence[number];  // Another array which will hold the final state of the process
    final_sequence[0]=seq[0];  // initailize the  Final_sequencial_Array first element is the sequencial array.
    int n;
    n=number;
    int order[n][n]; // It will hold the order of the process.
 
//    order[0][]=seq;
    for(i=0;i<n;i++)
    {
        order[0][i]=seq[i];     // each and every process order status from sequence of the array.
    }

int next_index;   // it is used when we looking for the next process.
float min=9999.00;  // this is the boundary condition 
timer=0;  // again timer is initialize  zero.
timer=proc[order[0][0]].AT; // this step speacify the order of the process in the basis of Arrival time.
i=0;
    while(n--) . // again checking of the process.
    {
        final_sequence[i]=order[i][0];  // initial value of the process
           proc[i].status=2;   // update the status from ready state to the processed state.
           timer=timer+proc[i].BT; // adding the burst time to the timer

            proc[i].CC=(float)timer; // assign timer to the its Compelition time 
          
           for(j=0;j<number;j++);
           {
                if(proc[j].status==1) // next process which is having status as READY
                {
                    if(proc[j].WT==0)  // if its wating time is zero
                    {
                         proc[j].WT=proc[i].BT - proc[j].AT;     // change its waiting time as difference between its burst time and arrival time.
                    }
                    else
                    {
                    proc[j].WT=proc[j].WT+proc[i].BT; // if the waiting time is non-zero then process time simply adding burst time to it.
                    }
                }
           }

           i++;

           for(int k=0;k<number;k++)    // again when we will looking for the status 
           {
               if(proc[k].status==1)    // when process is in the status as one means it is in Ready status
               {
                   proc[k].priority=1+ (proc[k].WT) / (proc[k].BT) ;   // it is condition given in the problem statement.
               }
            }

            for(int l=0;l<number;l++)
            {
                   if( (timer > proc[l].AT) && ( proc[l].status==1 ) ) // when timer is more than it is arrival time and also is in Ready state.
                   {
                        if(min > proc[l].priority)  // if it is satisfy when it is greater of it's boundary condition
                        {
                            min=proc[l].priority; // set is as priority wise.
                            // and change the index to its adjuscent element.
                            next_index=l;
                        }
                   }
            }
            int z=1; // column wise
            for(j=0;j<number;j++)
            {
                if(j==0)
                {
                    order[i][0]=next_index+1;  // Maintain  the order of the process
                }
                else
                {
                    if(proc[j].status==1)  // after the priority checking and also checking as Status is in Ready queue
                    {
                           order[i][z]=proc[j].pid;  // assignment basis of its pid  
                           z++; 
                    }
                }
            }
