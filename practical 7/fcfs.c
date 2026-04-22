#include <stdio.h>

int main(){
    int n,i,j,temp;
    int at[10],bt[10],ct[10],tat[10],wt[10];

    printf("No of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    // sort by arrival time
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
            }
        }
    }

    // completion time
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(ct[i-1]<at[i])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
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
    for(i=0;i<n;i++)
        printf(" P%d |",i+1);

    printf("\n%d",at[0]);
    for(i=0;i<n;i++)
        printf("   %d",ct[i]);

    printf("\n");
    return 0;
}

