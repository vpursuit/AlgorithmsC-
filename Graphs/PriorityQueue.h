//
//  PriorityQueue.h
//  Homework2
//
//  Created by Peter Trebing on 03.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__PriorityQueue__
#define __Homework1__PriorityQueue__

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#endif /* defined(__Homework1__PriorityQueue__) */

class PriorityQueue {
  
    class QueueElement {
        
    public:
        QueueElement(int k = 0, double p = 0.0):key(k), priority(p){};
        
        bool operator==(QueueElement other){
            return this->key == other.key;
        }
        
        int key;
        
        double priority;
    };
    
    class QueueComparator {
        
    public:
        bool operator()(QueueElement& e1, QueueElement& e2)
        {
            // the smallest distance, so use minimum priority
            return e1.priority > e2.priority;
        }
    };
    
public:
    
    PriorityQueue(){};
    
    /*
     * chgPrioirity(PQ, priority): changes the priority (node value) of queue element.
     */
    void chgPriority(int e, double priority);
    
    /*
     * pop(PQ): removes the top element of the queue.
     */
    void pop();
    
    /*
     * contains(PQ, queue_element): does the queue contain queue_element.
     */
    bool contains(int e);
    
    /*
     * insert(PQ, queue_element): insert queue_element into queue
     */
    void insert(int e, double priority);
    
    /*
     * top(PQ):returns the top element of the queue.
     */
    int top();
    
    /*
     * size(PQ): return the number of queue_elements.
     */
    unsigned long size();
    
private:
    vector<QueueElement> pq;
    
};