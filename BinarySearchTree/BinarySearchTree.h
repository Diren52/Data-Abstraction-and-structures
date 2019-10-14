#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

    /**
     * @class BinarySearchTree
     * @brief A data Structure that stores data in a tree like structure
     *
     * Class T values would be inserted into the tree, after they have been constructed elsewhere.
     *
     * @author Joseph Sigar
     * @version 01
     * @date 10/05/17 Joseph Sigar Created Basic BinarySearchTree class with no templates
     * @date 11/05/17 Joseph Sigar Created a Test data using integer values
     *
     * @author Joseph Sigar
     * @version 02
     * @date 12/05/17 Joseph Sigar Modified and tested the Basic BinarySearchTree.
     *
     * @author Joseph Sigar
     * @version 03
     * @date 12/05/17 Joseph Sigar Modified the class to cater for templates.
     *
     * @author Joseph Sigar
     * @version 04
     * @date 20/05/17 Joseph Sigar added function pointer to the class
     *
     * @author Joseph Sigar
     * @version 05
     * @date 25/05/17 Joseph Sigar tested using the pointers.
     *
     * @author Joseph Sigar
     * @version 06
     * @date 28/05/17 Joseph Sigar incorporated into the assignement
     *
     * @todo Make class into a minimal but complete class
     *
     * @bug N/A at the moment. Needs further testing.
     *
     */

using namespace std;

///Definition of the node
template<class T>
struct nodeType
{
    T data;
    nodeType<T> *left;
    nodeType<T> *right;
};

template <class T>
class BinarySearchTree
{
    ///function pointer variable
    typedef void (*flTyp)(T&);
public:

        /**
         * @brief The Default Constructor
         *
         * This function initializes the root value to null.
         *
         * @return void
         */
    BinarySearchTree();
    // Default constructor

        /**
         * @brief The copy constructor
         *
         * This function copies the values from one BinarySearchTree to another
         *
         * @param otherTree - The other BinarySearchTree to copy from
         *
         * @return void
         */
    BinarySearchTree(const BinarySearchTree<T> &otherTree);
    // Copy constructor

        /**
         * @brief The Destructor of the BinarySearchTree class
         *
         * This function returns the memory allocated back to the system.
         *
         * @return void
         */
    ~BinarySearchTree();
    // Destructor

        /**
         * @brief Inserts an item to the tree.
         *
         * This Function will insert an item into the tree.
         * It will automatically decide to either insert it into the right or left subtree.
         *
         * @param insertItem -  the item to be inserted into the tree.
         *
         * @return void
         */
    void Insert(const T & insertItem);
    // Inserts an item into the tree

        /**
         * @brief Removes an item from the tree
         *
         * This function will remove an item from the tree. If found. otherwise
         * will print to screen an error message.
         *
         * @param itemToRemove - the item that is to be removed from the tree.
         *
         * @return void
         */
    void Remove(const T & itemToRemove);
    // Removes an item from the tree

        /**
         * @brief Arranges the Values into an In-Order traversal sequence
         *
         * This function arranges the values into the tree using the in-order traversal sequence.
         *
         * @param fl - function pointer for retrieval of data
         * @return void
         * @pre Requires there to be data inserted onto the tree before arranging into in-order traversal sequence
         * @post Will arrange the inserted data into a in-order traversal sequence.
         */
    void inOrderTraversal(flTyp fl) const;
    // Arranges the data into an In-Order traversal sequence

        /**
         * @brief Arranges the Values into an post order traversal sequence
         *
         * This function will arrange the values using the post-order traversal sequence.
         *
         * @param fl - function pointer for retrieval of data
         * @return void
         * @pre Requires there to be data in the tree before arranging it
         * @post Will arranged the data into a post-order traversal sequence.
         */
    void postOrderTraversal(flTyp fl) const;
    // Arranges the data into a Post-Order traversal sequence

        /**
         * @brief Arranges the Values into an pre-order traversal sequence
         *
         * This function will arrange the values using the pre-order traversal sequence.
         *
         * @param fl - function pointer for retrieval of data
         * @return void
         * @pre  Requires there to be data in the tree before arranging it
         * @post Will arranged the data into a pre-order traversal sequence.
         */
    void preOrderTraversal(flTyp fl) const;
    // Arranges the data into a pre-order traversal sequence

        /**
         * @brief Checks whether the tree is empty
         *
         * This function will check whether the Tree is empty or not.
         *
         * @return bool
         * @post Returns true if the tree is empty, otherwise will return false
         */
    bool isEmpty() const;
    // Checks whether the tree is empty

    const BinarySearchTree<T> & operator = (const BinarySearchTree<T> &); //doxygen for this

        /**
         * @brief searches the tree for a defined searchItem
         *
         * This function will determine if the searchItem is within the tree
         *
         * @param searchItem -  item to be searched
         *
         * @return bool
         * @post Will return True if the search item is found in the tree, otherwise false.
         */
    bool Search(const T & searchItem) const;
    // Searches the tree for searchItem.

