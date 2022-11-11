
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
#include <cstddef>

template <class T, class Compare>
class heap;

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
<<<<<<< HEAD
    return 2*currentIdx + 1;
=======
    return 0;
>>>>>>> release/main
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
<<<<<<< HEAD
    return 2*currentIdx + 2;
=======
    return 0;
>>>>>>> release/main
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
<<<<<<< HEAD
    return std::floor((currentIdx - 1)/2);
=======
    return 0;
>>>>>>> release/main
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
<<<<<<< HEAD
    if (leftChild(currentIdx) < _elems.size()) {
        return true;
    }
=======
>>>>>>> release/main
    return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
<<<<<<< HEAD

    if ((leftChild(currentIdx) + 1) >= _elems.size()) {
        return leftChild(currentIdx);
    } 
    if (higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])) {
        return leftChild(currentIdx);
    } else {
        return rightChild(currentIdx);
    }
=======
    return 0;
>>>>>>> release/main
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
<<<<<<< HEAD
    if (!hasAChild(currentIdx)) {
        return;
    }
    size_t minChildIndex = maxPriorityChild(currentIdx);
    if (_elems[currentIdx] > _elems[minChildIndex]) {
        std::swap(_elems[currentIdx], _elems[minChildIndex]);
        heapifyDown(minChildIndex);
    }
=======
>>>>>>> release/main
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) 
{
    // @TODO Construct a heap using the buildHeap algorithm
<<<<<<< HEAD
    //_elems = elems;
    for (size_t i = 0; i < elems.size(); i++) {
        _elems.push_back(elems[i]);
    }
    for (int i = _elems.size() - 1; i >= 0; i--) {
        heapifyDown(i);
    }
   
=======
>>>>>>> release/main
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
<<<<<<< HEAD
    T min = _elems[0];
    std::swap(_elems[0], _elems[_elems.size() - 1]);
    _elems.pop_back();
    heapifyDown(0);
    return min;
=======
    return T();
>>>>>>> release/main
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
<<<<<<< HEAD
    return _elems[0];
=======
    return T();
>>>>>>> release/main
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
<<<<<<< HEAD
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
=======
>>>>>>> release/main
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
<<<<<<< HEAD
    _elems[idx] = elem;
    if (idx != 0 && higherPriority(elem, _elems[parent(idx)])) {
        heapifyUp(idx);
    } else {
        heapifyDown(idx);
    }
=======
>>>>>>> release/main
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
<<<<<<< HEAD
    return _elems.size() == 0;
=======
    return true;
>>>>>>> release/main
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
