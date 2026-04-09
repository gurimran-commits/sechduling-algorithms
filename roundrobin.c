#include<stdio.h>
int main() 
{
    int i,n;
    float avg_tat =0,avg_wt=0;
    int process[20],at[20],bt[20],ct[20],tat[20],wt[20],rt[20];
    printf("\n====this is a roundrobin algorithm====\n");
    printf("enter the number of processes : ");

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        process[i]=i+1 ;
        printf("\n enter the arrival time for %d process :",i+1);
        scanf("%d",&at[i]);
    }
    printf("\n---enter the burst time ---");
    for(i=0;i<n;i++)
    {
        process[i]=i+1 ;
        printf("\n enter the  burst time for %d process :",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }
    int tq ,time = 0, remaining =n,flag =0;
    printf("\n enter the time quantum :");
    scanf("%d",&tq);
    printf("\n\np id\tat\tbt\tct\ttat\twt \n");
    printf("---------------------------------------------------------------------------\n");
    while(remaining>0)
    {

        int done_work=0;
        for( i = 0; i < n; i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                done_work=1;
                if (rt[i]<=tq)
                {
                    time +=rt[i];
                    rt[i]=0;
                    flag=1;                    
                }
                else
                {
                    time +=tq;
                    rt[i]-=tq;
                }
                if(rt[i]==0 && flag==1)
                {
                    remaining--;
                    ct[i]=time;

                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    avg_tat+=tat[i];
                    avg_wt+=wt[i];
                    flag=0;
                    printf("\np%d\t%d\t%d\t%d\t%d\t%d\n",process[i],at[i],bt[i],ct[i],tat[i],wt[i]);
                }
            }
        }
        if (done_work=0){
            time++;
        }        
    }  
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
    printf("the average turnaround time = %.2f",avg_tat);
    printf("\nthe average waiting time =%.2f",avg_wt);
    return 0;
}
