//
//  huffman.c
//  HuffmanEncode
//
//  Created by 吴孜健 on 2018/5/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include "huffman.h"
#include "queue.h"

htTree *buildTree(char *str)
{
    int *probability = (int *)malloc(sizeof(int) *256);
    //初始化
    for (int i = 0; i < 256; i++) {
        probability[i] = 0;
    }
    
    //统计待编码的字符串各个字符出现的次数
    for (int j = 0; str[j] != '\0'; j++) {
        probability[str[j]]++;
    }
    
    //定义队列的头指针
    pQueue *huffmanQueue;
    initPQueue(&huffmanQueue);
    
    //填充队列
    for (int k = 0; k < 256; k++) {
        if (probability[k] != 0) {
            htNode *aux = (htNode *)malloc(sizeof(htNode));
            aux->left = NULL;
            aux->right = NULL;
            aux->symbol = (char)k;
            addPQueue(&huffmanQueue, aux, probability[k]);
        }
    }
    free(probability);
    
    //生成赫夫曼树
    while (huffmanQueue->size != 1) {
        unsigned int newPriority = huffmanQueue->first->priority+huffmanQueue->first->next->priority;//取前两个的权值和
        htNode *aux = (htNode *)malloc(sizeof(htNode));
        aux->left = getQueue(&huffmanQueue);
        aux->right = getQueue(&huffmanQueue);
        addPQueue(&huffmanQueue, aux, newPriority);//取出前两个的结点结合之前的权值生成新结点
    }
    htTree *tree = (htTree *)malloc(sizeof(htTree));
    tree->root = getQueue(&huffmanQueue);//当队列的size为1时，为huffmanTree的根节点
    return tree;
}

void traverseTree(htNode *treeNode,hlTable **table,int k, char code[256])
{
    if (treeNode->left == NULL && treeNode ->right == NULL) {
        //此时为叶子结点
        code[k] = '\0';
        hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
        aux->code = (char *)malloc(sizeof(char *) *(strlen(code)+1));
        strcpy(aux->code, code);//将code拷贝进树结点的code
        aux->symbol = treeNode->symbol;
        aux->next = NULL;
        if ((*table)->first == NULL) {
            (*table)->first = aux;
            (*table)->last = aux;//第一个结点
        }else{
            (*table)->last->next = aux;
            (*table)->last = aux;//插入到后面
        }
    }
    if (treeNode->left != NULL) {
        //左子树，code字符串append '0'
        code[k] = '0';
        traverseTree(treeNode->left, table, k+1, code);
    }
    if (treeNode->right != NULL) {
        //右子树，code字符串append '1'
        code[k] = '1';
        traverseTree(treeNode->right, table, k+1, code);
    }
}

hlTable *buildTable(htTree *huffmanTree)
{
    hlTable *table = (hlTable *)malloc(sizeof(hlTable));
    table->first = NULL;
    table->last = NULL;
    
    char code[256];
    int k = 0;//层数
    traverseTree(huffmanTree->root, &table, k, code);
    return table;
}

void encode(hlTable *table, char *stringToEncode)
{
    hlNode *traversal;
    printf("Encodeing ..\n\nInput string:\n%s\n\nEncoded string:\n",stringToEncode);
    for (int i = 0; stringToEncode[i] != '\0'; i++) {
        traversal  = table->first;
        while (traversal-> symbol != stringToEncode[i]) {
            traversal = traversal->next;
            printf("%s",traversal->code);
        }
    }
    printf("\n");
}

void decode(htTree *tree, char *stringToDecode)
{
    htNode *traversal = tree->root;
   printf("\n\nDecoding......\n\nInput string: \n%s\n\nDecoded string: \n",stringToDecode);
    for (int i = 0; stringToDecode[i] != '\0'; i++) {
        if (traversal->left == NULL && traversal->right == NULL) {
            printf("%c",traversal->symbol);
            traversal = tree->root;
        }
        if (stringToDecode[i] == '0') {
            traversal = traversal->left;
        }else if (stringToDecode[i] == '1') {
            traversal = traversal->right;
        }else{
            printf("The input string is not coded correctly!\n");
            return;
        }
    }
    printf("\n\n");
    return;
}



