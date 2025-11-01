#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

// Function to create a new node
TreeNode* createNode(int val, TreeNode* parent = nullptr) {
    TreeNode* newNode = new TreeNode();
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = parent;
    return newNode;
}

// Function to insert a node in BST using recursion
TreeNode* insert(TreeNode* root, int val, TreeNode* parent = nullptr) {
    if (root == nullptr) {
        return createNode(val, parent);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val, root);
    } else if (val > root->data) {
        root->right = insert(root->right, val, root);
    }
    
    return root;
}

// Function to insert a node in BST using iteration
TreeNode* insertIterative(TreeNode* root, int val) {    
    if (root == nullptr) {
        return createNode(val);
    }
    
    TreeNode* current = root;
    TreeNode* parent = nullptr;
    
    while (current != nullptr) {
        parent = current;
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            return root; // Value already exists
        }
    }
    
    TreeNode* newNode = createNode(val, parent);
    
    if (val < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    
    return root;
}

// Function to create BST from array
TreeNode* createFromArray(int arr[], int size) {
    TreeNode* root = nullptr;
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Function to search for a value in BST using recursion
bool search(TreeNode* root, int val) {
    if (root == nullptr) return false;
    if (val == root->data) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}
//return pointer of the node
TreeNode* searchPos(TreeNode* root, int val) {
    if (root == nullptr || root->data == val) return root;
    if (val < root->data) return searchPos(root->left, val);
    return searchPos(root->right, val);
}

// Function to search for a value in BST using iteration
bool searchIterative(TreeNode* root, int val) {
    while (root != nullptr) {
        if (val == root->data) return true;
        if (val < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// Function to find ceiling 
int findCeiling(TreeNode* root, int val) {
    int ceiling = -1;
    while (root != nullptr) {
        if (root->data < val) {
            root = root->right;
        } else  {
            ceiling = root->data;
            root = root->left;
        }
    }
    return ceiling;
}
// Function to find ceiling using parent pointer

int findFloor(TreeNode* root, int val) {
    int floor = -1;
    while (root != nullptr) {
        if (root->data > val) {
            root = root->left;
        } else {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

TreeNode* findSuccessor(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;

    TreeNode* pos = searchPos(root, val);
    if (pos == nullptr) return nullptr; // Value not found 

    // Case 1: Node has right subtree
    if (pos->right != nullptr) {
        TreeNode* temp = pos->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }
    
    // Case 2: No right subtree, find ancestor
    TreeNode* current = pos;
    TreeNode* ancestor = current->parent;
    
    // Go up until we find an ancestor where current node is in left subtree
    while (ancestor != nullptr && current == ancestor->right) {
        current = ancestor;
        ancestor = ancestor->parent;
    }
    
    return ancestor; // This will be nullptr if no successor exists
}

void deleteNode1(TreeNode* &root, int val){
    if(root == nullptr) return;
    
    if(val < root->data){
        deleteNode1(root->left, val);
    }
    else if(val > root->data){
        deleteNode1(root->right, val);
    }
    else{
        // Found the node to delete
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr){
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            // Two children: find inorder successor
            TreeNode* succ = root->right;
            while(succ->left != nullptr){
                succ = succ->left;
            }
            root->data = succ->data;
            deleteNode1(root->right, succ->data);
        }
    }
}

// Function to find minimum element
int findMin(TreeNode* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr) root = root->left;
    return root->data;
}

// Function to find maximum element
int findMax(TreeNode* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr) root = root->right;
    return root->data;
}

// Inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Display tree (inorder)
void display(TreeNode* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    cout << "Tree elements (inorder): ";
    inorderTraversal(root);
    cout << endl;
}

// Check if tree is empty
bool isEmpty(TreeNode* root) {
    return root == nullptr;
}

// Get height of tree
//https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=14
int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = nullptr;
    
    int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Creating BST from array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    root = createFromArray(arr, size);
    
    display(root);
    
    cout << "Minimum element: " << findMin(root) << endl;
    cout << "Maximum element: " << findMax(root) << endl;
    
    int searchVal = 40;
    cout << "Searching for " << searchVal << ": " << (search(root, searchVal) ? "Found" : "Not Found") << endl;
    
    searchVal = 100;
    cout << "Searching for " << searchVal << ": " << (searchIterative(root, searchVal) ? "Found" : "Not Found") << endl;
    
    cout << "Inserting 55..." << endl;
    root = insert(root, 55);
    display(root);

    cout << "Inserting 45 Using Recursive Method..." << endl;
    root = insert(root, 45);
    display(root);

    cout << "Inserting 68 using iterative method..." << endl;
    root = insertIterative(root, 68);
    display(root);

    cout<< "ceiling of 42: " << findCeiling(root, 42) << endl;

    cout<< "Floor of 42: " << findFloor(root, 42) << endl; 

    cout << "Successor of 70: " << findSuccessor(root, 70)->data << endl;

    deleteNode1(root,30);
    cout<< "Deleted 30: "; display(root);


    cout << "Tree height: " << getHeight(root) << endl;
    cout << "Total nodes: " << countNodes(root) << endl;
    
    return 0;
}
