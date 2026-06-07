#include <bits/stdc++.h>
using namespace std;

const int ORDER = 3; // order = max children per internal node, or max keys per leaf node

//internal nodes will have min ceil(ORDER/2) children and max ORDER children 

struct Node
{
    vector<int> keys; // keys storage
    vector<Node *> child; // child pointers (only for internal nodes)
    Node *next; // link to next leaf horizontally (only for leaf nodes ig)
    int keyCount;
    bool isLeaf;
    int maxKeys;

    Node(bool leaf)
    {
        isLeaf = leaf;
        keyCount = 0;
        next = NULL;

        if (isLeaf)
        {
            maxKeys = ORDER;
            keys.assign(ORDER + 1, 0);
        }
        else
        {
            maxKeys = ORDER - 1;
            keys.assign(ORDER, 0);
            child.assign(ORDER + 2, NULL);      //2 extra for temporary storage during splits (one extra key and one extra child pointer)
        }
    }
};

// ========== DISPLAY FUNCTIONS ==========

void displayTree(Node *root, int level = 0)
{
    if (root == NULL)
        return;

    cout << "Level " << level << " [" << (root->isLeaf ? "LEAF" : "INTERNAL") << "] : ";

    for (int i = 0; i < root->keyCount; i++)
    {
        cout << root->keys[i] << " ";
    }
    cout << endl;

    if (!root->isLeaf)
    {
        for (int i = 0; i <= root->keyCount; i++)
        {
            displayTree(root->child[i], level + 1);
        }
    }
}

//printing all the leaf nodes in a chain using next pointer (left to right)
void displayLeafChain(Node *root)
{
    if (root == NULL)
        return;

    // find leftmost leaf
    Node *current = root;
    while (!current->isLeaf)
    {
        current = current->child[0];    //child[0] is the leftmost child of every node
    }

    cout << "Leaf chain: ";
    while (current != NULL)
    {
        cout << "[ ";
        for (int i = 0; i < current->keyCount; i++)
        {
            cout << current->keys[i] << " ";
        }
        cout << "] ";
        if (current->next != NULL)
            cout << "-> ";
        current = current->next;
    }
    cout << endl;
}

// return pointer to leaf node where key should be (or is) located, returns NULL if tree is empty
Node *findLeaf(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    Node *current = root;

    while (!current->isLeaf)
    {
        int i = 0;
        while (i < current->keyCount && key >= current->keys[i])
        {
            i++;
        }
        current = current->child[i];
    }

    return current; //if not found returns leaf where it should be, if found also returns the same leaf
}

bool search(Node *root, int key)    //return true if key is found, false otherwise
{
    Node *leaf = findLeaf(root, key);

    if (leaf == NULL)
        return false;

    for (int i = 0; i < leaf->keyCount; i++)
    {
        if (leaf->keys[i] == key)
            return true;
    }

    return false;
}

// target leaf is given, 
void insertInLeaf(Node *leaf, int key)      //inserts key into leaf node in sorted order (assumes leaf has space)
{                                           
    int i = leaf->keyCount - 1;

    while (i >= 0 && leaf->keys[i] > key)
    {
        leaf->keys[i + 1] = leaf->keys[i];  //push bigger keys to right
        i--;
    }

    leaf->keys[i + 1] = key;
    leaf->keyCount++;
}

// target node is given, insert key and right child in sorted order (assumes internal node has space)
void insertInInternal(Node *node, int key, Node *rightChild)    
{
    int i = node->keyCount - 1;

    while (i >= 0 && node->keys[i] > key)   //key should go left
    {
        node->keys[i + 1] = node->keys[i];
        node->child[i + 2] = node->child[i + 1];
        i--;
    }

    node->keys[i + 1] = key;
    node->child[i + 2] = rightChild;
    node->keyCount++;
}


