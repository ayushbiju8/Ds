#include <stdio.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char postfix[30];
char stack[20];

void push(char c){
    top++;
    stack[top]=c;
}

char pop(){
    char c = stack[top];
    top--;
    return c;
}


int presc(char c){
    switch (c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^' :
            return 3;
        default:
            return -1;
    }
}



char* infixToPostfix(char* infix){
    int length = strlen(infix);
    int j=0;
    
    for (int i=0;i<length;i++){
        char c = infix[i];
        if (isalnum(c)){
            postfix[j++]=c;
        }else if(c=='('){
            push(c);
        }else if(c==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }else{
            while(top!=-1 && (presc(c)<presc(stack[top])||(presc(c)==presc(stack[top])&&c!='^'))){
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("%s\n", postfix);
}
int main(){
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
}

// Algorithm to convert an infix expression to a postfix expression:
//
// 1. Initialize an empty stack and an empty string to hold the postfix expression.
// 2. Loop through each character (symbol) in the infix expression:
//     a. If the character is an operand (e.g., a variable or number), append it directly to the postfix expression.
//     b. If the character is an opening parenthesis '(', push it onto the stack.
//     c. If the character is a closing parenthesis ')':
//        - Pop characters from the stack and append them to the postfix expression until an opening parenthesis '(' is encountered.
//        - Discard the opening parenthesis.
//     d. If the character is an operator (+, -, *, /, ^):
//        - While the stack is not empty and the precedence of the operator at the top of the stack is greater than or equal to
//          the current operator (except for the case where both operators are '^'), pop the operator from the stack and append it to the postfix expression.
//        - Push the current operator onto the stack.
// 3. After processing the entire infix expression, pop any remaining operators from the stack and append them to the postfix expression.
// 4. The final postfix expression is the converted expression.
//
// Precedence rules:
//     - Operators '^' has the highest precedence, followed by '*' and '/' with the same precedence, and then '+' and '-' with the lowest precedence.
//     - Parentheses '(' and ')' are used to alter precedence during the conversion process.
//
