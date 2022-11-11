/* Your code here! */
#include <dsets.h>


void DisjointSets::addelements(int num) {
    //have the root value be the size of the up-tree
    for (int i = 0; i < num; i++) {
        elements.push_back(-1);
    }
}

int DisjointSets::find(int elem) {
    if (elements[elem] < 0) {
        return elem;
    } else {
        elements[elem] = find(elements[elem]);
        return elements[elem];
    }
}

void DisjointSets::setunion(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);

    int newSize = elements[root1] + elements[root2];

    if (abs(elements[root1]) < abs(elements[root2])) { // if the first set is smaller than the second
        elements[root1] = root2;
        elements[root2] = newSize;
    } else { // if the second set is smaller than the second
        elements[root2] = root1;
        elements[root1] = newSize;
    }
}

int DisjointSets::size(int elem) {
    return abs(elements[find(elem)]);
}