/**
 * @file bst.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V BST<K, V>::find(const K& key)
{
<<<<<<< HEAD
    Node* to_return = find(root, key);
    if (to_return == NULL) {
        return V();
    } 
    return to_return -> value;
=======
>>>>>>> release/main
    // your code here
}

template <class K, class V>
struct BST<K, V>::Node* & BST<K, V>::find(Node* & subtree, const K& key)
{
    // Your code here
<<<<<<< HEAD
    
    if (subtree == NULL || subtree -> key == key ) {
        return subtree;
    }
    
    if (subtree -> key > key) {
        return find(subtree -> left, key);
    } 
    return find(subtree -> right, key);
=======
>>>>>>> release/main
}

template <class K, class V>
void BST<K, V>::insert(const K & key, const V & value)
{
<<<<<<< HEAD
    insert (root, key, value);
=======
    // your code here
>>>>>>> release/main
}

template <class K, class V>
void BST<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
<<<<<<< HEAD
    if (subtree == NULL) {
        subtree = new Node(key,value);
    } else if (key == subtree -> key) {
        return;
    } else if (key < subtree -> key) {
        insert(subtree -> left, key, value);
    } else {
        insert(subtree -> right, key, value);
    }

=======
    // your code here
>>>>>>> release/main
}

template <class K, class V>
void BST<K, V>::swap(Node*& first, Node*& second)
{
    // your code here
}

template <class K, class V>
void BST<K, V>::remove(const K& key)
{
    // your code here
}

template <class K, class V>
void BST<K, V>::remove(Node*& subtree, const K& key)
{
    // your code here
}

template <class K, class V>
BST<K, V> listBuild(std::vector<std::pair<K, V>> inList){
    // your code here
<<<<<<< HEAD
    return nullptr;
=======
>>>>>>> release/main
}

template <class K, class V>
std::vector<int> allBuild(std::vector<std::pair<K, V>> inList){
    // your code here
<<<<<<< HEAD
    std::vector<int> to;
    return to;
    
=======
>>>>>>> release/main
}