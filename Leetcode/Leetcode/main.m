//
//  main.m
//  Leetcode
//
//  Created by 吴孜健 on 2019/6/6.
//  Copyright © 2019 wuzijian. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct Node {
    int value;
    struct Node *next;
}Node;

void logLink(Node *head) {
    while (head != NULL) {
        NSLog(@"%d",head->value);
        head = head->next;
    }
}

void deleteDuplicateNode(Node *head) {
    if (head == nil || !head->next->value) {
        return;
    }
    Node *resultHead = head;
    Node *p = resultHead;
    head = head->next;
    while (head != NULL) {
        if (p->value != head->value) {
            p->next = head;
            p = p->next;
         
        }
        head = head->next;
    }
    p->next = NULL;
    logLink(resultHead);
}



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int array[8] = {2,3,3,3,4,4,4,5};
        Node *pre = (Node *)malloc(sizeof(Node));
        Node *head = (Node *)malloc(sizeof(Node));
        for (NSInteger i = 0; i < 8; i++) {
            Node *node = (Node *)malloc(sizeof(node));
            node->value = array[i];
            pre->next = node;
            pre = node;
            if (!i) {
                head = pre;
            }
        }
        pre->next = NULL;
        
        deleteDuplicateNode(head);
        NSLog(@"Hello, World!");
    }
    return 0;
}
