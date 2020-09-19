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

int peek(struct stack *s){
    return s->arr[s->top];    
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
int match(char a,char b){
    if((a == '(')&&(b == ')')){
        return 1;
    }
    if((a == '[')&&(b == ']')){
        return 1;
    }
    if((a == '{')&&(b == '}')){
        return 1;
    }
    return 0;
}

int multipleparenthesis_match(char *exp){
    int pop_ch;

    struct stack s;
    s.size = 50;
    s.top = -1;
    s.arr = (char *)malloc(s.size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')){
            push(&s,exp[i]);
        }
        else if ((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')){
            if (isempty(&s)){
                return 0;
            }
            else{
                pop_ch = pop(&s);
                if(!match(pop_ch,exp[i])){
                    return 0;
                }
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
    char * expression = "a*(b-c)*{y[hfg]}(ghfa[jh]){hsd[{]})";
    // char expression[100];
    // printf("Please enter an expresssion\n");
    // scanf("%s",expression);
    if(multipleparenthesis_match(expression)){
        printf("The parenthesis is matching\n");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}