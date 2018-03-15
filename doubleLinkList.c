//
//  main.c
//  doubleLinkList
//
//  Created by 吴孜健 on 2018/3/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prior;
}Node, *doubleLinkList;

//创建双向链表
doubleLinkList Create_DL(void);

//打印链表
void Traverse_DL(doubleLinkList DHead);

//判断链表是否为空
int IsEmpty_DL(doubleLinkList DHead);

//计算链表长度
int GetLength_DL(doubleLinkList DHead);

//向链表插入节点
int Insert_DL(doubleLinkList DHead, int pos, int data);

//从链表删除节点
int Delete_DL(doubleLinkList DHead, int pos);

//删除整个链表，释放内存
void FreeMemory(doubleLinkList *DHead);

int main(int argc, const char * argv[]) {
    
    int flag = 0, length = 0;
    int position = 0, value = 0;
    doubleLinkList head = NULL;
    
    head = Create_DL();
    
    flag = IsEmpty_DL(head);
    if (flag)
        printf("双向链表为空！\n");
    else
    {
        length = GetLength_DL(head);
        printf("双向链表的长度为：%d\n", length);
        Traverse_DL(head);
    }
    
    printf("请输入要插入节点的位置和元素值(两个数用空格隔开)：");
    scanf("%d %d", &position, &value);
    flag = Insert_DL(head, position, value);
    if (flag)
    {
        printf("插入节点成功！\n");
        Traverse_DL(head);
    }
    else
        printf("插入节点失败！\n");
    
    flag = IsEmpty_DL(head);
    if (flag)
        printf("双向链表为空，不能进行删除操作！\n");
    else
    {
        printf("请输入要删除节点的位置：");
        scanf("%d", &position);
        flag = Delete_DL(head, position);
        if (flag)
        {
            printf("删除节点成功！\n");
            Traverse_DL(head);
        }
        else
            printf("删除节点失败！\n");
    }
    
    FreeMemory(&head);
    if (NULL == head)
        printf("已成功删除双向链表，释放内存完成！\n");
    else
        printf("删除双向链表失败，释放内存未完成！\n");
    
    return 0;
    
    return 0;
}

doubleLinkList Create_DL()
{
    int i, length = 0,data = 0;
    doubleLinkList DTail = NULL, D_NEW = NULL;
    doubleLinkList DHead = (doubleLinkList)malloc(sizeof(Node));
    if (NULL == DHead) {
        printf("内存分配失败");
        exit(0);
    }
    DHead->data = 0;
    DHead->prior = NULL;
    DHead->next = NULL;
    DTail = DHead;
    
    printf("输入要创建的链表的长度");
    scanf("%d",&length);
    
    for (i = 1; i < length+1; i++) {
        D_NEW = (doubleLinkList)malloc(sizeof(Node));
        if (D_NEW == NULL) {
            exit(0);
        }
        printf("请输入第%d个元素的值",i);
        scanf("%d",&data);
        
        D_NEW->data = data;
        D_NEW->next = NULL;
        D_NEW->prior = DTail;
        DTail->next = D_NEW;
        DTail = D_NEW;
    }
    return DHead;
}

void Traverse_DL(doubleLinkList DHead){
    doubleLinkList L = DHead->next;
    printf("打印链表:");
    while (L != NULL) {
        printf("%d \n",L->data);
        L = L->next;
    }
    
}


int IsEmpty_DL(doubleLinkList DHead)
{
    doubleLinkList L = DHead->next;
    if (L == NULL) {
        return 1;
    }else{
        return 0;
    }
}

//计算链表长度
int GetLength_DL(doubleLinkList DHead)
{
    int j = 0;
    doubleLinkList L = DHead->next;
    while (L != NULL) {
        j++;
        L = L->next;
    }
    return j;
    
}

//向链表插入节点
int Insert_DL(doubleLinkList DHead, int pos, int data)
{
    int j = 0;
    doubleLinkList s = NULL;
    if (pos > 0 && pos < GetLength_DL(DHead)+2) {
        s = (doubleLinkList)malloc(sizeof(Node));
    }else{
        return 0;
    }
    doubleLinkList L = DHead->next;
    while (L != NULL && j < pos-1) {
        L = L->next;
        j++;
    }
    s->data = data;
    if (pos == GetLength_DL(DHead)+1) {
        L->next = s;
        s->prior = L;
        s->next = s;
    }else if (pos == 1){
        DHead->next = s;
        s->next = L;
        s->prior = DHead;
    }else{
        s->next = L;
        L->prior->next = s;
        s->prior = L->prior;
        L->prior = s;
    }
    
    return 1;
}

//从链表删除节点
int Delete_DL(doubleLinkList DHead, int pos)
{
    if (pos <= 0 && pos > GetLength_DL(DHead)) return 0;
    int j = 0;
    doubleLinkList L = DHead->next;
    while (L != NULL && j < pos-1) {
        L = L->next;
        j++;
    }
    if (pos == 1) {
        DHead->next = L->next;
    }else if (pos == GetLength_DL(DHead)){
        L->prior->next = L->prior;
    }else{
        L->prior->next = L->next;
        L->next->prior = L->prior;
    }
    free(L);
    return 1;
}

void FreeMemory(doubleLinkList *DHead)
{
    doubleLinkList L = NULL;
    while (*DHead != NULL) {
        L = (*DHead)->next;
        free(*DHead);
        if (NULL != L) {
            L->prior = NULL;
        }
        *DHead = L;
    }
}

