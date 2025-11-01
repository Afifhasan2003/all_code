#include <iostream>
#include <vector>
using namespace std;

// Tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create tree from vector (using recursion)
Node* createTreeFromVector(vector<int>& vec, int index = 0) {  //if index is not provided, it defaults to 0
    if (index >= vec.size()) return nullptr;
    
    Node* root = new Node(vec[index]);
    root->left = createTreeFromVector(vec, 2 * index + 1);
    root->right = createTreeFromVector(vec, 2 * index + 2);
    
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}




void inorderUsingStack(Node* root) {
    vector<Node*> stack;
    Node* current = root;
    
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push_back(current);
            current = current->left;
        }
        current = stack.back();
        stack.pop_back();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorderUsingStack(Node* root) {
    if (root == nullptr) return;

    vector<Node*> stack;
    stack.push_back(root);

    while (!stack.empty()) {
        Node* current = stack.back();
        stack.pop_back();
        cout << current->data << " ";

        // Push right child first so that left child is processed first
        if (current->right != nullptr) {
            stack.push_back(current->right);
        }
        if (current->left != nullptr) {
            stack.push_back(current->left);
        }
    }
}

void postorderUsingStack(Node* root) {
    if (root == nullptr) return;

    vector<Node*> stack1, stack2;
    stack1.push_back(root);

    while (!stack1.empty()) {
        Node* current = stack1.back();
        stack1.pop_back();
        stack2.push_back(current);

        if (current->left != nullptr) {
            stack1.push_back(current->left);
        }
        if (current->right != nullptr) {
            stack1.push_back(current->right);
        }
    }

    // Print the nodes in reverse order
    while (!stack2.empty()) {
        cout << stack2.back()->data << " ";
        stack2.pop_back();
    }
}







// BFS traversal (Level Order) using recursion
void printLevel(Node* root, int level) {
    if (root == nullptr) return;
    if (level == 1) {
        cout << root->data << " ";
        return;
    }
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}


int getHeight(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void bfs(Node* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
    }
}

int main() {
    // Initialize vector with tree values (level order)
    vector<int> treeValues = {1, 2, 3, 4, 5, 6, 7};
    
    // Create tree from vector
    Node* root = createTreeFromVector(treeValues);
    
    // Tree structure:
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6  7
    
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nBFS: ";
    bfs(root);
    cout << endl;

    return 0;
}