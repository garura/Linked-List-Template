//
//  client.cpp
//  linkedlist
//
//  Created by Chris on 8/1/15.
//  Copyright (c) 2015 Chris. All rights reserved.
//

#include <stdio.h>
#include "linkedlist.h"

using namespace cs2b_8;

int main() {
   linkedList<int> tester;
   tester.addEntry(5);
   std::cout << tester.getEntry(0);
}