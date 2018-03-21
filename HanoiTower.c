//
//  main.c
//  HanoiTower
//
//  Created by 吴孜健 on 2018/3/19.
//  Copyright © 2018年 吴孜健. All rights reserved.
//

#include <stdio.h>

void hanoi_move(int n, char x, char y, char z);

int main(int argc, const char * argv[]) {
    
    int n;
    printf("请输入汉诺塔的层数:");
    scanf("%d",&n);
    hanoi_move(n, 'x', 'y', 'z');
    return 0;
}

void hanoi_move(int n, char x, char y, char z)
{
    if (1 == n) {
        printf("%c-->%c \n",x, z);
    }else{
        hanoi_move(n-1, x, z, y);
        printf("%c-->%c \n",x,z);
        hanoi_move(n-1, y, x, z);
    }
}
