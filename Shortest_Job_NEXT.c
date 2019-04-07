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
