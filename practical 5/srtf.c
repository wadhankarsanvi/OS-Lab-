#include <stdio.h>

int main(){
    int n,i,time=0,remain,smallest,last=-1;
    int at[10],bt[10],rt[10],ct[10],tat[10],wt[10];

    float act=0,atat=0,awt=0;

    // gantt
    int seq[100],tline[100],k=0;

    printf("No of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    remain=n;

    while(remain>0){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        // CPU idle
        if(smallest==-1){
            time++;
            continue;
        }

        // store gantt only when process changes
        if(last!=smallest){
            seq[k]=smallest;
            tline[k]=time;
            k++;
            last=smallest;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            ct[smallest]=time;
            remain--;
        }
    }
    tline[k]=time;

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
    printf("\nP AT BT CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d  %d  %d  %d  %d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    printf("\nAvg CT  = %.2f",act/n);
    printf("\nAvg TAT = %.2f",atat/n);
    printf("\nAvg WT  = %.2f\n",awt/n);

    return 0;
}

