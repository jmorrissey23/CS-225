/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> release/main
template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
<<<<<<< HEAD
    // head_ -> next = NULL;
    // tail_ -> next = NULL;
    // head_ -> prev = NULL;
    // tail_ -> prev = NULL;
    length_ = 0;
=======
>>>>>>> release/main
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
<<<<<<< HEAD
  return List<T>::ListIterator(head_, tail_);
=======
  return List<T>::ListIterator(NULL);
>>>>>>> release/main
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
<<<<<<< HEAD
  return List<T>::ListIterator(tail_ -> next, tail_);
=======
  return List<T>::ListIterator(NULL);
>>>>>>> release/main
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
<<<<<<< HEAD
  ListNode* temp;
  while (head_ != NULL) {
    temp = head_ -> next;
    delete head_;
    head_ = temp;
  }
=======
>>>>>>> release/main
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
<<<<<<< HEAD
  ListNode* newNode = new ListNode(ndata);
  
  newNode -> next = head_;
  if (head_ != NULL) {
    head_ -> prev = newNode;
  } 
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  head_ = newNode;
  length_++;
=======
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  
  if (head_ != NULL) {
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  

  length_++;

>>>>>>> release/main
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
<<<<<<< HEAD
  ListNode* newNode = new ListNode(ndata);
  if (head_ != NULL) {
    newNode -> prev = tail_;
    tail_ -> next = newNode;
    tail_ = newNode;
  } else {
    tail_ = newNode;
    head_ = newNode;
  }
  length_ ++;
=======
>>>>>>> release/main
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
<<<<<<< HEAD
typename List<T>::ListNode * List<T>::split(ListNode* start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;
  for (int i = 0; i < splitPoint; i++) {
    curr = curr->next;
  }
  if (curr != NULL) {
    if (curr -> prev != NULL) { //if not first element
      curr -> prev -> next= NULL;
      curr->prev = NULL;
    }    
  }
  return curr;
=======
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  for (int i = 0; i < splitPoint || curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return NULL;
>>>>>>> release/main
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
<<<<<<< HEAD
  int counter = 0;
  ListNode* looper = head_;
  while (looper !=  NULL) {
    ListNode* first;
    ListNode* second;
    ListNode* third;
    if (length_ - counter >= 3) {
      first = looper;
      second = looper -> next;
      third = looper -> next -> next;

      first -> next = third -> next;
      third -> next = first;
      if (counter == 0) { //reassigns head
        second -> prev = NULL;
        head_ = second;
      } else {
        second -> prev = looper -> prev;
        looper -> prev -> next = second;
      }
      first -> prev = third;
      if (first -> next != NULL) {
        first -> next -> prev = first;
      } else {
        tail_ = first;
      }
      
      // if (length_ - counter == 0) {
      //   tail_ = first;
      // }
      looper = first -> next;
    } else {
      break;
    }
    counter = counter + 3;
  }
=======
  // @todo Graded in MP3.1
>>>>>>> release/main
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
<<<<<<< HEAD

  ListNode* current = startPoint;
  ListNode* next = endPoint -> next;
  
  bool head = false;
  bool tail = false;
  if (startPoint -> prev == NULL) { // CHECKS IF STARTPOINT IS THE HEAD
    head = true;
  } else {
    startPoint -> prev -> next = endPoint;
  }

  if (endPoint -> next == NULL) { // CHECKS IF ENDPOINT IS TAIL
    tail = true;
  } else {
    endPoint -> next -> prev = startPoint;
  }

  // 1 -> 2 -> 3 -> 4  REVERSE  1 <- 2 <- 3 <- 4
  // 1 -> 2 -> 3 -> 4 REVERSE 1 -> 3 -> 2 -> 4   
  while (current != endPoint) {
    current -> prev = current -> next;
    current -> next = next;
    next = current;
    current = current -> prev;
  }

  endPoint -> prev = startPoint -> prev;
  current -> next = next;
  
  endPoint = startPoint;
  startPoint = current;
  if (head) {
    head_ = startPoint;
  }
  if (tail) {
    tail_ = endPoint;
  }
=======
>>>>>>> release/main
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
<<<<<<< HEAD
  int counter = 0;
  ListNode* looper = head_;
  while (looper != NULL) {
    ListNode* end = looper;
    if(length_ - counter >= n) {
      for (int i = 0; i < n - 1; i++) {
        end = end -> next;
      }
      reverse(looper, end);
    } else {
      for (int i = 0; i < length_ - counter - 1; i++) {
        end = end -> next;
      }
      reverse(looper, end);
    }
    looper = end -> next;
    counter += n;
  }

=======
>>>>>>> release/main
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
<<<<<<< HEAD
  ListNode* first_looper = first;
  ListNode* second_looper = second;
  ListNode* to_return = first;
  while (second_looper != NULL) {
    ListNode* second_next = second_looper -> next;
    while (first_looper != NULL) {
      if (second_looper -> data < first_looper -> data) {
        if (first_looper -> prev == NULL) { // if adding to beginning of list
          second_looper -> next = first_looper;
          first_looper -> prev = second_looper;
          second_looper -> prev = NULL;
          to_return = second_looper;
        } else { // middle of list
          second_looper -> next = first_looper;
          second_looper -> prev = first_looper -> prev;
          first_looper -> prev -> next = second_looper;
          first_looper -> prev = second_looper;
        }
        break;
      } else { //second_looper -> data >= first_looper -> data
        if (first_looper -> next ==  NULL) { //reached end of first_list
          second_looper -> prev = first_looper;
          second_looper -> next = NULL;
          first_looper -> next = second_looper;
          break;
        } else {
          first_looper = first_looper -> next;
        }
      }
    }
    first_looper = second_looper;
    second_looper = second_next;
  }
  return to_return;
=======
  return NULL;
>>>>>>> release/main
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
<<<<<<< HEAD
  if (start == NULL || chainLength == 1) {
    return start;
  } else {
    int first_half = chainLength / 2;

    ListNode* node = split(start, first_half);

    ListNode* head1 = mergesort(start, first_half);
    ListNode* head2  = mergesort(node, chainLength - first_half);
    
    return merge(head1, head2);
  }
=======
  return NULL;
>>>>>>> release/main
}
