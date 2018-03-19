//
//  main.c
//  ConvertNum
//
//  Created by 吴孜健 on 2018/3/16.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct SqNode{
    int elem;
    struct SqNode *next;
}SqNode;

typedef struct SqStack{
    SqNode *base;
    SqNode *top;
}SqStack;

void systemConvert(int number,int system,SqStack *SS);
void InitStack(SqStack *SS);
int PushStack(SqStack *SS,int e);
int PopStack(SqStack *SS);




int main(int argc, const char * argv[]) {
    SqStack S;
    InitStack(&S);
    int number,system;
    scanf("%d",&number);
    scanf("%d",&system);
    systemConvert(number,system,&S);
    
    while (S.top != S.base) {
        PopStack(&S);
    }
    return 0;
}

void systemConvert(int number,int system, SqStack *SS){
    int q;//余数
    int r;//商
    r = number/system;
    q = number%system;
    PushStack(SS, q);
    while (r != 0) {
        q = r%system;
        r = r/system;
        PushStack(SS, q);
    }
}

void InitStack(SqStack *SS)
{
    SS->base = (SqNode *)malloc(sizeof(SqNode));
    SS->top = SS->base;
    
}


int PopStack(SqStack *SS){
    if (SS->top == SS->base) {
        return 0;
    }
    printf("%d \n",SS->top->elem);
    SqNode *ss = SS->top->next;
    free(SS->top);
    SS->top = ss;
    return 1;
}


int PushStack(SqStack *SS, int e)
{
    SqNode *SN = (SqNode *)malloc(sizeof(SqNode));
    if (!SN) {
        printf("内存申请失败!");
        return 0;
    }
    SN->elem = e;
    SN->next = SS->top;
    SS->top = SN;
    return 1;
}




