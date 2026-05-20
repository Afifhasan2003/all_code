#include <bits/stdc++.h>
using namespace std;

const int M = 3; // m-way tree

struct Node
{
    vector<int> keys;
    vector<Node *> child;

    int keyCount;
    bool leaf;

    Node(bool isLeaf)
    {
        leaf = isLeaf;
        keyCount = 0;

        keys.assign(M - 1, 0);
        child.assign(M, NULL);
    }
};


// display tree
void display(Node *root, int level = 0)
{
    if (root == NULL)
        return;

    cout << "Level " << level << " : ";

    for (int i = 0; i < root->keyCount; i++)
    {
        cout << root->keys[i] << " ";
    }

    cout << endl;

    // Only traverse children if not a leaf node
    if (!root->leaf)
    {
        for (int i = 0; i <= root->keyCount; i++)
        {
            display(root->child[i], level + 1);
        }
    }
}


// insert key in leaf node
void insert(Node *root, int value)
{
    if (root->leaf)
    {
        if (root->keyCount >= M - 1)
        {
            cout << "Node Full! Can't insert " << value << endl;
            return;
        }

        int i = root->keyCount - 1;

        while (i >= 0 && root->keys[i] > value)
        {
            root->keys[i + 1] = root->keys[i];
            i--;
        }

        root->keys[i + 1] = value;
        root->keyCount++;
    }
    else
    {
        int i = 0;

        while (i < root->keyCount && value > root->keys[i])
        {
            i++;
        }

        insert(root->child[i], value);
    }
}


Node *createTree()
{
    /*
                    [50]
              /        |        \
          [20]      [70 80]     [100]
         /   \       /   |   \     /   \
      [5 10] [30] [60] [75] [90] [110] [120]
    */

    Node *root = new Node(false);

    root->keys[0] = 50;
    root->keyCount = 1;

    // level 1 - internal nodes
    root->child[0] = new Node(false);
    root->child[1] = new Node(false);
    root->child[2] = new Node(false);

    root->child[0]->keys[0] = 20;
    root->child[0]->keyCount = 1;

    root->child[1]->keys[0] = 70;
    root->child[1]->keys[1] = 80;
    root->child[1]->keyCount = 2;

    root->child[2]->keys[0] = 100;
    root->child[2]->keyCount = 1;

    // level 2 - leaf nodes under child[0]
    root->child[0]->child[0] = new Node(true);
    root->child[0]->child[1] = new Node(true);

    root->child[0]->child[0]->keys[0] = 5;
    root->child[0]->child[0]->keys[1] = 10;
    root->child[0]->child[0]->keyCount = 2;

    root->child[0]->child[1]->keys[0] = 30;
    root->child[0]->child[1]->keyCount = 1;

    // level 2 - leaf nodes under child[1]
    root->child[1]->child[0] = new Node(true);
    root->child[1]->child[1] = new Node(true);
    root->child[1]->child[2] = new Node(true);

    root->child[1]->child[0]->keys[0] = 60;
    root->child[1]->child[0]->keyCount = 1;

    root->child[1]->child[1]->keys[0] = 75;
    root->child[1]->child[1]->keyCount = 1;

    root->child[1]->child[2]->keys[0] = 90;
    root->child[1]->child[2]->keyCount = 1;

    // level 2 - leaf nodes under child[2]
    root->child[2]->child[0] = new Node(true);
    root->child[2]->child[1] = new Node(true);

    root->child[2]->child[0]->keys[0] = 110;
    root->child[2]->child[0]->keyCount = 1;

    root->child[2]->child[1]->keys[0] = 120;
    root->child[2]->child[1]->keyCount = 1;

    return root;
}


bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    int i = 0;

    while (i < root->keyCount && key > root->keys[i])
        i++;

    if (i < root->keyCount && key == root->keys[i])
    {
        cout << "Key found" << endl;
        return true;
    }

    if (root->leaf)
        return false;

    return search(root->child[i], key);
}


int main()
{
    Node *root = createTree();

    cout << "Tree structure:" << endl;
    display(root);

    cout << "\nSearching for 75: ";
    search(root, 75);

    cout << "Searching for 25: ";
    search(root, 25);

    cout << "\nInserting 15 into leaf [5 10]:" << endl;
    insert(root->child[0]->child[0], 15);

    cout << "\nAttempting to insert 35 into full leaf [30]:" << endl;
    insert(root->child[0]->child[1], 35);

    cout << "\nTree after insertions:" << endl;
    display(root);

    return 0;
}