        /**
         * @brief searches the tree for a defined searchItem
         *
         * This function will determine if the searchItem is within the tree and return the item if found
         *
         * @param searchItem -  item to be searched
         *
         * @return T
         * @post Will return object if the search item is found in the tree, otherwise will not return an item.
         */
    const T & SearchAndRetrieve(const T & searchItem);
    // Searches the tree for searchItem and returns an object.

        /**
         * @brief Destroys the binary search tree
         *
         * This function will destroy the binary search tree. Releasing the memory back to the system
         *
         * @return void
         * @post Memory space is released back to the system and root is set to NULL
         */
    void destroyBinarySearchTree();
    // Destroys the binary search tree

private:
    /// The Binary search tree node
    nodeType<T> *root; // the BST node

        /**
         * @brief Inserts a newnode which points to the parent points
         *
         * This function, using recursion, insert a new node into a parents left or right subtree.
         *
         * @param newNode - a new node that points to newNode
         * @param parent -  a node that points to the parent node
         *
         * @return void
         * @post new nodes are either inserted to the left or right of the parents node
         */
    void Insert(nodeType<T> *newNode, nodeType<T> *parent);
    // Inserts a new node to either the left or right of the parent node.

        /**
         * @brief Does an in-order traversal of the tree
         *
         * Function does an in-order traversal of the tree at which someNode points to.
         *
         * @param fl - function pointer for retrieval of data
         * @param someNode - a node that points to some specified node
         * @return void
         * @post The nodes of the tree are arranged in a in-order sequence, at which someNode points to
         */
    void inOrder(flTyp fl, nodeType<T> *someNode) const;
    // Nodes are arranged in in-order sequence


        /**
         * @brief Does a pre-order traversal of the tree
         *
         * Function does a pre-order traversal of the tree at which someNode points to.
         *
         * @param fl - function pointer for retrieval of data
         * @param someNode - a node that points to some specified node
         * @return void
         * @post Nodes are arranged in a pre-order sequence
         */
    void preOrder(flTyp fl, nodeType<T> *someNode) const;
    // Nodes are arranged in a pre-order sequence

        /**
         * @brief Does an post-Order traversal of the tree
         *
         * Function does a post-Order traversal of the tree at which someNode points to,
         *
         * @param fl - function pointer for retrieval of data
         * @param someNode - a node that points to some specified node
         * @return void
         * @post Nodes are arranged in a post-order sequence
         */
    void postOrder(flTyp fl, nodeType<T> *someNode) const;
    // Nodes are arranged in a post-order sequence

        /**
         * @brief Destroys the Binary Tree
         *
         * Function destroys the binary tree at which someNode points to
         *
         * @param someNode - a node that points to some specified node
         * @return void
         * @post Memory is reallocated back to the system at which someNode points at
         * @post Sets root to NULL
         */
    void destroy(nodeType<T>* &someNode);
    // Destroys the Binary Tree and sets the root to NULL

        /**
         * @brief Copies the binary tree
         *
         * Function will copy the binary tree from where the otherTRoot points at.
         *
         * @param copiedTRoot - the node where the copy is being copied to.
         * @param otherTRoot - the node where the copy is being copied from
         * @return void
         * @post copiedTRoot will point to otherTRoot.
         */
    void copyTree(nodeType<T>* &copiedTRoot, nodeType<T>* otherTRoot);
    // Copies one tree to another

