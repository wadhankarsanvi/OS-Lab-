#include <stdio.h>

int main(){
    int n,i,time=0,remain,high;
    int at[10],bt[10],pr[10],ct[10],tat[10],wt[10],done[10]={0};

    // For Gantt chart
    int seq[20],tline[20],k=0;

    float act=0,atat=0,awt=0;

    printf("No of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    remain=n;

    while(remain>0){
        high=-1;

        // find highest priority among arrived
        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(high==-1 || pr[i]<pr[high])
                    high=i;
            }
        }

        // CPU Idle
        if(high==-1){
            time++;
            continue;
        }

        // store start time
        tline[k]=time;
        seq[k]=high;
        k++;

        time+=bt[high];
        ct[high]=time;
        done[high]=1;
        remain--;
    }
    tline[k]=time; // final time

    // calculate times
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        act+=ct[i];
        atat+=tat[i];
        awt+=wt[i];
    }

    // ----- GANTT CHART -----
    printf("\nGantt Chart:\n");

    for(i=0;i<k;i++)
        printf("| P%d ",seq[i]+1);
    printf("|\n");

    for(i=0;i<=k;i++)
        printf("%d    ",tline[i]);
    printf("\n");

    // ----- TABLE -----
    printf("\nP AT BT PR CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d  %d  %d  %d  %d  %d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("\nAvg CT  = %.2f",act/n);
    printf("\nAvg TAT = %.2f",atat/n);
    printf("\nAvg WT  = %.2f\n",awt/n);

    return 0;
}

