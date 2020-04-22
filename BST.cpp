#include <iostream>
using namespace std;

class BstNode {
public:
    int data;
    BstNode* left;
    BstNode* right;
};

class BstTree {
public:
    int cnt = 0;
    BstNode* root = nullptr;
    BstNode* getNewNode ( int data );
    void Insert( BstNode*& root, int data );
    bool Search( BstNode*& root, int data );
    void Traverse ( BstNode*& root );
    void TraverseDel ( BstNode*& root );
    void Delete ( BstNode*& root, int data );
    BstNode* FindMin ( BstNode* root );
    ~BstTree()
    {
        TraverseDel( root );
    } 
};

BstNode* BstTree::FindMin ( BstNode* root )
{
    while ( root->left != nullptr )
        root = root->left;
    return root;
}

BstNode* BstTree::getNewNode ( int data )
{
    BstNode* node = new BstNode();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}
void BstTree::Insert( BstNode*& root, int data )
{
    if ( root == nullptr )
        root = getNewNode( data );
    else if ( data < root->data )
        Insert( root->left, data ); 
    else 
        Insert( root->right, data );
    cnt++;
}
bool BstTree::Search( BstNode*& root, int data )
{
    // break condition 
    if ( root == nullptr ) return false;
    else if ( root->data == data ) return true;
    // recursiving 
    else if ( data < root->data ) return Search( root->left, data );
    else return Search( root->right, data );
}
void BstTree::Traverse ( BstNode*& root )
{
    if ( root == nullptr ) return;
    else
    {
        Traverse ( root->left );
        cout << root->data << " ";
        Traverse ( root->right );
    }
}
void BstTree::TraverseDel ( BstNode*& root )
{
    if ( root == nullptr ) return;
    else
    {
        TraverseDel ( root->left );
        delete root;
        TraverseDel ( root->right );
    }
}

void BstTree::Delete( BstNode*& root, int data )
{
    if ( root == nullptr ) return; 
    else if ( data < root->data ) Delete( root->left, data );
    else if ( data > root->data ) Delete( root->right, data );
    else
    {   //case 1: no child
        if ( root->left == nullptr && root->right == nullptr )
        {
            delete root;
            root = nullptr;
        }
        //case 2: 1 child
        else if ( root->left == nullptr )
        {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if ( root->right == nullptr )
        {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: 2 children
        else
        {
            //find the minimum node of the root's right subtree to replace it
            BstNode* temp = FindMin( root->right );
            root->data = temp->data;
            Delete ( root->right, temp->data );
        }
        return;
    }
}
int main()
{
    BstTree* tree = new BstTree();
    tree->Insert( tree->root, 6 );
    tree->Insert( tree->root, 8 );
    tree->Insert( tree->root, 15 );
    tree->Insert( tree->root, 9 );
    tree->Insert( tree->root, 7 );
    tree->Insert( tree->root, 10 );
    tree->Insert( tree->root, 20 );
    tree->Insert( tree->root, 18 );
    tree->Insert( tree->root, 17 );
    tree->Insert( tree->root, 19 );
    tree->Insert( tree->root, 22 );
    int n;
    tree->Traverse( tree->root );
    cout << "Enter a number to search: ";
    cin >> n;
    if ( tree->Search(tree->root, n) ) cout << "Found!\n";
    else cout << "Not found!\n";
    cout << "Enter a number to delete from node: ";
    cin >> n;
    tree->Delete( tree->root, n );
    tree->Traverse( tree->root );
    delete tree;
}
