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

struct ListNode {
     int val;
    struct ListNode *next;
 };

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
    while (head != nil) {
        if (p->value != head->value) {
            p->next = head;
            p = p->next;
         
        }
        head = head->next;
    }
    p->next = NULL;
    logLink(resultHead);
}


void completeDeleteDuplicateNode(Node *head) {
    if (head == nil || !head->next->value) {
        return;
    }
   
    Node *resultHead = NULL;//记录结果链表的头节点
    Node *p = NULL;//记录结果链表的尾节点
    Node *last_repeat = NULL;//记录上次重复的节点位置
    
    while (head != NULL) {
        //如果有下个节点并且不等于下个节点或者尾节点
        if ((head->next && head->value != head->next->value) || head->next == NULL) {
            //上次重复的节点为空，或者上次重复的节点跟现在的节点值不同
            if (last_repeat == NULL || last_repeat->value != head->value) {
                if (p == NULL) {
                    resultHead = head;
                    p = resultHead;
                } else {
                    //使其永远指向结果链表的尾节点
                    p->next = head;
                    p = p->next;
                }
            }
        } else {
            last_repeat = head;
        }
        head = head->next;
    }
    
    if (p) {
        p->next = NULL;
    }
    logLink(resultHead);
}

void mergeTwoSortedList(Node *head1, Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return;
    }
    Node *resultHead = NULL;
    Node *p = NULL;
    if (head2->value < head1->value) {
        p = head2;
        head2 = head2->next;
    } else {
        p = head1;
        head1 = head1->next;
    }
    resultHead = p;
    while (head1 != NULL && head2 != NULL) {
        if (head1->value < head2->value) {
            p->next = head1;
            head1 = head1->next;
        } else {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    
    if (head1 == NULL) {
        p->next = head2;
    } else {
        p->next = head1;
    }
    logLink(resultHead);
}

void addTwoNumbers(Node *head1,Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        return;
    }
    Node *resultHead = NULL;
    Node *p = NULL;
    BOOL needCarry = NO;
    while (head1 != NULL && head2 != NULL) {
        if (p == NULL) {
            p = head1;
            p->value = head1->value+head2->value;
            if (p->value>=10) {
                p->value = p->value-10;
                needCarry = YES;
            }else {
                needCarry = NO;
            }
            resultHead = p;
        } else {
            p->next->value = head1->value+head2->value+(needCarry?1:0);
            if (p->next->value>=10) {
                p->next->value = p->next->value-10;
                needCarry = YES;
            } else {
                needCarry = NO;
            }
            p = p->next;
        }
        head2 = head2->next;
        head1 = head1->next;
    }
    if (head1 == NULL) {
        p->next = head2;
        while (head2 != NULL && head2->next != NULL) {
            p->next->value = head2->value+(needCarry?1:0);
            if (p->next->value >= 10) {
                p->next->value = p->next->value-10;
                needCarry = YES;
            } else{
                needCarry = NO;
            }
            head2 = head2->next;
        }
        //此时已经是最后一个节点了
        
        head2->value = head2->value+(needCarry?1:0);
        if (head2->value>=10) {
            head2->value = head2->value-10;
            head2->next = (Node *)malloc(sizeof(Node));
            head2->next->value = 1;
            head2->next->next = NULL;
        }
        
    }
    if (head2 == NULL) {
        p->next = head1;
        while (head1 != NULL && head1->next != NULL) {
            p->next->value = head1->value+(needCarry?1:0);
            if (p->next->value >= 10) {
                p->next->value = p->next->value-10;
                needCarry = YES;
            } else {
                needCarry = NO;
            }
            head1 = head1->next;
        }
        //此时已经是最后一个节点了
        
        head1->value = head1->value+(needCarry?1:0);
        if (head1->value>=10) {
            head1->value = head1->value-10;
            head1->next = (Node *)malloc(sizeof(Node));
            head1->next->value = 1;
            head1->next->next = NULL;
        }
    }
   p = p->next;
 
    logLink(resultHead);
}


void reverseLinkList(Node *head) {
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL) {
        Node *curTmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = curTmp;
       
    }
    
    
    logLink(pre);
   
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}


Node *createList(int array[],int len) {
    Node *pre = (Node *)malloc(sizeof(Node));
    Node *head = (Node *)malloc(sizeof(Node));
    for (NSInteger i = 0; i < len; i++) {
        Node *node = (Node *)malloc(sizeof(node));
        node->value = array[i];
        pre->next = node;
        pre = node;
        if (!i) {
            head = pre;
        }
    }
    pre->next = NULL;
    return head;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int array[4] = {2,3,5,6};
//        int arraya[4] = {4,7,7,7};
        Node *head = createList(array,4);
//        Node *head2 = createList(arraya,4);
        
//        deleteDuplicateNode(head);
//        completeDeleteDuplicateNode(head);
//        mergeTwoSortedList(head, head2);
//        addTwoNumbers(head, head2);
        reverseLinkList(head);
        NSLog(@"Hello, World!");
    }
    return 0;
}