// splits a leaf when full and new key needs to be inserted, returns new leaf node created after split
Node *splitLeaf(Node *leaf, int key)
{
    // create temp array with all keys including new key
    vector<int> temp(ORDER + 1, 0);
    int i = 0, j = 0;

    while (i < leaf->keyCount && leaf->keys[i] < key)   //helps cut the array in perfect halves when we insert the new key in sorted order
    {
        temp[j++] = leaf->keys[i++];
    }
    temp[j++] = key;
    while (i < leaf->keyCount)
    {
        temp[j++] = leaf->keys[i++];
    }

    // create new leaf
    Node *newLeaf = new Node(true);

    // split point
    int split = (ORDER + 1) / 2;

    // left leaf gets first 'split' keys, from here we will know how many keys are in the node, even if there are more keys in leaf->keys
    leaf->keyCount = split;
    for (int i = 0; i < split; i++)
    {
        leaf->keys[i] = temp[i];
    }
        //rest of the keys of leaf should be cleared (not necessary but cleaner),we are not doing it anyway

    // right leaf gets remaining keys
    newLeaf->keyCount = (ORDER + 1) - split;
    for (int i = 0; i < newLeaf->keyCount; i++)
    {
        newLeaf->keys[i] = temp[split + i];
    }

    // link leaves  
    newLeaf->next = leaf->next;
    leaf->next = newLeaf;   //seq is leaf -> newLeaf -> old next leaf (if any)

    return newLeaf;      // first key of new leaf will be pushed up to parent as separator key
}

// splits an internal node when full and new key+child needs to be inserted, returns new internal node created after split
Node *splitInternal(Node *node, int key, Node *rightChild)
{
    // create temp arrays
    vector<int> tempKeys(ORDER, 0);
    vector<Node *> tempChild(ORDER + 1, NULL);

    int i = 0, j = 0;

    // copy existing keys and children to temp, inserting new key
    while (i < node->keyCount && node->keys[i] < key)
    {
        tempKeys[j] = node->keys[i];
        tempChild[j] = node->child[i];
        i++;
        j++;
    }

    tempKeys[j] = key;
    tempChild[j] = node->child[i];
    tempChild[j + 1] = rightChild;
    j++;

    while (i < node->keyCount)
    {
        tempKeys[j] = node->keys[i];
        tempChild[j + 1] = node->child[i + 1];
        i++;
        j++;
    }

    // split point
    int split = ORDER / 2;  //any intermediate key can have minimam of ceil(ORDER/2) children

    // left node gets first 'split' keys
    node->keyCount = split;
    for (int i = 0; i < split; i++)
    {
        node->keys[i] = tempKeys[i];
        node->child[i] = tempChild[i];
    }
    node->child[split] = tempChild[split]; // one extra for ceiling

    // create new internal node for right side
    Node *newInternal = new Node(false);

    // right node gets keys after split+1
    newInternal->keyCount = (ORDER - 1) - split;
    for (int i = 0; i < newInternal->keyCount; i++)
    {
        newInternal->keys[i] = tempKeys[split + 1 + i];
        newInternal->child[i] = tempChild[split + 1 + i];
    }
    newInternal->child[newInternal->keyCount] = tempChild[ORDER];

    
    return newInternal;
}

// recursively inserts key into subtree rooted at node, sets childToInsert and keyToInsert if a split occurs at this level
Node *insertInternal(Node *node, int key, Node **childToInsert, int *keyToInsert)
{

    //first thing to do is find the correct leaf to insert the key, then we will check if the leaf is full or not
    if (node->isLeaf)
    {
        if (node->keyCount < node->maxKeys)
        {
            // leaf not full
            insertInLeaf(node, key);
            *childToInsert = NULL;
            return node;    //return leaf node where key was inserted
        }
        else
        {
            // leaf full, need to split
            Node *newLeaf = splitLeaf(node, key);
            *keyToInsert = newLeaf->keys[0]; // pointer to first key of new leaf which will be pushed up to parent as separator key
            *childToInsert = newLeaf;       // pointer to new leaf created after split, will be inserted as child in parent
                                            // childToInsert was accepted as pointer, so dont have to return it, just set it and it will be available to caller, 
            return node;
        }
    }
    else
    {
        //  node is not lead, find child to go to
        int i = 0;
        while (i < node->keyCount && key >= node->keys[i])
        {
            i++;
        }

        Node *splitChild = NULL;
        int splitKey = 0;   //this is the key of smallest key in the subtree of splitChild, which will be pushed up to this internal node if split occurs in child

        insertInternal(node->child[i], key, &splitChild, &splitKey);

        if (splitChild == NULL)
        {
            // no split occurred in the direct child, so nothing to insert in this node
            *childToInsert = NULL;
            return node;
        }

        // split occurred, need to insert 

        if (node->keyCount < node->maxKeys) // this node is not full, can insert splitKey and splitChild here
        {
            // internal node not full
            insertInInternal(node, splitKey, splitChild);       //splitKey is not position of split, it is the first key of the new child created after split,             *childToInsert = NULL;
            return node;
        }
        else
        {
            // internal node full, need to split
            Node *newInternal = splitInternal(node, splitKey, splitChild);  // accepted new right child and key to insert

            
            vector<int> tempKeys(ORDER, 0);
            vector<Node *> tempChild(ORDER + 1, NULL);

            int idx = 0, j = 0;
            while (idx < node->keyCount && node->keys[idx] < splitKey)
            {
                tempKeys[j] = node->keys[idx];
                tempChild[j] = node->child[idx];
                idx++;
                j++;
            }
            tempKeys[j] = splitKey;
            tempChild[j] = node->child[idx];
            tempChild[j + 1] = splitChild;
            j++;

            while (idx < node->keyCount)
            {
                tempKeys[j] = node->keys[idx];
                tempChild[j + 1] = node->child[idx + 1];
                idx++;
                j++;
            }

            int split = ORDER / 2;
            *keyToInsert = tempKeys[split]; // push up middle key
            *childToInsert = newInternal;

            return node;
        }
    }
}

