#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


typedef struct {
    int top;
    int items[MAX];
    /*struct yap�s� tan�mlad�m. */
} Stack;

void initStack(Stack* s) {
    s->top = -1;
    /*y���n� ba�lat�yorum top de�erini -1 atama
    sebebim isEmpty yapt���mda true d�ns�n */
}

int isEmpty(Stack* s) {
    return s->top == -1;
    /*y���n bo� mu kontrol� yap�yorum*/
}

void push(Stack* s, int item) {
    s->items[++(s->top)] = item;
    /*y���na eleman ekliyorum ve top de�erini art�r�yorum */
}

int pop(Stack* s) {
    return s->items[(s->top)--];
    /*y���n�n en �st�ndeki eleman� ��kart�yorum. */
}

int peek(Stack* s) {
    return s->items[s->top];
    /*peek ile y���n�n en �st�ndeki eleman� d�nd�r�yoruz */
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    /* i�lemlere �ncelik derecesi at�yorum. */
    return -1;
}


int operation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        /*yap�lacak i�lemleri atad�m */
    }
    return 0;
}

int Calculator(const char* str) {
    Stack values;
    Stack ops;
    initStack(&values);
    initStack(&ops);

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            continue;
        }

        if (isdigit(str[i])) {
            int val = 0;
            while (i < strlen(str) && isdigit(str[i])) {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            i--;
            push(&values, val);
        } else if (str[i] == '(') {
            push(&ops, str[i]);
        } else if (str[i] == ')') {
            while (!isEmpty(&ops) && peek(&ops) != '(') {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, operation(val1, val2, op));
            }
            pop(&ops);  // Remove '(' from stack
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (!isEmpty(&ops) && precedence(peek(&ops)) >= precedence(str[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, operation(val1, val2, op));
            }
            push(&ops, str[i]);
        }
    }

    while (!isEmpty(&ops)) {
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = pop(&ops);
        push(&values, operation(val1, val2, op));
    }

    return pop(&values);
}

int main() {
    printf("'6*(4/2)+3*1': %d\n", Calculator("6*(4/2)+3*1"));
    printf("'6/3-1': %d\n", Calculator("6/3-1"));  // 1
    printf("'(2-0)*(6/2)': %d\n", Calculator("(2-0)*(6/2)"));

    return 0;
}
