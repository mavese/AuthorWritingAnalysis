//author: Matteo Mantese

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include "AVLnode.h"
#include <algorithm>
#include <iostream>

template <class T>
class AVLtree {
public:
    AVLtree(void);
    ~AVLtree(void);
    bool insert(T key);
    void deleteKey(const T key);
    void print();
    T& find(T, T*);
 	T *operator[](T);
private:
    AVLnode<T> *root;
    AVLnode<T>* rotateLeft( AVLnode<T> *a );
    AVLnode<T>* rotateRight( AVLnode<T> *a );
    AVLnode<T>* rotateLeftThenRight( AVLnode<T> *n );
    AVLnode<T>* rotateRightThenLeft( AVLnode<T> *n );
    void rebalance( AVLnode<T> *n );
    int height( AVLnode<T> *n );
    void setBalance( AVLnode<T> *n );
    void print( AVLnode<T> *n );
    void clearNode( AVLnode<T> *n );
    T& find(T, T*, AVLnode<T> *n);
    T *opHelper(T, AVLnode<T> *n);
};
#include "AVLTree.cpp"
#endif