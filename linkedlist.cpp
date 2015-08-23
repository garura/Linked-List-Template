
/*
 ============================================================================
 File Name   : linkedlist.cpp
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-31-15          1.0         NA           Chris Jordan    None
 ============================================================================
 */

#include <iostream>
#include <string>
#include <cassert>


namespace cs2b_8 {

   template<class T>
   linkedList<T>::linkedList() {
      list = nullptr;
      size = 0;
   }






   template<class T>
   linkedList<T>::linkedList(const linkedList &right) {
      size = right.size;
      copyList(right);
   }






   template<class T>
   linkedList<T>::~linkedList() {
      deleteList();
   }






   template<class T>
   linkedList<T> linkedList<T>::operator=(const linkedList &right) {
      if (this != &right) {
         size = right.size;
         deleteList();
         copyList(right);
      }
      return *this;
   }






   template<class T>
   int linkedList<T>::getSize() const {
      return size;
   }






   template<class T>
   void linkedList<T>::addEntry(const T entryValue) {
      node* newEntry = new node;
      newEntry->dataValue = entryValue;
      newEntry->next = list;
      list = newEntry;
      size++;
   }






   template<class T>
   bool linkedList<T>::deleteEntry(const T removedValue) {
      if (list->dataValue == removedValue) {
         node* tempList = list;
         list = list->next;
         delete tempList;
         tempList = nullptr;
         size--;
         return true;
      }
      node* curptr = list->next;
      node* prevptr = list;
      while (curptr != nullptr) {
         if (curptr->dataValue == removedValue) {
            prevptr->next = curptr->next;
            delete curptr;
            curptr = nullptr;
            size--;
            return true;
         }
         else {
            prevptr = curptr;
            curptr = curptr->next;
         }
      }
      return false;
   }






   template<class T>
   T& linkedList<T>::getEntry(int index) const {
      assert (index >= 0 && index < getSize());
      node* nodeIndex = list;
      for (int i = 0; i < index; i++) {
         nodeIndex = nodeIndex->next;
      }
      return nodeIndex->dataValue;
   }






   template<class T>
   void linkedList<T>::copyList(const linkedList &right) {
      node* tempList = right.list;
      node* copy = new node;
      copy->next = nullptr;
      node* listHeader = copy;   // linked list header node
      while (tempList != nullptr) {
         copy->dataValue = tempList->dataValue;
         if (tempList->next != nullptr) {  // checks to see if we should allocate another node
            tempList = tempList->next;
            node* nextPtr = new node;
            copy->next = nextPtr;
            copy = nextPtr;
         }
         else {
            tempList = tempList->next;
            copy->next = nullptr;
         }
      }
      list = listHeader;
   }



   template<class T>
   void linkedList<T>::deleteList() {
      if (list != nullptr) {
         node* temp = list;
         while (list != nullptr) {
            temp = list->next;
            delete list;
            list = temp;
         }
      }
   }
}

