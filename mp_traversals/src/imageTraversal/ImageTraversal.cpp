#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"
#include "DFS.h"
/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}



/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() { 
}

ImageTraversal::Iterator::Iterator(const PNG & png, const Point & start, double tolerance, ImageTraversal* type, std::vector<std::vector<bool>> points) {
  /** @todo [Part 1] */
  start_ = start;
  image_ = png;
  current = start;
  tolerance_ = tolerance;
  seen = points;
  traversal = type;
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  seen.at(current.x).at(current.y) = true;
  //Adds point to da stack:
  if (current.x + 1 >= 0 && current.x + 1 < image_.width()) { // pixel to da right
    traversal->add(Point(current.x + 1, current.y));
  }
  if (current.y + 1 >= 0 && current.y + 1 < image_.height()) { // pixel below
    traversal->add(Point(current.x, current.y + 1));
  }
  if (current.x - 1 >= 0 && current.x - 1 < image_.width()) { // pixel to da left
    traversal->add(Point(current.x - 1, current.y));
  }
  if (current.y - 1 >= 0 && current.y - 1 < image_.height()) { // pixel above
    traversal->add(Point(current.x, current.y - 1));
  }   

  Point test = traversal-> peek();
  
  while (!(traversal->empty())) {
    if (seen.at(traversal->peek().x).at(traversal->peek().y) == false && calculateDelta(image_.getPixel(traversal->peek().x, traversal->peek().y), image_.getPixel(start_.x, start_.y)) < tolerance_) {
      current = traversal->pop();
      break;
    } else {
      traversal-> pop();
    }
  }

  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if (traversal-> empty()) { // PROB NEED TO CHANGE
    return false;
  }
  return true;
}

