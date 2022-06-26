//
// Created by zhuzh on 2022/6/23.
//

#include "sq_stack.h"

Status InitStack_Sq(SqStack *S) {
    S->base = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stack_size = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack_Sq(SqStack *S) {
    free(S->base);
    S->base = S->top = NULL;
    S->stack_size = 0;
    return 0;
}

Status ClearStack_Sq(SqStack *S) {
    if (!S->base) return ERROR;
    S->top = S->base;
    return OK;
}

Status StackEmpty_Sq(SqStack *S) {
    return S->base == S->top;
}

int StackLength_Sq(SqStack *S) {
    return (int) (S->top - S->base);
}

Status GetTop_Sq(SqStack *S, ElemType *e) {
    if (S->base == S->top) return ERROR;
    *e = *(S->top - 1);
    return OK;
}

Status Push_Sq(SqStack *S, ElemType e) {
    if (S->top - S->base >= S->stack_size) {
        S->base = (ElemType *) realloc(S->base, (S->stack_size + STACK_INCREMENT) * sizeof(ElemType));
        if (!S->base) exit(OVERFLOW);
        S->top = S->base + S->stack_size;
        S->stack_size += STACK_INCREMENT;
    }
    *S->top++ = e;
    return OK;
}

Status Pop_Sq(SqStack *S, int *e) {
    if (S->top == S->base) return ERROR;
    --S->top;
    if(e) *e = *S->top;
    return OK;
}

Status Display_Sq(SqStack *S) {
    if (!S || !S->base) return ERROR;
    printf("-------------------------------\n");
    printf("size: %d\n", StackLength_Sq(S));
    printf("[");
    for (ElemType *i = S->base; i < S->top; ++i) {
        printf("%d", *i);
        if (i < S->top - 1) printf("->");
    }
    printf("]\n");
    printf("-------------------------------\n");
    return OK;
}

Status StackTraverse_Sq(SqStack *S, Status (*visit)(int *)) {
    if (!S || !S->base) return ERROR;
    for (ElemType *i = S->base; i < S->top; ++i) {
        if (!visit(i)) return ERROR;
    }
    return OK;
}

void conversion() {
    SqStack S;
    InitStack_Sq(&S);

    int N;
    scanf("%d", &N);
    while (N) {
        Push_Sq(&S, N % 8);
        N /= 8;
    }

    int e;
    if (!StackEmpty_Sq(&S)) printf("0");
    while (!StackEmpty_Sq(&S)) {
        Pop_Sq(&S, &e);
        printf("%d", e);
    }
}

void line_edit() {
    SqStack S;
    InitStack_Sq(&S);
    int ch = getchar();
    int c = 0;
    while (ch != EOF) {
        while (ch != EOF && ch != '\n') {
            switch (ch) {
                case '#':
                    Pop_Sq(&S, &c);
                    break;
                case 64:
                    ClearStack_Sq(&S);
                    break;
                default:
                    Push_Sq(&S, ch);
            }
            ch = getchar();
        }
        for (ElemType *i = S.base; i < S.top; ++i) {
            printf("%c", *i);
        }
        ClearStack_Sq(&S);
        if (ch != EOF) ch = getchar();
    }
}