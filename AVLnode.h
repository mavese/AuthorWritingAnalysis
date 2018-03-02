//author: Matteo Mantese

#ifndef AVLNODE_H_
#define AVLNODE_H_
template <class T>
class AVLnode 
{
public:
    T key;
    int balance;
    AVLnode *left, *right, *parent; 
    AVLnode(T k, AVLnode *p) : key(k), balance(0), parent(p), left(NULL), right(NULL) {}
    ~AVLnode() 
    {
        delete left;
        delete right;
    }
};

#endif