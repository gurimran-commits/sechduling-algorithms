#include<stdio.h>
int main(){
    int n,i,j;
    float avg_tat=0,avg_wt=0;
    int process[20],bt[20],ct[20],tat[20],wt[20];
    printf("suppose the arriving time is zero \n");
    printf("enter the number of processes : \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        process[i]=i+1;
        printf("enter the burst time for the process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                int temp_bt=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp_bt;
                int temp_p =process[j];
                process[j]=process[j+1];
                process[j+1]=temp_p;
            }
        }        
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }
    ct[0] = bt[0];
for(i=1;i<n;i++){
    ct[i] = ct[i-1] + bt[i];
}
    for(i=0;i<n;i++){
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("\nprocess\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("p%d\t%d\t%d\t%d\t%d\n",process[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\naverage waiting time =%.2f\n",avg_wt);
    printf("\naverage turnaround time =%.2f\n", avg_tat); 
    return 0;
}
