//
//  main.c
//  BitTree
//
//  Created by 吴孜健 on 2018/4/24.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

void CreteBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if (' ' == c) {
        *T = NULL;
    }else{
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreteBiTree(&(*T)->lchild);
        CreteBiTree(&(*T)->rchild);
    }
}

void visit(char data, int level)
{
    printf("%c 在第%d层\n",data,level);
}

//遍历二叉树
//____前序遍历
void PreOrderTraverse(BiTree T, int level)
{
    if (T != NULL) {
        visit(T->data,level);
        PreOrderTraverse(T->lchild, level+1);
        PreOrderTraverse(T->rchild, level+1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int level = 1;
    BiTree T = NULL;
    CreteBiTree(&T);
    PreOrderTraverse(T, level);
    
    return 0;
}