// this is the main insertion function called by user
// inserts new key into the B+ tree, handles root creation and root split, returns (possibly new) root
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        root = new Node(true);
        root->keys[0] = key;
        root->keyCount = 1;
        return root;
    }

    Node *splitChild = NULL;    // if root splits, this will point to new node created after split
    int splitKey = 0;

    insertInternal(root, key, &splitChild, &splitKey);

    if (splitChild != NULL)
    {
        // root split, create new root
        Node *newRoot = new Node(false);
        newRoot->keys[0] = splitKey;
        newRoot->child[0] = root;
        newRoot->child[1] = splitChild;
        newRoot->keyCount = 1;
        return newRoot;
    }

    return root;
}



// ========== DELETION HELPER FUNCTIONS ==========

// returns index of first key in node >= given key (position where key would be inserted or is located)
int findKeyIndexInNode(Node *node, int key)
{
    int i = 0;
    while (i < node->keyCount && node->keys[i] < key)
        i++;
    return i;
}

// removes key from leaf node by shifting remaining keys left, does nothing if key not found
void removeFromLeaf(Node *leaf, int key)
{
    int i = 0;
    while (i < leaf->keyCount && leaf->keys[i] != key)
        i++;

    if (i == leaf->keyCount)
        return; // key not found

    // shift keys left
    for (int j = i; j < leaf->keyCount - 1; j++)
    {
        leaf->keys[j] = leaf->keys[j + 1];
    }
    leaf->keyCount--;
}

// removes key at given index from internal node and shifts remaining keys and child pointers left
void removeFromInternal(Node *node, int index)
{
    for (int i = index; i < node->keyCount - 1; i++)
    {
        node->keys[i] = node->keys[i + 1];
        node->child[i + 1] = node->child[i + 2];
    }
    node->keyCount--;
}

// borrows a key from left sibling to fix underflow in child at index, updates parent separator key accordingly
void borrowFromLeft(Node *node, int index, Node *parent)    //index is the index of child (at parent node )which is underflowed, so left sibling is at index-1
{
    Node *child = parent->child[index];
    Node *leftSibling = parent->child[index - 1];

    if (child->isLeaf)
    {
        // shift all keys in child to right one position
        for (int i = child->keyCount; i > 0; i--)
        {
            child->keys[i] = child->keys[i - 1];
        }

        // borrow from left sibling
        child->keys[0] = leftSibling->keys[leftSibling->keyCount - 1];
        child->keyCount++;
        leftSibling->keyCount--;

        // update parent key (parent key is always the first key of right child)
        parent->keys[index - 1] = child->keys[0];
    }
    else
    {
        // shift all keys and children in child to right
        for (int i = child->keyCount; i > 0; i--)
        {
            child->keys[i] = child->keys[i - 1];
        }
        for (int i = child->keyCount + 1; i > 0; i--)
        {
            child->child[i] = child->child[i - 1];
        }

        // move parent key down (cannot direct bring siblings's last, because sibling's last > zparents last )
        child->keys[0] = parent->keys[index - 1];

        // move sibling's last child
        child->child[0] = leftSibling->child[leftSibling->keyCount];

        // move sibling's last key to parent
        parent->keys[index - 1] = leftSibling->keys[leftSibling->keyCount - 1];

        child->keyCount++;
        leftSibling->keyCount--;
    }
}

