#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct pQueue{
    char ch;
    int prio;
} pQueue;
int j=1;
    pQueue* arr;
void push(pQueue val){
    int i=j;
    *(arr+j)=val;
    j++;
     while(i!=1){
         int parent=i/2;
           if((arr+i)->prio>(arr+parent)->prio){
            pQueue temp= *(arr+i);
            *(arr+i)=*(arr+parent);
            *(arr+parent)=temp;
        }
        else break;
        i=parent;
     }
}
void pop(){
    j--;
     int k=1;
     pQueue val=*(arr+1);
     *(arr+1)=*(arr+j);
     while(true){
        int left=2*k;
        int right=2*k+1;
        if(left>j-1)break;
        if(right>j-1){
            if((arr+left)->prio>(arr+k)->prio){
                pQueue temp=*(arr+left);
                *(arr+left)=*(arr+k);
                *(arr+k)=temp;
                k=left;
            }
            break;
        }
        if((arr+left)->prio>(arr+right)->prio){
            if((arr+left)->prio>(arr+k)->prio){
                  pQueue temp=*(arr+left);
                *(arr+left)=*(arr+k);
                *(arr+k)=temp;
                k=left;
            }
            else break;
        }
        else{
              if((arr+right)->prio>(arr+k)->prio){
                  pQueue temp=*(arr+right);
                *(arr+right)=*(arr+k);
                *(arr+k)=temp;
                k=right;
            }
            else break;
        }
     }
     printf("The element deleted was %c[%d]",val.ch,val.prio);
     printf("\n");
}
pQueue peek(){
   if(!j){
    printf("the priority queue is empty");
    pQueue h;
    h.ch='N';
    h.prio=-1;
    return h;
   }
   return *(arr+1);
}
void rearrangepriority(){
    if(!j){
        printf("The priority queue is empty");
        return ;
    }
    for(int i=1;i<j;i++){
        int k=i;
     while(true){
        int left=2*k;
        int right=2*k+1;
        if(left>j)break;
        if(right>j){
            if((arr+left)->prio>(arr+k)->prio){
                pQueue temp=*(arr+left);
                *(arr+left)=*(arr+k);
                *(arr+k)=temp;
            }
            break;
        }
        if((arr+left)->prio>(arr+right)->prio){
            if((arr+left)->prio>(arr+k)->prio){
                  pQueue temp=*(arr+left);
                *(arr+left)=*(arr+k);
                *(arr+k)=temp;
            }
            else break;
        }
        else{
              if((arr+right)->prio>(arr+k)->prio){
                  pQueue temp=*(arr+right);
                *(arr+right)=*(arr+k);
                *(arr+k)=temp;
            }
            else break;
        }
     }
    }
}
void changepriority(int val,char ch){
    if(!j){
        printf("The priority queue is empty");
        return ;
    }
    for(int i=1;i<j;i++){
        if((arr+i)->ch==ch){
            int tempval=(arr+i)->prio;
        (arr+i)->prio=val;
        printf("%c[%d]->%c[%d]",ch,tempval,ch,val);
        return ;
        }
    }
}
void display(){
    if(!j){
        printf("The priority queue is empty");
        return ;
    }
    for(int i=1;i<j;i++){
        printf("%c[%d]",(arr+i)->ch,(arr+i)->prio);
    }
}
void levelorder(){
    int left=1;
    int right=2;
    while(left<j){
        for(int i=left;i<right && i<j;i++) printf("%c[%d] ",(arr+i)->ch,(arr+i)->prio);
        left=right;
        right*=2;
        printf("\n");
    }
}
int main(){
    arr=(pQueue*)calloc(100,sizeof(pQueue));
      pQueue pq1;
      pQueue pq2;
      pQueue pq3;
      pQueue pq4;
      pQueue pq5;
      pQueue pq6;
      pq1.ch='E';
      pq1.prio=100;
      pq2.ch='C';
      pq2.prio=70;
      pq3.ch='A';
      pq3.prio=50;
      pq4.ch='B';
      pq4.prio=10;
      pq5.ch='D';
      pq5.prio=65;
      pq6.ch='F';
      pq6.prio=40;
      push(pq1);
      push(pq2);
      push(pq3);
      push(pq4);
      push(pq5);
      push(pq6);
      levelorder();
      pop();
      levelorder();
      printf("\n");
      display();

}