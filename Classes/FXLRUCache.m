//
//  FXLRUCache.m
//
//  Created by Zeacone on 16/4/7.
//  Copyright © 2016年 zeacone. All rights reserved.
//

#import "FXLRUCache.h"

const NSInteger CacheCapacity = 40;

@implementation LRUCacheNode

@end

@implementation FXLRUCache

+ (FXLRUCache *)defaultCache {
    
    static FXLRUCache *cache = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        cache = [FXLRUCache new];
        [cache initialConfig];
    });
    return cache;
}

- (void)initialConfig {
    
    self.head = [LRUCacheNode new];
    self.tail = [LRUCacheNode new];
    
    self.head.prev = nil;
    self.head.next = self.tail;
    
    self.tail.prev = self.head;
    self.tail.next = nil;
    
    self.caches = [NSMutableDictionary dictionary];
    self.capacity = CacheCapacity;
    self.count = 0;
}

- (LRUCacheNode *)getNode:(NSString *)key {
    
    LRUCacheNode *node = (LRUCacheNode *)[self.caches objectForKey:key];
    
    if (!node) {
        return nil;
    } else {
        
        [self detachNode:node];
        [self insertNodeToFront:node];
        return node;
    }
}

- (void)setNode:(NSString *)key value:(NSString *)value {
    
    NSAssert(key, @"The key cannot be nil.");
    
    LRUCacheNode *node = [self.caches objectForKey:key];
    
    if (!node) {
        if (self.count == self.capacity) {
            [self removeNode];
        }
        LRUCacheNode *newNode = [LRUCacheNode new];
        newNode.key = key;
        newNode.value = value;
        [self.caches setObject:newNode forKey:key];
        // 只用字典存储缓存数据，双向链表只做索引，而不存储数据，因此将其置空
        newNode.value = nil;
        
        [self insertNodeToFront:newNode];
        ++self.count;
    } else {
        [self detachNode:node];
        node.value = value;
        [self insertNodeToFront:node];
        // 只用字典存储缓存数据，双向链表只做索引，而不存储数据，因此将其置空
        node.value = nil;
    }
}

- (void)removeNode {
    
    LRUCacheNode *node = self.tail.prev;
    [self detachNode:node];
    [self.caches removeObjectForKey:node.key];
    --self.count;
}

- (void)detachNode:(LRUCacheNode *)node {
    
    node.next.prev = node.prev;
    node.prev.next = node.next;
}

- (void)insertNodeToFront:(LRUCacheNode *)node {
    
    node.next = self.head.next;
    node.prev = self.head;
    
    self.head.next = node;
    node.next.prev = node;
}

@end
