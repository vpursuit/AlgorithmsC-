//
//  TestPQueue.m
//  Homework1
//
//  Created by Peter Trebing on 09.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "PQueue.h"

@interface TestPQueue : XCTestCase

@end

@implementation TestPQueue

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample
{
    PQueue *pq = [[PQueue alloc] init];
    
    double val = 0.1;
    for (unsigned int i = 0; i < 100; i++) {
        [pq insert:i priority:val];
        val += 0.5;
    }
    
    XCTAssert([pq size] == 100, @"invalid size of queue");
    
    for (unsigned int i = 0; i < 100; i++) {
        XCTAssert([pq contains:i], @"Missing key %d", 0);
    }
    
    val = 0.1;
    for (unsigned int i = 0; i < 100; i++) {
        XCTAssert([pq top] == i, @"Bad minimum");
        val += 0.5;
        [pq pop];
    }
    
  //  XCTFail(@"No implementation for \"%s\"", __PRETTY_FUNCTION__);
}

@end
