#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
// Order added:
// The pixel to the right, (x + 1),
// The pixel below, (y + 1), and
// The pixel to the left, (x - 1).
// The pixel above, (y - 1),
DFS::DFS(const PNG & png, const Point & start, double tolerance): start_(start), image_(png), tolerance_(tolerance) {  
  /** @todo [Part 1] */
  add(start_);
  
  std::vector<bool> boolean;
  for (size_t i = 0; i < image_.height(); i++) {
    boolean.push_back(false);
  }
  for (size_t j = 0; j < image_.width(); j++) {
    seen.push_back(boolean);
  }
}



/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(image_, start_, tolerance_, this, seen);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();  
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  stack.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point point = stack.top();
  stack.pop();
  return point;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return stack.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return stack.empty();
}