        /**
         * @brief Removes specified node from Binary Tree
         *
         * Function will remove a node, pointed by someNode, will be removed from the binary tree.
         *
         * @param someNode - a node that points to a node that will be removed.
         * @return void
         * @post The node (someNode) is removed from the tree.
         */
    void removeFromTree(nodeType<T>* &someNode);
    // Removes a node from the tree
};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> & otherTree)
{
    if (otherTree.root == NULL)
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template<class T>
void BinarySearchTree<T>::copyTree(nodeType<T>* &copiedTRoot, nodeType<T>* otherTRoot)
{
    if (otherTRoot == NULL)
        copiedTRoot = NULL;
    else
    {
        copiedTRoot = new nodeType<T>;

        copiedTRoot->data = otherTRoot->data;

        copyTree(copiedTRoot->left, otherTRoot->left);

        copyTree(copiedTRoot->right, otherTRoot->right);
    }
}

template<class T>
const BinarySearchTree<T> & BinarySearchTree<T>::operator = (const BinarySearchTree<T> & otherTree)
{
    if (this != & otherTree)
    {
        if (root != NULL)
            destroy(root);

        if (otherTree.root == NULL)
            root == NULL;
        else
            copyTree(root, otherTree.root);
    }

    return *this;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    destroy(root);
}

template<class T>
void BinarySearchTree<T>::destroyBinarySearchTree()
{
    destroy(root);
}

template<class T>
void BinarySearchTree<T>::destroy(nodeType<T>* &someNode)
{
    if (someNode != NULL)
    {
        destroy(someNode -> left);
        destroy(someNode -> right);
        delete someNode;
        someNode = NULL;
    }
}

template<class T>
void BinarySearchTree<T>::Insert(const T& insertItem)
{
    nodeType<T> *someNode;
    someNode = new nodeType<T>;
    someNode -> data = insertItem;
    someNode -> right = NULL;
    someNode -> left = NULL;

    if (root == NULL)
    {
        root = someNode;
    }
    else
        Insert(someNode, root);
}

template<class T>
void BinarySearchTree<T>::Insert(nodeType<T> *newNode, nodeType<T> *parent)
{
    if (newNode -> data < parent -> data)
    {
        if (parent -> left == NULL)
            parent -> left = newNode;
        else
            Insert(newNode, parent -> left);
    }
    else if (newNode -> data > parent -> data)
    {
        if (parent -> right == NULL)
            parent -> right = newNode;
        else
            Insert(newNode, parent -> right);
    }
    else
        return;
}

template<class T>
void BinarySearchTree<T>::inOrderTraversal(flTyp fl) const
{
    inOrder(*fl, root);
}

template<class T>
void BinarySearchTree<T>::inOrder(flTyp fl, nodeType<T> *someNode) const
{
    if (someNode != NULL)
    {
        inOrder(*fl, someNode -> left);
        (*fl) (someNode -> data);
        inOrder(*fl, someNode -> right);
    }
}

template<class T>
void BinarySearchTree<T>::postOrderTraversal(flTyp fl) const
{
    postOrder(*fl, root);
}

template<class T>
void BinarySearchTree<T>::postOrder(flTyp fl, nodeType<T> *someNode) const
{
    if (someNode != NULL)
    {
        postOrder(*fl, someNode  -> left);
        postOrder(*fl, someNode -> right);
        (*fl)(someNode -> data);
    }
}

template<class T>
void BinarySearchTree<T>::preOrderTraversal(flTyp fl) const
{
    preOrder(*fl, root);
}

template<class T>
void BinarySearchTree<T>::preOrder(flTyp fl, nodeType<T> *someNode) const
{
    if (someNode != NULL)
    {
        (*fl)(someNode -> data);
        preOrder(*fl, someNode -> left);
        preOrder(*fl, someNode -> right);
    }
}

template<class T>
void BinarySearchTree<T>::Remove(const T & itemToRemove)
{
    nodeType<T> *current;
    nodeType<T> *behind;
    bool found = false;

    if(root != NULL)
    {
        current = root;
        behind = root;

        while (current != NULL && !found)
        {
            if (current -> data == itemToRemove)
                found = true;
            else
            {
                behind = current;

                if (current -> data > itemToRemove)
                    current = current -> left;
                else
                    current = current -> right;
            }
        }

        if (found)
        {
            if (current == root)
                removeFromTree(root);
            else if (behind -> data > itemToRemove)
                removeFromTree(behind -> left);
            else
                removeFromTree(behind -> right);
        }else
            cout << "Item is not in the tree. Cannot be deleted." << endl;
    }
}

template<class T>
void BinarySearchTree<T>::removeFromTree(nodeType<T>* &someNode)
{
    nodeType<T> *current; // pointer to traverse the tree
    nodeType<T>* behind; // pointer behind the current pointer
    nodeType<T>* temp; // temporary pointer that allows deleting of the node

    if (someNode == NULL)
        cout << "Error: NULL" << endl;
    else if (someNode -> left == NULL && someNode -> right == NULL)
    {
        temp = someNode;
        someNode = NULL;
        delete temp;
    }
    else if (someNode -> left == NULL)
    {
        temp = someNode;
        someNode = temp -> right;
        delete temp;
    }
    else if (someNode -> right == NULL)
    {
        temp = someNode;
        someNode = temp -> left;
        delete temp;
    }
    else
    {
        current = someNode -> left;
        behind = NULL;

        while (current -> right != NULL)
        {
            behind = current;
            current = current -> right;
        }

        someNode -> data = current -> data;

        if (behind == NULL)
            someNode -> left = current -> left;
        else
            behind -> right = current -> left;

        delete current;
    }
}

template<class T>
bool BinarySearchTree<T>::Search(const T & searchItem) const
{
    nodeType<T> *someNode;
    bool found = false;

    if (root != NULL)
    {
        someNode = root;

        while (someNode != NULL && !found)
        {
            if (someNode -> data == searchItem)
                found= true;
            else if (someNode -> data > searchItem)
                someNode = someNode -> left;
            else
                someNode = someNode -> right;
        }
    }
    else if (root == NULL)
            cout << "Cannot search an Empty Tree." << endl;

    return found;
}

template<class T>
const T & BinarySearchTree<T>::SearchAndRetrieve(const T & searchItem)
{
    if (Search(searchItem))
        return root -> data;
}

template<class T>
bool BinarySearchTree<T>::isEmpty() const
{
    return (root == NULL);
}
#endif // BINARYSEARCHTREE_H

