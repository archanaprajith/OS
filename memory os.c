#include<stdio.h>
#include<stdlib.h>

struct block{
    int id,size,alloc;
}b[10];

struct process{
    int id,size,blckno;
}p[10];

void first(int m,int n){
    
    for (int i = 0; i < m; i++) b[i].alloc = -1;
    for (int i = 0; i < n; i++) p[i].blckno = -1;

    for( int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(b[j].alloc==-1 && b[j].size>=p[i].size){
            p[i].blckno=b[j].id;
            b[j].alloc=1;
            break;
            }
    }
    }
    printf("process no \t block no");
    for(int i=0;i<n;i++){
        if(p[i].blckno!=-1){
        printf("\n");
            printf("%d \t %d ",p[i].id ,p[i].blckno);
        }else
        {
    printf("\n%d \t Not Allocated", p[i].id);

    }
    }
}
    

void best(int m,int n){
    for (int i = 0; i < m; i++) b[i].alloc = -1;
    for (int i = 0; i < n; i++) p[i].blckno = -1;

    struct block temp;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(b[j].size >b[j+1].size){

            temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
            }
        }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j].alloc==-1 && b[j].size>=p[i].size){
                p[i].blckno=b[j].id;
                b[j].alloc=1;
                break;
                }
        }
        
    }
    printf("process no \t block no");
    for(int i=0;i<n;i++){
        if(p[i].blckno!=-1){
        printf("\n");
            printf("%d \t %d ",p[i].id ,p[i].blckno);
        }else
        {
    printf("\n%d \t Not Allocated", p[i].id);
        }
}

}

void worst(int m,int n){
    
        for (int i = 0; i < m; i++) b[i].alloc = -1;
        for (int i = 0; i < n; i++) p[i].blckno = -1;
    
        struct block temp;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<m-i-1;j++){
                if(b[j].size <b[j+1].size){
    
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
                }
            }
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[j].alloc==-1 && b[j].size>=p[i].size){
                    p[i].blckno=b[j].id;
                    b[j].alloc=1;
                    break;
                    }
            }
            
        }
        printf("process no \t block no");
        for(int i=0;i<n;i++){
            if(p[i].blckno!=-1){
            printf("\n");
                printf("%d \t %d ",p[i].id ,p[i].blckno);
            }else
            {
        printf("\n%d \t Not Allocated", p[i].id);
            }
    }
    
    }


int main(){
int i,j,m,n;
printf("enter no. of process:");
scanf("%d",&n);
printf("enter no. of memory block:");
scanf("%d",&m);

for(i=0;i<n;i++){
    p[i].id = i + 1;
    printf("enter size of process %d :",i+1);
    scanf("%d",&p[i].size);
    p[i].blckno=-1;
   
}
for(int i=0;i<m;i++){
    b[i].id = i + 1;
    printf("enter size of block %d :",i+1);
    scanf("%d",&b[i].size);
    b[i].alloc=-1;
}
int ch;
while(1){
    printf("enter choice:");
scanf("%d",&ch);
switch(ch){
    case 1:first(m,n);
    break;

    case 2:best(m,n);
    break; 
    case 3:worst(m, n);
    break;

    case 4:exit (0); 
    
}
}

    return 0;
}
