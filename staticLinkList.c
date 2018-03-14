//
//  main.c
//  DataStructure
//
//  Created by 吴孜健 on 2018/3/13.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>


int maxSize = 10;

typedef int ElemType;



typedef struct{
    ElemType data;
    int cur;//为0时表示无指向
}SLinkList[10];

void initSpace_SL(SLinkList space);//创建静态链表

int malloc_SL(SLinkList space);//若链表为非空，则返回分配的结点下标，否则返回0;

void free_SL(SLinkList space, int pos);//将下标为pos的空闲结点回收到链表

void insert_SL(SLinkList space, ElemType elem, int pos);//插入操作

void delete_SL(SLinkList space, int pos);//删除操作

int length_SL(SLinkList space);//获取静态链表的结点长度

void logNum(SLinkList space);//打印数组结点

int main(int argc, const char * argv[]) {
    SLinkList SL;
    initSpace_SL(SL);
    for (int i = 1; i < 5; i++) {
        insert_SL(SL, i, i);
    }
    logNum(SL);
    
    delete_SL(SL, 3);
    logNum(SL);
    return 0;
}

void initSpace_SL(SLinkList space){
    for (int i = 0; i < (maxSize-1); i++) {
        space[i].cur = i+1;
    }
    space[maxSize-1].cur = 0;
//    for (int i = 0; i < maxSize-1; i++) {
//        printf("%d \n",space[i].cur);
//    }
    
}

int malloc_SL(SLinkList space){
    int k = space[0].cur;
    if (k) {
        space[0].cur = space[k].cur;
    }
    return k;
}

void free_SL(SLinkList space, int pos){
    space[pos].cur = space[0].cur;//将空闲结点改为0位的游标
    space[0].cur = pos;//0位游标改为空闲结点
}

int length_SL(SLinkList space)
{
    int i = space[maxSize-1].cur;
    int j = 0;
    while (i) {
        i = space[i].cur;
        ++j;
    }
    return j;
}

void insert_SL(SLinkList space, ElemType elem, int pos){
    if (pos < 1 || pos > length_SL(space)+1) {
        return;
    }
    
    int i = malloc_SL(space);//获取可插入的结点下标
    int k = maxSize-1;
    if (i) {
        space[i].data = elem;
        for (int l = 1; l <= pos-1; l++) {
            k = space[k].cur;//获取pos位置的前一个元素
        }
        
        space[i].cur = space[k].cur;//把第pos前一个元素之前的cur赋值给新元素的cur
        space[k].cur = i;//然后pos前一个元素的cur指向新插入的元素位置
        
        return;
    }
}

void delete_SL(SLinkList space,int pos){
    if (pos < 1 || pos > length_SL(space)) {
        return;
    }
    int k = maxSize-1;
    for (int l = 1; l <= pos-1; l++) {
        k = space[k].cur;//获取删除位置的前一个元素
    }
    int j = space[k].cur;//将要删除元素的下标
    space[k].cur = space[j].cur;//修改删除元素前一位的游标改为删除元素的游标（即后继指针）
    free_SL(space, j);//释放空闲结点
}



void logNum(SLinkList space){
    int k = maxSize-1;
    while (space[k].cur != 0) {
        k = space[k].cur;
        printf("%d \n",k);
    }
}
