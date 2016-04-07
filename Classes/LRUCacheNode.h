//
//  LRUCacheNode.h
//
//  Created by Zeacone on 16/4/7.
//  Copyright © 2016年 Zeacone. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LRUCacheNode : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, strong) LRUCacheNode *prev;
@property (nonatomic, strong) LRUCacheNode *next;

@end