// borrows a key from right sibling to fix underflow in child at index, updates parent separator key accordingly
void borrowFromRight(Node *node, int index, Node *parent)
{
    Node *child = parent->child[index];
    Node *rightSibling = parent->child[index + 1];

    if (child->isLeaf)
    {
        // borrow from right sibling
        child->keys[child->keyCount] = rightSibling->keys[0];
        child->keyCount++;

        // shift right sibling keys left
        for (int i = 0; i < rightSibling->keyCount - 1; i++)
        {
            rightSibling->keys[i] = rightSibling->keys[i + 1];
        }
        rightSibling->keyCount--;

        // update parent key
        parent->keys[index] = rightSibling->keys[0];
    }
    else
    {
        // move parent key down
        child->keys[child->keyCount] = parent->keys[index];

        // move sibling's first child
        child->child[child->keyCount + 1] = rightSibling->child[0];

        // move sibling's first key to parent
        parent->keys[index] = rightSibling->keys[0];

        // shift right sibling keys and children left
        for (int i = 0; i < rightSibling->keyCount - 1; i++)
        {
            rightSibling->keys[i] = rightSibling->keys[i + 1];
        }
        for (int i = 0; i < rightSibling->keyCount; i++)
        {
            rightSibling->child[i] = rightSibling->child[i + 1];
        }

        child->keyCount++;
        rightSibling->keyCount--;
    }
}

// merges child at index into its left sibling, pulls down parent separator key (internal only), updates leaf chain (leaf only)
void mergeWithLeft(Node *node, int index, Node *parent)
{
    Node *child = parent->child[index];
    Node *leftSibling = parent->child[index - 1];

    if (child->isLeaf)
    {
        // merge child into left sibling
        for (int i = 0; i < child->keyCount; i++)
        {
            leftSibling->keys[leftSibling->keyCount + i] = child->keys[i];
        }
        leftSibling->keyCount += child->keyCount;

        // update leaf chain
        leftSibling->next = child->next;

        // remove key from parent
        removeFromInternal(parent, index - 1);

        delete child;
    }
    else
    {
        // pull down parent key
        leftSibling->keys[leftSibling->keyCount] = parent->keys[index - 1];
        leftSibling->keyCount++;

        // merge child into left sibling
        for (int i = 0; i < child->keyCount; i++)
        {
            leftSibling->keys[leftSibling->keyCount + i] = child->keys[i];
            leftSibling->child[leftSibling->keyCount + i] = child->child[i];
        }
        leftSibling->child[leftSibling->keyCount + child->keyCount] = child->child[child->keyCount];
        leftSibling->keyCount += child->keyCount;

        // remove key from parent
        removeFromInternal(parent, index - 1);

        delete child;
    }
}

// merges right sibling into child at index, pulls down parent separator key (internal only), updates leaf chain (leaf only)
void mergeWithRight(Node *node, int index, Node *parent)
{
    Node *child = parent->child[index];
    Node *rightSibling = parent->child[index + 1];

    if (child->isLeaf)
    {
        // merge right sibling into child
        for (int i = 0; i < rightSibling->keyCount; i++)
        {
            child->keys[child->keyCount + i] = rightSibling->keys[i];
        }
        child->keyCount += rightSibling->keyCount;

        // update leaf chain
        child->next = rightSibling->next;

        // remove key from parent
        removeFromInternal(parent, index);

        delete rightSibling;
    }
    else
    {
        // pull down parent key
        child->keys[child->keyCount] = parent->keys[index];
        child->keyCount++;

        // merge right sibling into child
        for (int i = 0; i < rightSibling->keyCount; i++)
        {
            child->keys[child->keyCount + i] = rightSibling->keys[i];
            child->child[child->keyCount + i] = rightSibling->child[i];
        }
        child->child[child->keyCount + rightSibling->keyCount] = rightSibling->child[rightSibling->keyCount];
        child->keyCount += rightSibling->keyCount;

        // remove key from parent
        removeFromInternal(parent, index);

        delete rightSibling;
    }
}

// ========== DELETION MAIN FUNCTION ==========

