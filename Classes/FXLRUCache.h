//
//  FXLRUCache.h
//
//  Created by Zeacone on 16/4/7.
//  Copyright © 2016年 zeacone. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LRUCacheNode : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, strong) LRUCacheNode *prev;
@property (nonatomic, strong) LRUCacheNode *next;

@end

@interface FXLRUCache : NSObject

/**
 *  用以存放缓存数据的可变字典
 */
@property (nonatomic, strong) NSMutableDictionary *caches;

/**
 *  链表的首节点
 */
@property (nonatomic, strong) LRUCacheNode *head;

/**
 *  链表的尾节点
 */
@property (nonatomic, strong) LRUCacheNode *tail;

/**
 *  缓存的容量大小
 */
@property (nonatomic, assign) NSInteger capacity;

/**
 *  缓存已使用的容量大小
 */
@property (nonatomic, assign) NSInteger count;

//////////////////////////////////////////////
//////////////////////////////////////////////

/**
 *  将缓存设计为单例模式
 *
 *  @return 返回缓存的单例
 */
+ (FXLRUCache *)defaultCache;

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
