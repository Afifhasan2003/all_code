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




Node* createTreeFromVector(vector<int>& vec, int index = 0) {  //if index is not provided, it defaults to 0
    if (index >= vec.size()) return nullptr;
    
    Node* root = new Node(vec[index]);
    root->left = createTreeFromVector(vec, 2 * index + 1);
    root->right = createTreeFromVector(vec, 2 * index + 2);
    
    return root;
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

void inorder(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
}

//this algorithm works similar to the inorder traversal above, not like the algo of the pdf
void preorder(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            cout << curr->data << " ";
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        curr = curr->right;
    }
}

//this follows the alogorithm of the pdf 5.1 (sumon sir)
//https://www.youtube.com/watch?v=Bfqd8BsPVuw  watch this video if didnt understand
void preorder2(Node* root) {
    Node* stack[100];
    int top = 1;
    stack[0] = NULL;
    Node* Ptr = root;

    while (Ptr != NULL) {
        cout << Ptr->data << " ";

        if (Ptr->right != NULL) {
            stack[top++] = Ptr->right;
        }

        if (Ptr->left != NULL) {
            Ptr = Ptr->left;
        } else {
            Ptr = stack[--top];
        }
    }
}








//https://www.youtube.com/watch?v=2YBhNLodD8Q  
void postorder_twoStack(Node* root) {
    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    Node* curr = root;

    if (curr == NULL) return;

    stack1[++top1] = curr;

    while (top1 != -1) {
        curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left != NULL) {
            stack1[++top1] = curr->left;
        }
        if (curr->right != NULL) {
            stack1[++top1] = curr->right;
        }
    }

    while (top2 != -1) {
        cout << stack2[top2--]->data << " ";
    }
}

//https://www.youtube.com/watch?v=NzIGLLwZBS8
// not totally clear about this one yet
void postorder_oneStack(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* curr = root;
    Node* lastVisited = NULL;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top];
        if (curr->right == NULL || curr->right == lastVisited) {
            cout << curr->data << " ";
            stack[top--] = NULL;  // Remove from stack
            lastVisited = curr;
            curr = NULL;
        } else {
            curr = curr->right;
        }
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
    
    cout << "Inorder Traversal: ";
    inorderUsingStack(root);            //4 2 5 1 6 3 7
    cout << "\nPreorder Traversal: ";
    preorderUsingStack(root);           //1 2 4 5 3 6 7
    cout << "\nPostorder Traversal: ";
    postorderUsingStack(root);          //4 5 2 6 7 3 1
    cout << endl;

    cout << "Inorder Traversal (using loop): ";
    inorder(root);                      //4 2 5 1 6 3 7
    cout << "\nPreorder Traversal (using loop): ";
    preorder(root);                     //1 2 4 5 3 6 7 
    cout << "\nPostorder Traversal (using loop): ";
    postorder_twoStack(root);           //4 5 2 6 7 3 1
    cout << "\nPostorder Traversal (using one stack): ";
    postorder_oneStack(root);           //4 5 2 6 7 3 1
    cout << endl;

    return 0;
}