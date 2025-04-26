#include<stdio.h>

 struct process{
    int pid,bt,ct,rt,tat,wt;

}p[100];

int main(){
    int n,tq,time=0,done;
    
    printf("enter no of process");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter burst time pf P %d:",p[i].pid);
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    }
    printf("enter time quantum");
    scanf("%d",&tq);
    printf("\ngantt chart\n");

    do{
    done=1;
    for(int i=0;i<n;i++){
        if(p[i].rt>0){
            done=0;
            if(p[i].rt>tq){
                printf("P%d|",p[i].pid);
            time+=tq;
            p[i].rt-=tq;
            }else{
                printf("P%d|",p[i].pid);
                time+=p[i].rt;
                p[i].ct=time;
                p[i].rt=0;

            }
        }
    }
    }while(!done);

    printf("\n");
    float t_tat=0,t_wt=0;
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct;
        p[i].wt=p[i].tat-p[i].bt;
        t_tat+=p[i].tat;
        t_wt+=p[i].wt;
    }
printf("average tat is:%.2f \n average wt is:%.2f",(float)t_tat/n,(float)t_wt/n);
    return 0;

}
