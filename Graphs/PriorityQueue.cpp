//
//  PriorityQueue.cpp
//  Homework2
//
//  Created by Peter Trebing on 03.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include "PriorityQueue.h"


void PriorityQueue::chgPriority(int e, double priority){
    QueueElement element(e, priority);
    vector<QueueElement>::iterator it = find(pq.begin(), pq.end(), element);
    if (it != pq.end()) {
        it->priority = priority;
        make_heap(pq.begin(),pq.end(), QueueComparator());
    }
}

void PriorityQueue::pop(){
    pop_heap(pq.begin(),pq.end(), QueueComparator());
    pq.pop_back();
}

bool PriorityQueue::contains(int e){
    QueueElement element(e);
    vector<QueueElement>::iterator it = find(pq.begin(), pq.end(), element);
    return it != pq.end();
}

void PriorityQueue::insert(int e, double priority){
    if (!this->contains(e)) {
        pq.push_back(QueueElement(e, priority));
        push_heap(pq.begin(),pq.end(), QueueComparator());
    }
}

int PriorityQueue::top(){
    return pq.front().key;
}

unsigned long PriorityQueue::size(){
    return pq.size();
}