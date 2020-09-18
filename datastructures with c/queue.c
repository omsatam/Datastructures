#include<stdio.h>
#include<stdlib.h>

struct queue{
    int maxSize;
    // int n;
    int e;
    int d;
    int *arr;
    // arr = (int *)malloc(maxSize * sizeof(int));
};
int isfull(struct queue *q){
    if(q->maxSize == q->e){
        return 1;
    }
    return 0;
}
int isempty(struct queue *q){
      if(q->d == q->e){
        return 1;
    }
    return 0;
}

void enque(struct queue *q,int element){
    if (isfull(q)){
        printf("The queue is already full\n");
    }
    else{
        q->e++;
        q->arr[q->e] = element;
    }

}
int dequeue(struct queue *q){
    int a;
    if (isempty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->d++;
        a = q->arr[q->d];
    }
    return a;
}
void show_queue(struct queue *q){
    if(isempty(q))
    {
        printf("The queue is empty\n Insert elements to print\n");
    }
    printf("\n");
    else {for(int i=q->d+1;i<q->e+1;i++){
     printf("%d  ",q->arr[i]);    
    }
    printf("\n");
    }
}
int main()
{
     struct queue q;
     q.maxSize = 50;
     q.e = -1;
     q.d = -1;
     int i,n;
     q.arr = (int *)malloc(q.maxSize * sizeof(int));
    //  printf("How many elements you want to enter\n");
    //  scanf("%d",&n);
    //  for(i=0;i<n;i++){
    //      scanf("%d",(q.arr+i));
    //  }
    // isempty(&q);
    // isfull(&q);
enque(&q,45);
enque(&q,5);
enque(&q,15);
enque(&q,75);
enque(&q,47);
enque(&q,77);
enque(&q,21);
enque(&q,116);
enque(&q,5);
enque(&q,47);
show_queue(&q);
printf("%d ",dequeue(&q));
printf("%d ",dequeue(&q));
printf("%d ",dequeue(&q));
printf("%d ",dequeue(&q));
printf("%d ",dequeue(&q));
show_queue(&q);

return 0;
}