//
//  FXLRUDiskCache.m
//
//  Created by Zeacone on 16/4/7.
//  Copyright © 2016年 Zeacone. All rights reserved.
//

#import "FXLRUDiskCache.h"

const NSInteger CacheCapacity = 100;

@implementation FXLRUDiskCache

+ (FXLRUDiskCache *)defaultDiskCache {
    
    static FXLRUDiskCache *cache = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        cache = [FXLRUDiskCache new];
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
    
    self.capacity = CacheCapacity;
    self.count = 0;
    
    self.cacheType = DiskCacheTypeFileCache;
    // 磁盘缓存使用SQLite来进行存储，周末再写。
}

@end
