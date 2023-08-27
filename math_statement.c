#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct StackNode {
    int data;
    struct stackNode* nextPtr;
};


void push(struct StackNode** topPtr, int info);
int pop(struct StackNode** topPtr);

int main() {

    struct StackNode* stackPtr = NULL;
    char ch,st[100];
    int value = 0, num1, num2, res,i=0;

    printf("Enter myMath statement :");
    fgets(st, 100, stdin);


    while (st[i]!='/0') {

        ch = st[i];

        if (ch>='1'&&ch<='9') {

            value = ch - '0';
            push(&stackPtr, value);

        }
        else if (ch == 42 || ch == 43 || ch == 45 || ch == 47) {

            num1 = stackPtr->data;
            pop(&stackPtr);
            num2 = stackPtr->data;
            pop(&stackPtr);

            if (ch == 42)
                res = num2 * num1;
            if (ch == 43)
                res = num2 + num1;
            if (ch == 45)
                res = num2 - num1;
            if (ch == 47)
                res = num2 / num1;

            push(&stackPtr, res);

        }
        else {
            printf("Statement must contain only numbers(1..9) and operators(+ - * /).");

            break;
        }

        i++;

    }

    if(stackPtr!=NULL)
        printf("Result of myMath statement :%d", pop(&stackPtr));


    return 0;
}

void push(struct StackNode** topPtr, int info) {

    struct StackNode* newPtr = (struct StackNode*)malloc(sizeof(struct StackNode));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else {
        printf("ERROR");
    }

}

int pop(struct StackNode** topPtr) {

    struct StackNode *tempPtr = *topPtr;
    int popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;

    free(tempPtr);

    return popValue;
}