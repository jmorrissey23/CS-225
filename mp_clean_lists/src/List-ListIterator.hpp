
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in MP3.1
    ListNode* position_;
<<<<<<< HEAD
    ListNode* tail_;

  public:
    ListIterator() : position_(NULL), tail_(NULL) { }
    ListIterator(ListNode* x, ListNode* y) : position_(x), tail_(y) { }
=======

  public:
    ListIterator() : position_(NULL) { }
>>>>>>> release/main
    ListIterator(ListNode* x) : position_(x) { }


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
<<<<<<< HEAD
        position_ = position_ -> next;
=======
>>>>>>> release/main
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        // @TODO: graded in MP3.1
        ListNode* temp = position_;
        position_ = position_->next;
<<<<<<< HEAD
        return ListIterator(temp, tail_);
=======
        return ListIterator(NULL);
>>>>>>> release/main
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // @TODO: graded in MP3.1
<<<<<<< HEAD
        if (position_ == NULL) {
            position_ = tail_;
            return *this;
        }
        position_ = position_ -> prev;
=======
>>>>>>> release/main
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        // @TODO: graded in MP3.1
<<<<<<< HEAD

        if (position_ == NULL) {
            position_ = tail_;
            return ListIterator(position_, tail_);
        }
        ListNode* temp = position_;
        position_ = position_ -> prev;
        return ListIterator(temp, tail_);
=======
        return ListIterator();
>>>>>>> release/main
    }

    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in MP3.1
<<<<<<< HEAD
        if (position_ == rhs.position_) {
            return false;
        }
        return true;
    }

    bool operator==(const ListIterator& rhs) {
        return !(position_ != rhs.position_);
=======
        return false;
    }

    bool operator==(const ListIterator& rhs) {
        return !(*this != rhs);
>>>>>>> release/main
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
