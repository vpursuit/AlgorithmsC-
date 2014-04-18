//
//  UF.h
//  Union find
//
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__UF__
#define __Homework1__UF__

#include <vector>

#include <iostream>


class UF {
    
public:
    UF(unsigned N);
    
    void join(unsigned p, unsigned q); //add connection between p and q
    unsigned find(unsigned p); // component identified for p (0...N)
    bool connected(unsigned p, unsigned q); // return true if p and q belong to the same component
    unsigned count(); // number of components
    
private:
    std::vector<unsigned> id;
    std::vector<short> rank;
    unsigned int ucount;
    
};

#endif /* defined(__Homework1__UF__) */
