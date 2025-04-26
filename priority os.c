#include<stdio.h>
struct process{
    int pid,at,bt,ct,pri,tat,wt,done;
}p[20];

int main(){
int i,j,n,completed=0,time=0;
float t_tat=0 ,t_wt=0;
printf("enter the no. of process:");
scanf("%d",&n);

for(i=0;i<n;i++){
    p[i].pid=i+1;
    printf("enter arrival ,burst,priority of P %d:",p[i].pid);
    scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pri);
    p[i].done=0;

}

while(completed<n){
    int idx=-1,high_pri=9999;
    for(i=0;i<n;i++){
        if(p[i].at<=time && !p[i].done && p[i].pri<high_pri){
            high_pri=p[i].pri;
            idx=i;
        }
    }
    if(idx!=-1){
        p[idx].ct=time+p[idx].bt;
        p[idx].tat=p[idx].ct-p[idx].at;
        p[idx].wt=p[idx].tat-p[idx].bt;
        p[idx].done=1;

        t_tat+=p[idx].tat;
        t_wt+=p[idx].wt;
        time=p[idx].ct;
        completed++;

    }else{
        time++;
    }
}
printf("gantt chart\n");
printf("|");
for(i=0;i<n;i++){
printf("P%d\t|",p[i].pid);
}
printf("\n");
printf("0");
for(i=0;i<n;i++){
printf("\t%d",p[i].ct);
}

printf("%.2f %.2f",(float)t_tat/n,(float)t_wt/n);
return 0;
}

