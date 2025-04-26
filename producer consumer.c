#include<stdio.h>

int buffer[10],size,front=-1,rear=-1;

void producer(int n){
if(rear==size-1){
printf("BUFFER FULL....Producer can't insert data\n");
}
else {
if(rear==-1){
rear=0;
front=0;
}
printf("Producer Inserted data succesfully\n");
buffer[rear++]=n;
}
}

void consumer(){
if(front==-1&&rear==-1){
printf("BUFFER EMPTY....Consumer can't delete data\n");
}
else{
int v=buffer[front];
printf("Data : %d\n",v);
printf("Consumer deleted data succesfully\n");
if(front==size-1){
front=-1;
rear=-1;
}
else{
front++;
}
}
}


int main(){
int ch,n;
printf("Enter Size\n");
scanf("%d",&size);
do{
printf("1.Producer	2.Consumer	3.Exit\n");
scanf("%d",&ch);
switch(ch){
case 1:printf("Enter data");
	scanf("%d",&n);
	producer(n);
	break;
case 2:consumer();
	break;
case 3:printf("Exiting program\n");
	break;
default :printf("Invalid choice\n");
}
}while(ch!=3);
return 0;
}
