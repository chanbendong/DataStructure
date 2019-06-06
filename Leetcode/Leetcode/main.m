//
//  main.m
//  Leetcode
//
//  Created by 吴孜健 on 2019/6/6.
//  Copyright © 2019 wuzijian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Node : NSObject

@property (nonatomic, assign) NSNumber *value;
@property (nonatomic, strong) Node *next;

@end

void logLink(Node *head) {
    while (head) {
        NSLog(@"%@",head.value);
        head = head.next;
    }
}

void deleteDuplicateNode(Node *head) {
    if (!head.next.value || !head) {
        return;
    }
    Node *resultHead = head;
    Node *p = resultHead;
    head = head.next;
    while (head) {
        if (p.value.integerValue != head.value.integerValue) {
            p.next = head;
            p = p.next;
            head = head.next;
        }
    }
    p.next = nil;
    logLink(resultHead);
}



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSArray *array = @[@2,@3,@4,@2,@3,@4];
        for (NSInteger i = 0; i < array.count; i++) {
            
        }
        NSLog(@"Hello, World!");
    }
    return 0;
}
