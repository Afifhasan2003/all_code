#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    
    /*Node(char c, int f) {
         ch = c;
         freq = f;
         left = nullptr;
         right = nullptr;
     } */
    // Alternative constructor using initializer list

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

};

// Comparator for priority queue (min heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // min heap based on frequency
    }
};//a struct can have member functions

// Step 1: Read paragraph from file
string readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return "";
    }

    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    cout << "File read successfully!" << endl;
    return content;
}

// Step 2: Count frequency of each character
map<char, int> countFrequency(const string& text) {
    map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    cout << "\nCharacter Frequencies:" << endl;
    for (auto& p : freq) {
        cout << "  '" << p.first << "' -> " << p.second << endl;
    }

    return freq;
}

// Step 3: Build Huffman Tree using priority queue
Node* buildHuffmanTree(map<char, int>& freq) {

    //top: least frequent node
    priority_queue<Node*, vector<Node*>, Compare> pq;   //priority_queue<Type, Container, Comparator> this is the general syntax for pq
                                                        //here we explicitly specify the container as vector and comparator as Compare struct
                                                        //we can prioritize based on any function we want



    // Insert all characters into priority queue
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));       // node takes char and its freq
    }

    // Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create parent node with combined frequency
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nHuffman Tree built successfully!" << endl;
    return pq.top();  // Root of the tree
}

// Step 4: Generate Huffman codes by traversing the tree
void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (!root) return;

    // Leaf node contains a character
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Step 5: Encode the text using Huffman codes
string encodeText(const string& text, map<char, string>& huffmanCodes) {
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCodes[ch];
    }

    cout << "\nText encoded successfully!" << endl;
    return encoded;
}

// Step 6: Write encoded text to output file
void writeToFile(const string& filename, const string& encodedText, map<char, string>& huffmanCodes) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return;
    }

    // Write Huffman codes (for decoding later)
    file << "===== HUFFMAN CODES =====" << endl;
    for (auto& p : huffmanCodes) 
        file << "'" << p.first << "' -> " << p.second << endl;
    
    file << endl;

    // Write encoded binary string
    file << "===== ENCODED TEXT =====" << endl;
    file << encodedText << endl;

    file.close();
    cout << "Encoded text written to " << filename << " successfully!" << endl;
}

// Helper: Calculate compression ratio
void showCompressionStats(const string& original, const string& encoded) {
    int originalBits = original.length() * 8;  // 8 bits per character (ASCII)
    int encodedBits = encoded.length();         // each '0' or '1' is 1 bit

    cout << "\n===== COMPRESSION STATISTICS =====" << endl;
    cout << "Original size: " << originalBits << " bits (" << original.length() << " characters)" << endl;
    cout << "Encoded size: " << encodedBits << " bits" << endl;
    cout << "Compression ratio: " << (double)encodedBits / originalBits * 100 << "%" << endl;
}



int main() {
    cout << "========== HUFFMAN ENCODING ==========" << endl << endl;

    string text = readFromFile("input.txt");
    if (text.empty()) return 1;

    map<char, int> freq = countFrequency(text);

    Node* root = buildHuffmanTree(freq);

    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    cout << "\nHuffman Codes Generated:" << endl;
    for (auto& p : huffmanCodes) {
        cout << "  '" << p.first << "' -> " << p.second << endl;
    }

    string encodedText = encodeText(text, huffmanCodes);

    writeToFile("output.txt", encodedText, huffmanCodes);

    showCompressionStats(text, encodedText);

    cout << "\n========== DONE ==========" << endl;

    return 0;
}