/*
 * =====================================================================================
 *
 *       Filename:  AVLtree.cpp
 *
 *    Description:  My implementation on AVL tree
 *
 *        Version:  1.0
 *        Created:  05/19/2020 01:43:29 PM
 *       Revision:  none *       
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
using std::endl;
using std::cout;

int Max ( int a, int b ) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

class Data {
public:
    int key1 = 0;
    int key2 = 0;
    int key3 = 0;
    int key4 = 0;
};

class Node {
public:
    int itsKey;
    Data data;
    Node* itsLeft;
    Node* itsRight;
    int itsHeight;   
}; 

class AVL {
public:
    Node* root = NULL;
    int count = 0;
    // AVL tree methods
    Node* GetNewNode( int key );
    int GetBalance( Node* N );
    int Height(Node* N );
    Node* RightRotate( Node* x );
    Node* LeftRotate( Node* y );
    Node* Insert( int key, Node* root );
    void PreOrder( Node*& root );
    void Print( Node*& root );
    void TraverseDel ( Node*& root );
    Node* MinNodeValue( Node* root );
    Node* DeleteNode( int key, Node* root );
    ~AVL() {
        TraverseDel(root);
    }
};

Node* AVL::GetNewNode( int key ) {
    Node* node = new Node();
    node->itsKey = key;
    node->data.key1 = key + 1;
    node->data.key2 = key + 2;
    node->data.key3 = key + 3;
    node->data.key4 = key + 4;
    node->itsLeft = NULL;
    node->itsRight = NULL;
    node->itsHeight = 1;
    return node;
}

int AVL::GetBalance( Node* N ) {
    if ( N == NULL ) {
        return 0;
    }
    else {
        return (Height(N->itsLeft) - Height(N->itsRight));
    }
}

int AVL::Height( Node* N ) {
    if ( N == NULL ) {
        return 0;
    }
    else {
        return N->itsHeight;
    }
}

Node* AVL::RightRotate( Node* x ) {
    Node* y = x->itsLeft;
    Node* yRight = y->itsRight;

    y->itsRight = x;
    x->itsLeft = yRight;

    x->itsHeight = Max(Height(x->itsLeft), Height(x->itsRight)) + 1;
    y->itsHeight = Max(Height(y->itsLeft), Height(y->itsRight)) + 1;

    return y;
}

Node* AVL::LeftRotate( Node* y ) {
    Node* x = y->itsRight;
    Node* xLeft = x->itsLeft;

    x->itsLeft = y;
    y->itsRight = xLeft;

    x->itsHeight = Max(Height(x->itsLeft), Height(x->itsRight)) + 1;
    y->itsHeight = Max(Height(y->itsLeft), Height(y->itsRight)) + 1;

    return x;
}

Node* AVL::Insert( int key, Node* root ) {
    if ( root == NULL ) {
        Node* node = GetNewNode(key);
        ++count;
        return node;
    }

    if ( key < root->itsKey ) {
        root->itsLeft = Insert(key, root->itsLeft);
    }
    else if ( key > root->itsKey ) {
        root->itsRight = Insert(key, root->itsRight);
    }
    else {
        return root;
    }

    root->itsHeight = 1 + Max(Height(root->itsLeft), Height(root->itsRight));

    int balance = GetBalance(root);

    // Left Left Case
    if ( balance > 1 && key < root->itsLeft->itsKey ) {
        Node* node = RightRotate(root);
        return node;
    } 
    // Left Right Case
    if ( balance > 1 && key > root->itsLeft->itsKey ) {
        root->itsLeft = LeftRotate(root->itsLeft);
        Node* node = RightRotate(root);
        return node;
    }
    // Right Right Case
    if ( balance < -1 && key > root->itsRight->itsKey ) {
        Node* node = LeftRotate(root);
        return node;
    }
    // Right Left Case
    if ( balance < -1 && key < root->itsRight->itsKey ) {
        root->itsRight = RightRotate(root->itsRight);
        Node* node = LeftRotate(root);
        return node;
    }
    return root;
}

Node* AVL::MinNodeValue( Node* root ) {
    Node* current = root;
    while( current->itsLeft != NULL ) {
        current = current->itsLeft;
    }
    return current;
}

Node* AVL::DeleteNode( int key, Node* root ) {
    if ( root == NULL ) {
        return root;
    }

    if ( key < root->itsKey ) {
        root->itsLeft = DeleteNode( key, root->itsLeft );
    }
    else if ( key > root->itsKey ) {
        root->itsRight = DeleteNode( key, root->itsRight );
    }
    else {
        // the node has no child or only 1 child
        if ( root->itsLeft == NULL || root->itsRight == NULL ) {
            Node* temp;
            if ( root->itsLeft != NULL ) {
                temp = root->itsLeft;
            }
            else {
                temp = root->itsRight;
            }
            // root has no child
            if ( temp == NULL ) {
                temp = root;
                root = NULL;
            }
            // root has 1 child: copy content of the child into root
            else {
                /*
                root->itsKey = temp->itsKey;
                root->itsHeight = temp->itsHeight;
                root->itsLeft = temp->itsLeft;
                root->itsRight = temp->itsRight;
                */
                *root = *temp;
            }
            delete temp;
        }
        else {
            Node* temp = MinNodeValue( root->itsRight );
            root->itsKey = temp->itsKey;
            root->itsRight = DeleteNode(temp->itsKey, root->itsRight);
        }
    }
    // when the root is the only node
    if ( root == NULL ) {
        return root;
    }
    
    root->itsHeight = 1 + Max(Height(root->itsLeft), Height(root->itsRight));

    int balance = GetBalance(root);

    //LL case
    if ( balance > 1 && GetBalance(root->itsLeft) >= 0 ) {
        return RightRotate(root);
    }
    //LR case
    if ( balance > 1 && GetBalance(root->itsRight) < 0 ) {
        root->itsLeft = LeftRotate(root->itsLeft);
        return RightRotate(root);
    }
    //RR case
    if ( balance < -1 && GetBalance(root->itsRight) <= 0 ) {
        return LeftRotate(root);
    }
    //RL case
    if ( balance < -1 && GetBalance(root->itsLeft) > 0 ) {
        root->itsRight = RightRotate(root->itsRight);
        return LeftRotate(root);
    }

    // if not unbalance then just return the root
    return root;
}

void AVL::PreOrder( Node*& root ) {
    if ( root != NULL ) {
        cout << root->itsKey << " "; 
        PreOrder(root->itsLeft);
        PreOrder(root->itsRight);
    }
}

void AVL::TraverseDel( Node*& root ) {
    if ( root != NULL ) {
        TraverseDel(root->itsLeft);
        delete root;
        TraverseDel(root->itsRight);
    }
}

int main(int argc, char** argv) {

    AVL* tree = new AVL();
    tree->root = tree->Insert(7, tree->root);
    tree->root = tree->Insert(8, tree->root);
    tree->root = tree->Insert(15, tree->root);
    tree->root = tree->Insert(27, tree->root);
    tree->root = tree->Insert(49, tree->root);
    tree->root = tree->Insert(10, tree->root);
    tree->root = tree->Insert(30, tree->root);
    tree->root = tree->Insert(45, tree->root);
    tree->root = tree->Insert(60, tree->root);
    tree->root = tree->Insert(25, tree->root);


    tree->PreOrder(tree->root);
    cout << endl;

    tree->root = tree->DeleteNode(10, tree->root);
    tree->PreOrder(tree->root);
    cout << endl;

    tree->root = tree->DeleteNode(30, tree->root);
    tree->PreOrder(tree->root);
    cout << endl;
    
    delete tree;

    return 0;
}
