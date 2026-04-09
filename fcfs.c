#include<stdio.h>
int main (){
    int i,n,j ;
    int process[20],bt[20],ct[20],wt[20],tat[20];
    float avg_wt=0 ,avg_tat=0 ;
    printf("assume the arrival time is zero for all the processes\n");
    printf("enter the number of processes : \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        process[i]=i+1 ;
    printf("enter the brust time for %d process : ",i+1);
    scanf("%d",&bt[i]);
    }
    ct[0]=bt[0];
    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i];
    wt[i]=tat[i]-bt[i];
    avg_tat+=tat[i] ;
    avg_wt+=wt[i];
    }
    printf("\nprocesses\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++) {
        printf("p%d\t\t%d\t%d\t%d\t%d\n",process[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n average turnaround time :%2f",avg_tat/n);
    printf("\n average waiting time :%2f",avg_wt/n);
    return 0;
}
