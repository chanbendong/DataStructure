//
//  main.c
//  HuffmanEncode
//
//  Created by 吴孜健 on 2018/5/14.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>
#include "huffman.h"


int main(int argc, const char * argv[]) {
  
    htTree *codeTree = buildTree("interesting c++!");
    hlTable *codeTable = buildTable(codeTree);
    encode(codeTable, "interesting c!");
    decode(codeTree,"001000111");//解码
    system("pause");
    return 0;
}
