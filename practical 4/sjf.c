#include <stdio.h>

int main(){
    int n,i,time=0,remain,smallest;
    int at[10],bt[10],ct[10],tat[10],wt[10],done[10]={0};

    printf("No of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    remain=n;

    // SJF Scheduling
    while(remain>0){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(smallest==-1 || bt[i]<bt[smallest])
                    smallest=i;
            }
        }

        // CPU idle
        if(smallest==-1){
            time++;
            continue;
        }

        time+=bt[smallest];
        ct[smallest]=time;
        done[smallest]=1;
        remain--;
    }

    // TAT & WT
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    // table
    printf("\nP AT BT CT TAT WT\n");
    for(i=0;i<n;i++)
        printf("%d %d  %d  %d  %d  %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    time=0;
    remain=n;

    int printed[10]={0};

    while(remain>0){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && printed[i]==0){
                if(smallest==-1 || bt[i]<bt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        printf(" P%d |",smallest+1);
        time+=bt[smallest];
        printed[smallest]=1;
        remain--;
    }

    printf("\n0");
    for(i=0;i<n;i++)
        printf("   %d",ct[i]);

    printf("\n");
    return 0;
}

