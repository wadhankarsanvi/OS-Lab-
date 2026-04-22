#include <stdio.h>

int main(){
    int n,i,time=0,remain,high,last=-1;
    int at[10],bt[10],pr[10],ct[10],tat[10],wt[10],rt[10];
    float act=0,atat=0,awt=0;

    printf("No of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    remain=n;

    printf("\nGantt Chart:\n");

    while(remain>0){
        high=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(high==-1 || pr[i]<pr[high])
                    high=i;
            }
        }

        if(high==-1){ time++; continue; }

        if(last!=high){
            printf("%d |P%d| ",time,high+1);
            last=high;
        }

        rt[high]--;
        time++;

        if(rt[high]==0){
            ct[high]=time;
            remain--;
        }
    }
    printf("%d\n",time);

    // calculate times
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        act+=ct[i];
        atat+=tat[i];
        awt+=wt[i];
    }

    printf("\nP AT BT PR CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d  %d  %d  %d  %d  %d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("\nAvg CT  = %.2f",act/n);
    printf("\nAvg TAT = %.2f",atat/n);
    printf("\nAvg WT  = %.2f\n",awt/n);

    return 0;
}

