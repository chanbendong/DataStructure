//
//  main.c
//  NodeQueue
//
//  Created by 吴孜健 on 2018/3/19.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *next;
}Node, *QueueNode;

typedef struct {
    QueueNode front;//头指针
    QueueNode rear;//尾指针
}LinkQueue;

void InitQueue(LinkQueue *queue)
{
    queue->front = queue->rear = (QueueNode)malloc(sizeof(Node));
    if (!queue->front) {
        exit(0);
    }
    queue->front->next = NULL;
}

void DestorQueue(LinkQueue *queue){
    while (queue->front) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
}

void EnQueue(LinkQueue *queue, int e){
    Node *p = (QueueNode)malloc(sizeof(Node));
    if (!p) {
        exit(0);
    }
    p->next = NULL;
    p->data = e;
    queue->rear->next = p;
    Node *j = queue->front->next;
    queue->rear = p;
}

void DeQueue(LinkQueue *queue){
    if (queue->front == queue->rear) {
        return;
    }
    Node *p = queue->front->next;
    queue->front->next = p->next;
    if (queue->rear == p) {
        queue->rear = queue->front;
    }
    free(p);
}

void logQueue(LinkQueue *queue)
{
    Node *p = queue->front->next;
    while (p) {
        printf("%d \n",p->data);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkQueue lq;
    InitQueue(&lq);
    printf("请输入要添加的数字:");
    int num;
    int i = 5;
    while (i > 0) {
        scanf("%d",&num);
        EnQueue(&lq, num);
        i--;
    }
    logQueue(&lq);

    DeQueue(&lq);
    logQueue(&lq);

    
    
    return 0;
}
