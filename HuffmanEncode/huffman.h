//
//  huffman.h
//  HuffmanEncode
//
//  Created by 吴孜健 on 2018/5/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#pragma once
#ifndef huffman_h
#define huffman_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _htNode{
    char symbol;
    struct _htNode *left,*right;
}htNode;

typedef struct _htTree{
    htNode *root;
}htTree;

typedef struct _hlNode{
    char symbol;//字符 例如'a'
    char *code;//字符的编码 例如‘0001’
    struct _hlNode *next;
}hlNode;

typedef struct _hlTable{
    hlNode *first;
    hlNode *last;
}hlTable;

htTree *buildTree(char *str);
hlTable * buildTable(htTree *huffmanTree);
void encode(hlTable *table, char *stringToEncode);
void decode(htTree *tree, char *stringToDecode);

#endif /* huffman_h */
