//
//  FXLRUDiskCache.h
//
//  Created by Zeacone on 16/4/7.
//  Copyright © 2016年 Zeacone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRUCacheNode.h"

typedef NS_ENUM(NSUInteger, DiskCacheType) {
    DiskCacheTypeFileCache,
    DiskCacheTypeSQLiteCache,
    DiskCacheTypeNmapCache,
};

@interface FXLRUDiskCache : NSObject

@property (nonatomic, assign) DiskCacheType cacheType;

@property (nonatomic, strong) LRUCacheNode *head;

@property (nonatomic, strong) LRUCacheNode *tail;

@property (nonatomic, assign) NSInteger capacity;

@property (nonatomic, assign) NSInteger count;

///////////////////////////////////////////////
///////////////////////////////////////////////

/**
 *  将缓存设计为单例模式
 *
 *  @return 返回缓存的单例
 */
+ (FXLRUDiskCache *)defaultDiskCache;

/**
 *  获取缓存
 *
 *  @param key 缓存节点的key
 *
 *  @return 查找到的缓存节点
 */
- (LRUCacheNode *)getNode:(NSString *)key;

/**
 *  设置缓存
 *
 *  @param key   设置缓存的key
 *  @param value 设置缓存的value
 */
- (void)setNode:(NSString *)key value:(NSString *)value;

/**
 *  分离链表的某个节点
 *
 *  @param node 待分离的节点
 */
- (void)detachNode:(LRUCacheNode *)node;

/**
 *  移除链表中的某个节点
 */
- (void)removeNode;

/**
 *  将链表中的某个节点移到链表的最前端
 *
 *  @param node 待移动的链表节点
 */
- (void)insertNodeToFront:(LRUCacheNode *)node;

@end
