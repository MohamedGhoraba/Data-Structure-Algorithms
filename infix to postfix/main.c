#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SIZE = 25;
char STACK[25];
int top = -1;

int Stack_Post[25];
int Top_Post = -1;

int Is_Full(){
    if (top == SIZE){
        return 1;
    }else
    return 0;
}

int Is_Full_Post(){
    if (Top_Post == SIZE){
        return 1;
    }else
    return 0;
}

int Is_Empty(){
    if(top == -1){
        return 1;
    }else
    return 0;
}

int Is_Empty_Post(){
    if(Top_Post == -1){
        return 1;
    }else
    return 0;
}

void push(char data){
    if(!Is_Full()){
        STACK[++top] = data;
    }else
    printf("stack is full");
}

void Push_Post(char data){
    if(!Is_Full_Post()){
        Stack_Post[++Top_Post] = data;
    }else
    printf("stack is full");
}

char pop(){
    if(!Is_Empty()){
        return STACK[top--];
    }else
  printf("stack is empty");
}

char Pop_Post(){
    if(!Is_Empty_Post()){
        return Stack_Post[Top_Post--];
    }else
  printf("stack is empty");
}

int precedence(char symbol){
    switch(symbol){
    case'+':case'-':
        return 2;
        break;
    case'*':case'/':
        return 3;
        break;
    case'^':
        return 4;
        break;
    case'(':case')':case'#':
        return 1;
        break;
    }
}

int Is_Operator(char symbol){
    switch(symbol){
    case'+':case'-':case'/':case'*':case'^':case')':case'(':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void Convert(char infix[], char postfix[]){
    STACK[++top] = '#';
    char symbol;
    int j = 0,i;
    for(i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        if(!Is_Operator(symbol)){
            postfix[j++] = symbol;
        }else{
            if(symbol == '('){
                push(symbol);
               }else{
                if(symbol == ')'){
                    while(STACK[top] != '('){
                           postfix[j++] = pop();
                          }
                          pop();
                   }else{
                    if(precedence(symbol) > precedence(STACK[top])){
                        push(symbol);
                    }else{
                        while(precedence(symbol) <= precedence(STACK[top])){
                            postfix[j++] = pop();
                        }
                        push(symbol);
                    }
                   }
               }
        }
    }
    while(STACK[top] != '#'){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int Evaluate(char *postfix){
    char ch; int i = 0,operand1,operand2;
    while((ch = postfix[i++]) != '\0'){
        if(!Is_Operator(ch)){
            Push_Post(ch-'0');
        }else{
            operand2 = Pop_Post();
            operand1 = Pop_Post();
            switch(ch){
                case'+':
                    Push_Post(operand1 + operand2);
                    break;
                case'-':
                    Push_Post(operand1 - operand2);
                    break;
                case'/':
                    Push_Post(operand1 / operand2);
                    break;
                case'*':
                    Push_Post(operand1 * operand2);
                    break;
            }
        }
    }
    return Stack_Post[Top_Post];
}

int main()
{
   char infix[25] = "(1*2)+3",postfix[25];
   Convert(infix,postfix);

   printf("Infix expression is: %s\n" , infix);
   printf("Postfix expression is: %s\n" , postfix);
   printf("Evaluated expression is: %d\n" , Evaluate(postfix));
    return 0;
}
