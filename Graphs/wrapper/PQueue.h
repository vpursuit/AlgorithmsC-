//
//  PQueue.h
//  Homework1
//
//  Created by Peter Trebing on 08.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PQueue : NSObject

-(instancetype)init;
-(void)insert:(unsigned int)e priority:(double)p;
-(void)pop;
-(unsigned int)top;
-(BOOL)contains:(unsigned int)e;
-(unsigned long)size;
-(void)chgPriority:(unsigned int)e priority:(double)p;

@end
