/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (first[curDim] == second[curDim]) {
      return first < second;
     }
    return first[curDim] < second[curDim];
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */


      double potential_difference = 0.0;
      double best_distance = 0.0;

      for(int i = 0; i < Dim; i++) {
        potential_difference += pow(target[i] - potential[i],2);
      }
      
      for (int i = 0; i < Dim; i++) {
        best_distance += pow(target[i] - currentBest[i],2);
      }
      
      if (potential_difference == best_distance) {
        return potential < currentBest;
      }
      return potential_difference < best_distance;
}

template <int Dim>
double KDTree<Dim>::Radius(Point<Dim> point1, Point<Dim> point2) const {
  double sum = 0;
  for (int i = 0; i < Dim; i++) {
    sum += (point1[i] - point2[i]) * (point1[i] - point2[i]);
  }
  return sum;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    
  size = 0;
  if (newPoints.size() == 0) { //if the vector of points is empty
    root = NULL;
  } else {
    vector<Point<Dim>> nodes;
    nodes.assign(newPoints.begin(), newPoints.end());
    root = RecursiveConstructor(nodes, 0, newPoints.size() - 1, 0);
  }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::RecursiveConstructor(vector<Point<Dim>>& newPoints, int left, int right, int dimension) {
  int size = newPoints.size();
  if (newPoints.size() == 0 || left > right || right < left || left < 0 || left > size - 1 || right < 0 || right > size - 1) {
    return NULL;
  }
  KDTreeNode* subtree;
  int splitPoint = (left + right) / 2;
  subtree = new KDTreeNode(QuickSelect(newPoints, left, right, splitPoint, dimension % Dim));
  size++;
  subtree -> left = RecursiveConstructor(newPoints, left, splitPoint - 1, (dimension + 1) % Dim);
  subtree -> right = RecursiveConstructor(newPoints, splitPoint + 1, right, (dimension + 1) % Dim);
  return subtree;
}


template <int Dim>
Point<Dim> KDTree<Dim>::QuickSelect(vector<Point<Dim>>& newPoints, int left, int right, int k, int dimension) {
  if (left == right) {
    return newPoints[left];
  }
  int pivotIndex = Partition(newPoints, left, right, k, dimension);
  if (k == pivotIndex) {
    return newPoints[k];
  } else if (k < pivotIndex) {
    return QuickSelect(newPoints, left, pivotIndex - 1, k, dimension);
  } else {
    return QuickSelect(newPoints, pivotIndex + 1, right, k, dimension);
  }
}

template <int Dim>
int KDTree<Dim>::Partition(vector<Point<Dim>>& newPoints, int left, int right, int pivotIndex, int dimension) {
  Point<Dim> pivotValue = newPoints[pivotIndex];
  std::swap(newPoints[pivotIndex], newPoints[right]);
  int storeIndex = left;
  for (int i = left; i < right; i++) {
    if (smallerDimVal(newPoints[i], pivotValue, dimension)) {
      std::swap(newPoints[i], newPoints[storeIndex]);
      storeIndex++;
    }
  }
  std::swap(newPoints[right], newPoints[storeIndex]); //// storeIndex = index of pivotValue
  return storeIndex;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  copy(other);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (this != &rhs) {
    clear(root);
    copy(rhs);
  }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  clear(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
  //query is the target node, we wish to find the point in the tree closes to the target
  std::stack<KDTreeNode*> stack;
  std::set<KDTreeNode*> seen;
  return findNearestNeighbor(query, 0, root, seen) -> point;
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query, int dim, KDTreeNode* current, std::set<KDTreeNode*>& seen) const {
  seen.insert(current);
  if (current -> left == NULL && current -> right == NULL) {
    return current;
  }

  KDTreeNode* best;
  if (smallerDimVal(query, current-> point, dim)) {
    if (current -> left != NULL) {
      best = findNearestNeighbor(query, (dim + 1) % Dim , current -> left, seen);
    } else {
      best = findNearestNeighbor(query, (dim + 1) % Dim , current -> right, seen);
    }
  } else {
    if (current -> right != NULL) {
      best = findNearestNeighbor(query, (dim + 1) % Dim, current-> right, seen);
    } else {
      best = findNearestNeighbor(query, (dim + 1) % Dim, current-> left, seen);
    }
  }

  if (shouldReplace(query, best -> point, current -> point)) {
    best = current;
  }

  double radius = Radius(query, best -> point);
  double splitDist = (current -> point[dim] - query[dim]) * (current -> point[dim] - query[dim]);

  if (radius >= splitDist) {
    KDTreeNode* tempBest = best;
    if (seen.count(current -> left) == 1) {
      if (current -> right != NULL) {
        tempBest = findNearestNeighbor(query, (dim + 1) % Dim, current-> right, seen);
      }
    } else {
      if (current -> left != NULL) {
        tempBest = findNearestNeighbor(query, (dim + 1) % Dim , current -> left, seen);
      }
    }
    if (shouldReplace(query, best -> point, tempBest -> point)) {
      best = tempBest;
    }
  }
  return best;
}





template <int Dim>
void KDTree<Dim>::copy(const KDTree<Dim>& rhs) {
  size = rhs.size;
  root = rhs.root;
}

template <int Dim>
void KDTree<Dim>::clear(KDTreeNode* subroot) {
  if (subroot == NULL) {
    return;
  }
  if (subroot -> left != NULL) {
    clear(subroot -> left);
  }
  if (subroot -> right != NULL) {
    clear(subroot -> right);
  }
  delete subroot;
  //subroot = NULL;
}




