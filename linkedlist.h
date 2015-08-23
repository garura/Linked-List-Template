 // ============================================================================
 // File Name   : linkedlist.h
 // Author      : Chris Jordan
 // Revision History: None
 // Date             Version     Change ID    Author          Comment
 // 7-31-15          1.0         NA           Chris Jordan    None
 //============================================================================

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

namespace cs2b_8 {

   template<class T>
   class linkedList {

   public:
      linkedList();
      linkedList(const linkedList &right);
      ~linkedList();
      linkedList operator= (const linkedList &right);
      int getSize() const;
      void addEntry(const T entryValue);
      bool deleteEntry(const T removedValue);
      T& getEntry(int index) const;
   private:
      struct node {
         T dataValue;
         node* next;
      };
      node* list;
      int size;
      void copyList(const linkedList &right);
      void deleteList();
   };
} // end namespace

#include "linkedlist.cpp"


#endif
