#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char* arr;
};
int isEmpty(struct stack* sp)
{
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack* sp)
{
    if(sp->top == sp->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* sp, char val)
{
    if(isFull(sp)){
        printf("The Stack is OverFlow\n");
    }
    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}
char pop(struct stack* sp)
{
    if(isEmpty(sp)){
        printf("The Stack is UnderFlow\n");
    }
    else{
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}
int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char ch)
{
    if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
char* infixToPostfix(char* infix)
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 20;
    sp->arr = (char*)malloc(sp->size*(sizeof(char)));
    char* postfix = (char*)malloc((strlen(infix)+2)*sizeof(char));
    int i = 0; // THIS 'i' WILL TRACK THE INFIX
    int j = 0; // THIS 'j' WILL TRACK THE POSTFIX ( BY ADDING )
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char* infix = "p-q-r/a";
    printf("The Resultant Postfix Expression is %s", infixToPostfix(infix));
    return 0;


}