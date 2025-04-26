#include<stdio.h>
struct process{
    int pid,at,bt,wt,tat,ct;
}p[20];

int  main(){
    int n,i,j,total_wt=0,total_tat=0;
    printf("enter the number of process:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter the arrival time and burst time of P%d  : ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
struct process temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    }

    p[0].ct=p[0].at+p[0].bt;
    for(int i=1;i<n;i++){
        if(p[i].at>p[i-1].ct){
            p[i].ct=p[i].at+p[i].bt;
        }else{
            p[i].ct=p[i-1].ct+p[i].bt;
        }

    }

        for(i=0;i<n;i++){
           p[i].tat=p[i].ct-p[i].at;
           p[i].wt= p[i].tat-p[i].bt;
           total_tat+=p[i].tat;
           total_wt+=p[i].wt;
        }
        printf("average tat is :%.2f \n average wt is %.2f",(float)total_tat/n,(float)total_wt/n);
        printf("\ngantt chart:\n");
        printf("|");
        for(i=0;i<n;i++){
            printf("P%d \t|",p[i+1].pid);
        }
        printf("\n0\t");
        for(i=0;i<n;i++){
            printf("%d \t",p[i].ct);
        }
        
        return 0;
    }
    
