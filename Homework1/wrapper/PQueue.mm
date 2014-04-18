//
//  PQueue.m
//  Homework1
//
//  Created by Peter Trebing on 08.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#import "PQueue.h"
#include "PriorityQueue.h"

@interface PQueue () {

 PriorityQueue *pq;
    
}

@end

@implementation PQueue

- (instancetype)init {
    
    self = [super init];
    if (self) {
        pq = new PriorityQueue();
    }
    
    return self;
}

- (void)dealloc {
    delete pq;
}

- (void) chgPriority:(unsigned int)e priority:(double) p {
    pq->chgPriority(e, p);
}

- (void) pop {
    pq->pop();
}

- (BOOL) contains:(unsigned int) e{
    return pq->contains(e);
}

- (void) insert: (unsigned int)e priority:(double)p {
    pq->insert(e, p);
}

- (unsigned int) top{
    return pq->top();
}

- (unsigned long) size{
    return pq->size();
}

@end
