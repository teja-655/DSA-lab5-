#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int stack[50];
int top = -1;
char post[][4] = {"1", "2", "+", "3", "*", "12", "-"};
char pre[][4]  =  {"+","*","3","4","5"};
void push(int x) { 
    stack[++top] = x; 
    
}
int  pop(void)   { 
    return stack[top--]; 
    
}
void apply(char c, int A, int B) {
    switch (c) {
        case '+': push(A + B); break;
        case '-': push(A - B); break;
        case '*': push(A * B); break;
        case '/': push(A / B); break;
        case '%': push(A % B); break;
    }
}
int Postfix(char arr[][4], int n) {
    top = -1;
    for (int i = 0; i < n; i++) {
        if (isdigit(arr[i][0])) {
            push(atoi(arr[i]));
        } else {
            int B = pop();
            int A = pop();
            apply(arr[i][0], A, B);
        }
    }
    return pop();
}
int Prefix(char arr[][4], int n) {
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(arr[i][0])) {
            push(atoi(arr[i]));
        } else {
            int A = pop();
            int B = pop();
            apply(arr[i][0], A, B);
        }
    }
    return pop();
}
int main() {
    int n = sizeof(post) / sizeof(post[0]);
    int m = sizeof(pre)  / sizeof(pre[0]);

    printf("%d\n", Postfix(post, n));
    printf("%d\n", Prefix(pre, m));
    return 0;
	

}


