//
//  main.c
//  BiThreadTree
//
//  Created by 吴孜健 on 2018/5/3.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef enum {
    Link,//指向左右孩子的指针
    Thread,//指向前驱后继的线索
}PointerTag;



typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode, *BiThrTree;

BiThrTree pre;//指向之前访问的结点

//创建一棵二叉树，先序遍历输入数据
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    scanf("%c",&c);
    if (' ' == c) {
        *T = NULL;
    }else{
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        
        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}

//中序遍历
void InThreading(BiThrTree T)
{
    if (T) {
        InThreading(T->lchild);
        if (!T->lchild) {
            T->ltag = Thread;
            T->lchild = pre;
        }
        
        if (!pre->rchild) {
            pre->rtag = Thread;
            pre->rchild = T;
        }
        
        pre = T;
        InThreading(T->rchild);
    }
}


void InOrderThreading(BiThrTree *p,BiThrTree T)
{
    *p = (BiThrNode *)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if (!T) {
        (*p)->lchild  = *p;
    }else{
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

int main(int argc, const char * argv[]) {
    
    BiThrTree p = NULL,T = NULL;
    
    CreateBiThrTree(&T);
    
    InOrderThreading(&p, T);
    
    return 0;
}
