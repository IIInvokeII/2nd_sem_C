#include <stdio.h>
int main()
{
    int arr_time[10], burst_time[10], pid[10];
    int n, i, j, temp, count, iter = 0; 
    int start_time, end_time = 0, sum_wait = 0, sum_turnaround = 0;
    float avgwait, avgturn;
    //Taking all the inputs
    printf("\nEnter No. of Processes: "); scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d - Arrival Time:", i + 1); scanf("%d", &arr_time[i]);
        printf("Process %d - Burst Time:", i + 1); scanf("%d", &burst_time[i]);
        pid[i] = i + 1;
    }
    //using bubble sort to sort according to arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr_time[i] > arr_time[j])
            {
                temp = arr_time[i];
                arr_time[i] = arr_time[j];
                arr_time[j] = temp;
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    end_time=arr_time[0]; //The least arrival time may not be 0 sometimes, so we are defining this here. 
    printf("\n\nPID\t|Arrival Time\t|Burst Time\t|Start Time\t|End Time\t|Waiting Time\t|Turnaround Time\n");
    while (iter < n)
    {
        count = 0;
        //we are counting how many of the processes are in the waiting queue, ready to be executed. 
        for (i = iter; i < n; i++)
        {
            if (arr_time[i] <= end_time)
                count++;
            else
                break;
        }
        //They are then sorted (only those processes) based on burst time
        if (count > 1)
        {
            for (i = iter; i < iter + count - 1; i++)
            {
                for (j = i + 1; j < iter + count; j++)
                {
                    if (burst_time[i] > burst_time[j])
                    {
                        temp = arr_time[i];
                        arr_time[i] = arr_time[j];
                        arr_time[j] = temp;
                        temp = burst_time[i];
                        burst_time[i] = burst_time[j];
                        burst_time[j] = temp;
                        temp = pid[i];
                        pid[i] = pid[j];
                        pid[j] = temp;
                    }
                }
            }
        }
        //start time of the next process is the end time of the previous process
        start_time = end_time;  
        //end_time keeps track of the time passed. by the end of every iteration, it will be the end time of every process
        end_time += burst_time[iter];
        printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", 
                pid[iter], //Process ID
                arr_time[iter], //Arrival Time
                burst_time[iter], //Burst Time
                start_time, //Start Time
                end_time, //End Time
                start_time - arr_time[iter], //Waiting Time
                //Also same as end_time - arr_time[iter] - burst_time[iter], 
                end_time - arr_time[iter]   //Turnaround Time
                //Also same as Waiting Time + burst_time[iter]
            );
        sum_wait += start_time - arr_time[iter];
        //end_time - arr_time[iter] - burst_time[iter];
        sum_turnaround += end_time - arr_time[iter];
        iter++;
    }
    avgwait = (float)sum_wait / (float)n;
    avgturn = (float)sum_turnaround / (float)n;
    printf("\nAverage Waiting Time: %f", avgwait);
    printf("\nAverage TurnAround Time: %f", avgturn);

    printf("\n\nGantt chart:\n");
    for(i=0;i<n;i++)
    {
        printf("|P%d\tP%d",pid[i],pid[i]);
    }
    printf("|");
    printf("\n|%d\t  ",arr_time[0]);
    int sum=arr_time[0];
    for(i=0;i<n;i++)
    {
        sum+=burst_time[i];
        printf("|%d\t  ",sum);
    }
    return 0;
}