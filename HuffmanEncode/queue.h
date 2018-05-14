//
//  queue.h
//  HuffmanEncode
//
//  Created by 吴孜健 on 2018/5/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//
#pragma once
#ifndef queue_h
#define queue_h


#define MAX_SZ 256
#define TYPE htNode *
#include <stdio.h>
#include "huffman.h"

typedef struct _pQueueNode{
    TYPE val;/**<树节点*/
    unsigned int priority;//权重
    struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue{
    unsigned int size;
    pQueueNode *first;//指向queue的头指针
}pQueue;

void initPQueue(pQueue **queue);
void addPQueue(pQueue **queue,TYPE val,unsigned int priority);
TYPE getQueue(pQueue **queue);

#endif /* queue_h */
