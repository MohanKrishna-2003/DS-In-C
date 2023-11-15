#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char * arr;
};
int isEmpty(struct stack* sp)
{
    if(sp->top==-1){
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
    char val;
    if(isEmpty(sp)){
        printf("The Stack is UnderFlow\n");
    }
    else{
        val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int paranthesisMatch(char* exp)
{
    struct stack *sp;
    sp->size = 30;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*(sizeof(char)));

    for (int i = 0; exp[i]!='\0'; i++)  
    {
        if(exp[i]=='('){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
   char * exp = "((8)((*-()()()()()(000))))-$$9))";
   if(paranthesisMatch(exp)){
    printf("The Paranthesis is Matched");
   }
   else{
    printf("The Paranthesis is not Matched");
   }
   return 0;
}