#import <Foundation/Foundation.h>
#import "OSCache.h"

typedef void (^ELAFetchCallback)(id);
typedef void (^ELAResultCallback)(id);

// Kurt Arnlund - Ingenious Arts and Technologies LLC - 8/16/2014
// Switched this class to use OSCache for open source caching
@interface ELAWellCached : OSCache

@property (assign, nonatomic, readonly) NSTimeInterval expireDuration;

+ (instancetype)cacheWithDefaultExpiringDuration:(NSTimeInterval)expireInterval;

- (id)objectForKeyedSubscript:(id <NSCopying>)key;
- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

- (void)setObject:(id)obj forKey:(id)key expirationInterval:(NSTimeInterval)expirationDuration;

- (id)fetch:(id)key generateOnMiss:(id (^)(void))handler;
- (id)fetch:(id)key generateOnMiss:(id (^)(void))handler expirationInterval:(NSTimeInterval)interval;
- (void)fetch:(id)key generateOnMissAsync:(void (^)(ELAResultCallback))handler result:(ELAFetchCallback)fetchCallback;
- (void)fetch:(id)key
    generateOnMissAsync:(void (^)(ELAResultCallback))handler
                 result:(ELAFetchCallback)fetchCallback
     expirationInterval:(NSTimeInterval)interval;
@end