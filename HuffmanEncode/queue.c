//
//  queue.c
//  HuffmanEncode
//
//  Created by 吴孜健 on 2018/5/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include "queue.h"


void initPQueue(pQueue **queue)
{
    (*queue) = (pQueue *)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
    return;
}

void addPQueue(pQueue **queue, TYPE val, unsigned int priority)
{
    if ((*queue)->size == MAX_SZ) {
        printf("\n Queue is full \n");
        return;
    }
    
    pQueueNode *aux = (pQueueNode *)malloc(sizeof(pQueueNode));
    aux->priority = priority;
    aux->val = val;
    
    if ((*queue)->size == 0 || (*queue)->first == NULL) {
        //当队列为空时
        aux->next = NULL;
        (*queue)->first = aux;
        (*queue)->size = 1;
        return;
    }else{
        
        if (priority <= (*queue)->first->priority) {
            //当队列不为空且权值小于等于队列的第一个结点
            aux->next = (*queue)->first;
            (*queue)->first = aux;
            (*queue)->size++;
            return;
        }else{
            pQueueNode *iterator = (*queue)->first;//迭代器
            while (iterator->next != NULL) {
                if (priority <= iterator->next->priority) {
                    //当权值小于等于下一个结点，便插入到下一个结点之前
                    aux->next = iterator->next;
                    iterator->next = aux;
                    (*queue)->size++;
                    return;
                }
                iterator = iterator->next;
            }
            if (iterator->next == NULL) {
                //当权值大于最后的结点，便插入到队列的最后
                aux->next = NULL;
                iterator->next = aux;
                (*queue)->size++;
                return;
            }
        }
    }
}

TYPE getQueue(pQueue **queue)
{
    TYPE returnValue;
    if ((*queue)->size > 0) {
        returnValue  = (*queue)->first->val;
        (*queue)->first = (*queue)->first->next;
        (*queue)->size--;
    }else{
        returnValue = NULL;
        printf("\n Queue is empty");
    }
    
    return returnValue;
}