// recursively deletes key from subtree rooted at node, fixes underflow by borrowing or merging as needed
void deleteInternal(Node *node, int key, Node *parent, int indexInParent)
{
    if (node->isLeaf)
    {
        removeFromLeaf(node, key);

        int minKeys = (ORDER + 1) / 2 - 1; // min keys for leaf after deletion

        if (node->keyCount >= minKeys || parent == NULL)
        {
            // no underflow or node is root, nothing to fix
            return;
        }

        // underflow - try to borrow or merge
        Node *leftSibling = (indexInParent > 0) ? parent->child[indexInParent - 1] : NULL;
        Node *rightSibling = (indexInParent < parent->keyCount) ? parent->child[indexInParent + 1] : NULL;

        // try borrow from left
        if (leftSibling && leftSibling->keyCount > minKeys)
        {
            borrowFromLeft(node, indexInParent, parent);
        }
        // try borrow from right
        else if (rightSibling && rightSibling->keyCount > minKeys)
        {
            borrowFromRight(node, indexInParent, parent);
        }
        // merge with left
        else if (leftSibling)
        {
            mergeWithLeft(node, indexInParent, parent);
        }
        // merge with right
        else if (rightSibling)
        {
            mergeWithRight(node, indexInParent, parent);
        }
    }
    // node is internal
    else
    {
        // internal node
        int i = 0;
        while (i < node->keyCount && key >= node->keys[i])
        i++;

        deleteInternal(node->child[i], key, node, i);   //recursive call to delete key from subtree, passing current node as parent and index of child in parent

        // check for underflow in internal node
        int minKeys = ORDER / 2 - 1; // min keys for internal node

        if (node->keyCount >= minKeys || parent == NULL)
        {
            // no underflow or node is root, nothing to fix
            return;
        }

        // underflow - try to borrow or merge
        Node *leftSibling = (indexInParent > 0) ? parent->child[indexInParent - 1] : NULL;
        Node *rightSibling = (indexInParent < parent->keyCount) ? parent->child[indexInParent + 1] : NULL;

        if (leftSibling && leftSibling->keyCount > minKeys)
        {
            borrowFromLeft(node, indexInParent, parent);
        }
        else if (rightSibling && rightSibling->keyCount > minKeys)
        {
            borrowFromRight(node, indexInParent, parent);
        }
        else if (leftSibling)
        {
            mergeWithLeft(node, indexInParent, parent);
        }
        else if (rightSibling)
        {
            mergeWithRight(node, indexInParent, parent);
        }
    }
}

// deletes key from the B+ tree, shrinks tree height if root becomes empty, returns (possibly new) root
Node *deleteKey(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    deleteInternal(root, key, NULL, 0);

    // if root became empty, make its only child the new root
    if (root->keyCount == 0 && !root->isLeaf)
    {
        Node *newRoot = root->child[0];
        delete root;
        return newRoot;
    }

    return root;
}

// ========== UTILITY FUNCTIONS ==========

// prints all keys in [start, end] by finding the start leaf and traversing the leaf chain rightward
void rangeQuery(Node *root, int start, int end)
{
    Node *leaf = findLeaf(root, start);

    if (leaf == NULL)
    {
        cout << "Range query: No results" << endl;
        return;
    }

    cout << "Range query [" << start << ", " << end << "]: ";

    bool found = false;
    while (leaf != NULL)
    {
        for (int i = 0; i < leaf->keyCount; i++)
        {
            if (leaf->keys[i] >= start && leaf->keys[i] <= end)
            {
                cout << leaf->keys[i] << " ";
                found = true;
            }
            if (leaf->keys[i] > end)
            {
                cout << endl;
                return;
            }
        }
        leaf = leaf->next;
    }

    if (!found)
        cout << "No results";
    cout << endl;
}

// recursively frees all nodes in the tree using post-order traversal
void destroyTree(Node *root)
{
    if (root == NULL)
        return;

    if (!root->isLeaf)
    {
        for (int i = 0; i <= root->keyCount; i++)
        {
            destroyTree(root->child[i]);
        }
    }

    delete root;
}

// ========== MAIN ==========

int main()
{
    Node *root = NULL;

    cout << "=== B+ Tree (Order " << ORDER << ") ===" << endl
         << endl;

    // Insertions
    cout << "Inserting: 5, 15, 25, 35, 45, 55, 40, 30, 20" << endl;
    vector<int> insertKeys = {5, 15, 25, 35, 45, 55, 40, 30, 20};
    for (int key : insertKeys)
    {
        root = insert(root, key);
    }

    cout << "\nTree structure:" << endl;
    displayTree(root);

    cout << "\n";
    displayLeafChain(root);

    // Search
    cout << "\n=== Search ===" << endl;
    vector<int> searchKeys = {25, 100};
    for (int key : searchKeys)
    {
        cout << "Search " << key << ": " << (search(root, key) ? "FOUND" : "NOT FOUND") << endl;
    }

    // Range query
    cout << "\n=== Range Query ===" << endl;
    rangeQuery(root, 20, 40);

    // Deletions
    cout << "\n=== Deletions ===" << endl;
    vector<int> deleteKeys = {25, 40, 5};
    for (int key : deleteKeys)
    {
        cout << "\nDeleting " << key << endl;
        root = deleteKey(root, key);
        displayTree(root);
        displayLeafChain(root);
    }

    // Cleanup
    destroyTree(root);

    return 0;
}