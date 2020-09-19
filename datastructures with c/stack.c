#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack * s){
    if(s->top == -1){
        return 1;
    }
    else {
         return 0;
        }
}

int isfull(struct stack * s){
    if(s->top == s->size - 1){
        return 1;
    }
    else { 
        return 0; 
    }
}

void push(struct stack * s,int element){
    // int value;
    if(isfull(s)){
        printf("The stack is already full\n");
    }
    else{        
        s->top++;
        s->arr[s->top] = element;
        // return value;
    }
}

int pop(struct stack * s){
    int value;
      if(isempty(s)){
        printf("The stack is empty\n");
    }
    else{
       value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int peek(struct stack *s, int position){
    int value;
    value = s->arr[position -1];
    return value;
}

int stack_top(struct stack *s){
    return s->arr[s->top];    
}

void show_stack(struct stack *s){
    int a = s->top;
    printf("\n");
    do{
        printf("%d\n",s->arr[a]);
        a--;
    }while(a>=0);    
}

int main()
{
    struct stack s;
    s.size = 50;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));
    push(&s,45);
    push(&s,46);
    push(&s,456);
    push(&s,457);
    push(&s,39);
    push(&s,37);
    push(&s,451);
    push(&s,452);
    push(&s,45);
    push(&s,46);
    push(&s,456);
    push(&s,457);
    push(&s,39);
    push(&s,37);
    push(&s,451);
    push(&s,452);
    printf("%d ",pop(&s));
    printf("%d ",pop(&s));
    printf("%d ",pop(&s));
    printf("%d ",pop(&s));
    printf("%d ",pop(&s));
    
    show_stack(&s);
    
    printf("%d ",stack_top(&s));
    printf("\nthe element at 5 position is %d\n",peek(&s,5));
    return 0;
}
