#include<conio.h>
#include<stdio.h>
#include<limits.h>
int main() {

    int i,n;
    float avg_tat=0,avg_wt=0;
    int t_wt=0,t_tat=0;
    int process[20],bt[20],ct[20],tat[20],wt[20],at[20],rt[20];
    printf("enter the number of processes :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        process[i]=i+1 ;
        printf("enter arrival time for %d process : ",i+1);
        scanf("%d",&at[i]);
    }
    printf("\n enter the burst time here\n");
    for(i=0;i<n;i++){
        process[i]=i+1 ;
        printf("enter burst time for %d process : ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    int comp = 0 , curr_time = 0;
    int min_remaining_time = INT_MAX;
    int shortest_process_index=0;
    int process_found = 0;
    while (comp !=n){
        for(int j=0;j<n;j++){
            if((at[j]<= curr_time) && (rt[j]>0))
            {
                min_remaining_time=rt[j];
                shortest_process_index=j;
                process_found=1;


            }
        }

        if(process_found ==0){
            curr_time++;
            continue;
        }
        rt[shortest_process_index]--;
        if(rt[shortest_process_index]== 0){
            comp++;
            ct[shortest_process_index]= curr_time + 1 ;
            tat[shortest_process_index]=ct[shortest_process_index]-at[shortest_process_index];
            wt[shortest_process_index]=tat[shortest_process_index]-bt[shortest_process_index];
            t_tat += tat[shortest_process_index];
            t_wt += wt[shortest_process_index];
        }

        curr_time++;
    }
    printf("\n\nprocess\tat\tbt\tct\ttat\twt ");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d\n",process[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    avg_tat= (float)t_tat/n;
    avg_wt= (float)t_wt/n;
    printf("\n average turnaround time = %.2f",avg_tat);
    printf("\n average waiting time = %.2f",avg_wt);
    return 0 ;
}
