//author: Matteo Mantese
 
template <class T>
void AVLtree<T>::rebalance(AVLnode<T> *n) {
    setBalance(n);
 
    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }
 
    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *a) {
    AVLnode<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;
 
    if (a->right != NULL)
        a->right->parent = a;
 
    b->left = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *a) {
    AVLnode<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;
 
    if (a->left != NULL)
        a->left->parent = a;
 
    b->right = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateLeftThenRight(AVLnode<T> *n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateRightThenLeft(AVLnode<T> *n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}
 
template <class T>
int AVLtree<T>::height(AVLnode<T> *n) {
    if (n == NULL)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}
 
template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *n) {
    n->balance = height(n->right) - height(n->left);
}
 
template <class T>
void AVLtree<T>::print(AVLnode<T> *n) 
{
    if (n != NULL) 
    {
        print(n->left);
        std::cout << n->key << endl;
        print(n->right);
    }
}
 
template <class T>
AVLtree<T>::AVLtree(void) : root(NULL) {}
 
template <class T>
AVLtree<T>::~AVLtree(void) {
    delete root;
}
 
template <class T>
bool AVLtree<T>::insert(T key) {
    if (root == NULL) {
        root = new AVLnode<T>(key, NULL);
    }
    else 
    {
        AVLnode<T> *n = root, *parent;
         while (true) 
         {
            if (n->key == key)
                return false;
            parent = n;
            bool goLeft = n->key > key;
            n = goLeft ? n->left : n->right;
 
            if (n == NULL)
            {
                if (goLeft)
                {
                    parent->left = new AVLnode<T>(key, parent);
                }
                else
                {
                    parent->right = new AVLnode<T>(key, parent);
                }
 
                rebalance(parent);
                break;
            }
        }
    }
    return true;
}
 
template <class T>
void AVLtree<T>::deleteKey(const T delKey) {
    if (root == NULL)
        return;
    AVLnode<T>
        *n       = root,
        *parent  = root,
        *delNode = NULL,
        *child   = root;
 
    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            delNode = n;
    }
 
    if (delNode != NULL) {
        delNode->key = n->key;
 
        child = n->left != NULL ? n->left : n->right;
 
        if (root->key == delKey) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            rebalance(parent);
        }
    }
}
 
template <class T>
void AVLtree<T>::print() 
{
    print(root);
    std::cout << std::endl;
}

template <class T>
T& AVLtree<T>::find(T key, T* base) 
{
    if (root == NULL) {
        return *base;
    }
    else 
    {
        return find(key, base, root);
    }
}

template <typename T>
T& AVLtree<T>::find(T key, T* base, AVLnode<T> *node)
{
    AVLnode<T> *n = node;
    if (n->key == key)
    {
        return n->key;
    }
    bool goLeft = n->key > key;
    n = goLeft ? n->left : n->right;

    if (n == NULL)
    {
        return *base;
    }
    else
    {
        return find(key, base, n);
    }
}

template <typename T>
T *AVLtree<T>::operator[](T key)
{
	if (root == NULL)
	{
		return nullptr;
	}
	else
	{
		return opHelper(key, root);
	}
}

template <typename T>
T *AVLtree<T>::opHelper(T key, AVLnode<T> *node)
{
	AVLnode<T> *n = node;
    if (n->key == key)
    {
        return &n->key;
    }
    bool goLeft = n->key > key;
    n = goLeft ? n->left : n->right;

    if (n == NULL)
    {
        return nullptr;
    }
    else
    {
        return opHelper(key, n);
    }
}