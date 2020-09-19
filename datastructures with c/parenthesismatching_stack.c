#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack * s){
    if(s->top == -1){
        return 1;
    }
    else { return 0; }
}
int isfull(struct stack * s){
    if(s->top == s->size - 1){
        return 1;
    }
    else { return 0; }
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
int peek(struct stack *s){
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
int parenthesis_match(char *exp){
    struct stack s;
    s.size = 50;
    s.top = -1;
    s.arr = (char *)malloc(s.size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if (exp[i] == '('){
            push(&s,exp[i]);
        }
        else if (exp[i]==')'){
            if (isempty(&s)){
                return 0;
            }
            else{
                pop(&s);
            }
        }
    }
    if (isempty(&s)){
        return 1;
    }
    else{
        return 0;
    }

}
int main()
{
    // char * expression = "a*(b-c)+(c-d)";
    char expression[100];
    printf("Please enter an expresssion\n");
    scanf("%s",expression);
    if(parenthesis_match(expression)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}